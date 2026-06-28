# UVa 10474 - Where is the Marble?

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10474
- **Problem Title:** Where is the Marble?
- **Problem Link:** [UVa 10474 Where is the Marble?](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415)
- **Source Code (Fail):** [src/10474-fail.cpp](./src/10474-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10474.cpp](./src/10474.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  多組測試資料。每組資料開頭是兩個整數 $N$（大理石的數量，最多 10000）與 $Q$（問題的數量）。接下來有 $N$ 行輸入大理石上的數字，接著有 $Q$ 行輸入你想尋找的數字。當 $N=0$ 且 $Q=0$ 時結束程式。
- **What is the expected output?**
  先印出目前是第幾組測資（例如 `CASE# 1:`）。對於每一個詢問，如果找到了，輸出它在**排序後**的第幾個位置（從 1 開始算）；如果找不到，輸出 `not found`。
- **What are the main rules or constraints?**
  大理石的數字一開始是亂序的，必須先「由小到大」排序。
  如果同一個數字有多顆大理石，必須回傳它「第一次」出現的位置。
- **What is the core task you must solve?**
  對陣列進行有效率的排序。在面對大量的詢問時，使用二分搜尋法快速找到目標，並正確處理「有重複數字」的退位尋找邏輯。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  讀取大理石數字時順便做插入排序 (Insertion Sort)。針對每次查詢，利用二分搜尋法 (Binary Search) 每次切一半來找數字，把尋找時間從 $O(N)$ 縮短到 $O(\log N)$。
- **What difficulty did you notice at the beginning?**
  二分搜尋法的邊界條件非常容易寫到無窮迴圈（例如 `min = max` 或只差 1 的時候）。而且標準的二分搜尋法只要「一找到」就會停下來，但陣列裡可能有連續好幾個一樣的數字，它停下來的地方不一定是「第一個」。

### Final Strategy

- **What method did you finally use?**
  我手刻了完整的二分搜尋流程，並加上了很多邊界防護 (`if (max == min + 1)` 提早跳出)。最關鍵的一步是：當二分搜尋找到目標的索引值 `tmp` 後，我加了一個 `while` 迴圈往回推：`while (num[tmp] == num[tmp - 1]) tmp--;`，強迫它走到連續相同數字的最開頭。
- **Why does this method work?**
  先用二分搜尋法快速鎖定目標所在的「區域」，再用線性倒退的方式精準打擊到「第一個出現」的正確位置。這完美解決了題目中重複數字的陷阱。
- **What edge cases did you consider?**
  處理了要找的數字剛好在陣列最頭 `num[min]` 或最尾巴 `num[max]`，或是超過最大值 `numm > num[max]` 的極端情況，避免二分搜尋在這些地方當機。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Initialize `count = 1` for test cases.
2. Loop continuously:
   a. Read `n` and `q`. If both are 0, BREAK.
   b. Read `n` numbers and sort them simultaneously using Insertion Sort.
   c. Print "CASE# `count`:" and increment `count`.
   d. Loop `q` times for queries:
      i.   Read query number `numm`.
      ii.  Set `min = 1`, `max = n`, `tmp = (min + max) / 2`.
      iii. Run Custom Binary Search to find `numm`.
           - If found, stop and keep index in `tmp`.
           - If not found or search exhausted, set `tmp = 0`.
      iv.  If `tmp != 0`, loop backwards (`tmp--`) while the previous number is the same.
      v.   If `tmp == 0`, print "numm not found".
      vi.  Else, print "numm found at tmp".
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
using namespace std;

// 模擬一般初學者最常犯的錯：忽略重複數字
int main() {
    // ... 前面的排序省略 ...
    int min = 1, max = n;
    int ans = 0;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (num[mid] == numm) {
            ans = mid;
            break; // 致命錯誤：一找到就停，沒有往回找「第一個」
        } else if (num[mid] < numm) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    
    if (ans == 0) cout << numm << " not found" << endl;
    else cout << numm << " found at " << ans << endl;
}
```

**Why it failed:**

- **沒有找「第一個」：** 如果陣列是 `[2, 4, 4, 4, 5]`，你想找 `4`。標準二分搜尋可能會直接命中正中間那個索引 3 的 `4`，然後就輸出解答。但題目要求的是索引 2 的那個 `4`。

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n, q;
    int count = 1;
    while (true) {
        cin >> n >> q;
        if (n == 0 && q==0)break;
        int num[10000];
        cin >> num[1];
        for (int i = 2; i <= n; i++) {
            cin >> num[i];
            int tmp = i;
            while (num[tmp] < num[tmp-1]) {
                int t = num[tmp];
                num[tmp] = num[tmp-1];
                num[tmp-1] = t;
                tmp--;
                if (tmp == 1)break;
            }
        }
        cout << "CASE# " << count << ":" << endl; count++;
        for (int i = 1; i <= q; i++) {

            int numm;
            cin >> numm;

            int min = 1;
            int max = n;
            int tmp = (min + max) / 2;
            int cou = 0;
            if (numm == num[max] ) {
                tmp = max;
            }
            else if (numm == num[min]) {
                tmp = min;
            }
            else if (numm > num[max]) {
                tmp = 0;
            }
            else {
                while (numm != num[tmp]) {
                    if (numm < num[tmp]) {
                        max = tmp;
                    }
                    else if (numm > num[tmp]) {
                        min = tmp;
                    }
                    if (min == max) { tmp = 0; break; }
                    tmp = (min + max) / 2;
                    cou++;
                    if (max==min+1) {
                        tmp = 0; break;
                    }

                }
            }
            // 完美解決重複數字的退位邏輯
            if (tmp != 0){
                while (num[tmp] == num[tmp - 1])tmp--;
            }
            
            if (tmp == 0) {
                cout << numm << " not found"<<endl;
            }
            else {
                cout << numm << " found at " << tmp << endl;
            }
        }
    }
}
```

**Why it works:**

- 二分搜尋的邏輯成功縮小了範圍，加上最後面的 `while (num[tmp] == num[tmp - 1]) tmp--;`，完美修正了因為重複數字而造成的索引誤差。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 找到目標立刻輸出 | 找到目標後，向左掃描直到沒有相同數字為止 |
| Edge Cases | 找錯起始位置 | 精準打擊首個出現的位置 |
| Output Handling | 相同 | 相同 |
| Other | 標準但有破綻的二分搜尋 | 具備防呆機制的客製化二分搜尋 |

### Reflection

- **What mistake did you make?**
  初學二分搜尋法 (Binary Search) 時，很容易被區間 `min` 和 `max` 的更新條件搞混（到底要不要加 1 或減 1），導致寫出無窮迴圈。因此在 `while` 裡面手動塞了很多 `if (min == max)` 或是 `if (max == min + 1)` 這種跳出條件來防呆。
- **What did you learn from debugging this problem?**
  學到了如何處理「重複資料」的搜尋。只要陣列有排序過，相同的資料必然會相鄰在一起，找到一個之後再往旁邊拓展，是非常實用的技巧。
- **If you solve a similar problem again, what will you do better?**
  其實 C++ 內建的 `<algorithm>` 函式庫可以把這幾十行的程式碼縮減到 **3行**！
  1. 排序可以使用 `sort(num + 1, num + n + 1);`，它採用 $O(N \log N)$ 的超快排序，比目前的插入排序 $O(N^2)$ 快非常多。
  2. 尋找「大於等於目標的第一個位置」，C++ 有內建一個超強函式叫做 **`lower_bound()`**。未來解題時直接呼叫 `lower_bound`，不但不需要自己刻二分搜尋，而且它天生就會回傳「第一個」出現的指標，絕對不會有無窮迴圈的 Bug！