# UVa 10062 - Tell me the frequencies!

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10062
- **Problem Title:** Tell me the frequencies!
- **Problem Link:** [UVa 10062 Tell me the frequencies!](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1003)
- **Source Code (Fail):** [src/10062-fail.cpp](./src/10062-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10062.cpp](./src/10062.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  多筆測試資料。每筆測資是一行包含各種字元的字串（可能有空格）。
- **What is the expected output?**
  統計字串中每個字元出現的次數。輸出格式為「字元的 ASCII 碼」加上「出現次數」，並依照規定的排序方式印出。不同測資的輸出之間必須「空一行」（最後一筆測資結尾不能有多餘的空白行）。
- **What are the main rules or constraints?**
  1. **第一優先排序：** 出現次數「由小到大」（升冪）。
  2. **第二優先排序：** 如果次數相同，則 ASCII 碼「由大到小」（降冪）。
- **What is the core task you must solve?**
  利用 ASCII 碼作為陣列索引來統計頻率，然後實作一個能同時處理「次數升冪」與「ASCII 降冪」的雙重條件排序，並精準控制輸出換行的格式。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  開一個大小為 300 的陣列 `ascii`，直接把字元轉成 `int` 當作索引，讀到什麼字元就在那個格子 `+1`。統計完後，用一個 `while` 迴圈不斷在陣列裡找出最小值並印出，印完後把那個格子歸零，直到陣列全空為止。
- **What difficulty did you notice at the beginning?**
  自己寫的找最小值邏輯很混亂。而且題目要求次數相同時，ASCII 碼要「由大到小」印，從頭掃描陣列時很容易把順序搞反。

### Final Strategy

- **What method did you finally use?**
  放棄複雜的「每次找最小並歸零」寫法，改用**雙層迴圈暴力掃描**：
  外層迴圈 `freq` 從 1 開始慢慢往上數（代表尋找次數為 1 的、次數為 2 的...，這樣自然就滿足「次數由小到大」）。
  內層迴圈 `i`（代表 ASCII 碼）從 255 **倒著數回 0**（這樣自然滿足「同次數時，ASCII 由大到小」）。
  只要陣列 `ascii[i] == freq`，就直接印出來。
- **Why does this method work?**
  因為字串長度有限，最高頻率也不會太大。這個雙層迴圈完美契合了題目的兩個排序規則，而且程式碼極度簡潔，完全不需要寫複雜的交換 (Swap) 排序演算法。
- **What edge cases did you consider?**
  UVa 最嚴格的 Presentation Error (PE)。題目說「測資之間空一行」，意思是**只有第二筆測資開始，才需要在前面補換行**。我加入了一個 `bool first = true` 的旗標，完美避開了最後一筆測資多印空行的地雷。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Initialize a boolean flag `first = true`.
2. Loop continuously while `getline` reads `str`:
   a. If NOT `first`, print an empty line.
   b. Set `first = false`.
   c. Initialize `ascii[256] = {0}` and `max_freq = 0`.
   d. Loop through each character in `str`:
      i. Increment `ascii[character's ASCII value]`.
      ii. Update `max_freq` if current count is greater.
   e. Loop `freq` from 1 to `max_freq` (Sort by frequency ascending):
      i. Loop `i` from 255 down to 0 (Sort by ASCII descending):
         - If `ascii[i] == freq`, print `i` and `freq`.
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str)) {
        int ascii[300] = { 0 };
        for (int i = 0; i < str.size(); i++) {
            int x = (int)str[i];
            ascii[x]++;
        }
        while (true) {
            int min = 10000;
            int num = 0;
            for (int i = 0; i < 300; i++) {
                // 致命錯誤 1：邏輯運算子寫錯
                if (ascii[i] <= min || ascii[i] != 0) { 
                    min = ascii[i];
                    num = i;
                }
            }
            if (min == 10000)break;
            cout << num << " " << min << endl;
            ascii[num] = 0;

        }
        // 致命錯誤 2：每一筆測資後面都多印一個空行，會導致 PE
        cout << endl; 
   }
}
```

**Why it failed:**

1. **條件判斷筆誤：** `if (ascii[i] <= min || ascii[i] != 0)` 裡的 `||` (OR) 是錯的。這會導致只要 `ascii[i]` 不是 0，條件就成立，`min` 會一直被任意數字覆蓋，完全失去了找最小值的功能。應該要用 `&&`。
2. **換行格式錯誤：** `cout << endl;` 放在迴圈尾端，會導致檔案的最後一行多出一個空行，這在 UVa 會直接收到 Presentation Error (PE)。
3. **同頻率排序未明確處理：** 雖然由小掃到大 `i < 300` 配上 `<= min` 剛好會抓到後面較大的 ASCII 值，但邏輯太過脆弱且不易閱讀。

### Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    bool first = true;
    
    while (getline(cin, str)) {
        // 確保只有在「非第一筆測資」之前才印空行
        if (!first) {
            cout << endl;
        }
        first = false;
        
        int ascii[256] = { 0 };
        int max_freq = 0;
        
        // 統計頻率，順便記錄最高頻率以優化後面的迴圈
        for (int i = 0; i < str.size(); i++) {
            int x = (int)str[i];
            ascii[x]++;
            if (ascii[x] > max_freq) {
                max_freq = ascii[x];
            }
        }
        
        // 頻率由小到大
        for (int freq = 1; freq <= max_freq; freq++) {
            // ASCII 由大到小
            for (int i = 255; i >= 0; i--) {
                if (ascii[i] == freq) {
                    cout << i << " " << freq << endl;
                }
            }
        }
    }
    return 0;
}
```

**Why it works:**

- 揚棄了每次重新尋找最小值的寫法，改用 `1 到 max_freq` 以及 `255 到 0` 的雙層迴圈，讓結構自動滿足題目的兩個排序條件。
- 利用 `first` 變數作為開關，完美達到「兩筆測資之間空一行」的 UVa 經典格式要求。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 每次暴力掃描陣列找最小值並歸零 | 利用計數排序的概念，由低頻率掃描到高頻率 |
| Edge Cases | 未處理同頻率時的 ASCII 大小排序問題 | 內層迴圈倒著跑 (`i--`)，完美解決同頻率降冪問題 |
| Output Handling | 測資結束後空行 (導致 PE) | 測資開始前空行 (利用 flag 避開第一筆) |
| Other | `\|\|` 和 `&&` 混淆導致邏輯崩潰 | 程式碼簡化，避開了複雜的條件判斷 |

### Reflection

- **What mistake did you make?**
  寫 `if` 判斷式的時候把「AND (且)」跟「OR (或)」搞混了。在尋找最小值並排除 0 的時候，必須是「比目前最小值小 **而且 (&&)** 不是 0」，用成 `||` 就會造成毀滅性的 Bug。另外也踩到了 UVa 的空行陷阱。
- **What did you learn from debugging this problem?**
  學到了一種超好用的「免排序的排序法」。有時候不需要真的去寫一個陣列的排序演算法（或是呼叫 `sort`），只要我們預先知道目標資料的範圍（例如頻率從 1 到幾百，ASCII 從 0 到 255），直接用兩層 `for` 迴圈按照規定方向掃描，就能輕鬆照順序印出結果。
- **If you solve a similar problem again, what will you do better?**
  只要在 UVa 看到「測資之間空一行 (Separate the output of two consecutive cases by a blank line)」，大腦就要自動條件反射寫出 `bool first = true;` 的起手式，這樣以後絕對不會再因為 Presentation Error 冤枉重傳。