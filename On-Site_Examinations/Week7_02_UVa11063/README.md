# UVa 11063 - B2-Sequence

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11063
- **Problem Title:** B2-Sequence
- **Problem Link:** [UVa 11063 B2-Sequence](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2004)
- **Source Code (Fail):** [src/11063-fail.cpp](./src/11063-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11063.cpp](./src/11063.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  多筆測資，每筆給定一個整數 $N$ 和 $N$ 個數字組成的序列。
- **What is the expected output?**
  判斷該序列是否為 B2-Sequence，並按格式輸出 `Case #x: It is [not] a B2-Sequence.`。
- **What are the main rules or constraints?**
  1. 序列必須是遞增的 ($1 \le b_1 < b_2 < \dots < b_n$)。
  2. 所有的 $b_i$ 必須大於 0。
  3. 任意兩個數字的和（包含自己加自己 $b_i + b_j$，且 $i \le j$）必須是唯一的，不能重複。
- **What is the core task you must solve?**
  檢查序列的遞增性與正整數特性，並建立一個檢查機制來確認所有兩兩之和 ($b_i + b_j$) 沒有重複出現過。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  建立一個陣列存放所有的數字，然後用雙層迴圈暴力窮舉出所有的 $b_i + b_j$，把它們存進另一個陣列，最後檢查是否有重複。
- **What difficulty did you notice at the beginning?**
  檢查數字是否重複，如果用暴力法兩兩比對，時間複雜度會太高。且你的原程式碼在檢查和的過程中有一些邊界判斷的錯誤（例如 `sumcount` 的維護以及陣列交換邏輯稍顯複雜）。

### Final Strategy

- **What method did you finally use?**
  改用一個「標記陣列 (Boolean Array)」來檢查重複。因為題目的數字範圍與 $N$ 的規模允許我們直接用陣列存取。建立一個 `bool used[20001]` 或 `seen[20001]`，每算出一個新的和，就檢查該位置是否已經被標記過。如果被標記過，立刻判定為非 B2-Sequence。
- **Why does this method work?**
  這就是「雜湊 (Hashing)」的簡易版。當算出和 $S$ 時，直接檢查 `seen[S]` 是 `true` 還是 `false`，時間複雜度只有 $O(1)$，非常快速且乾淨。

### Edge Cases
- 序列中的數字必須嚴格遞增 (`num[i] <= num[i-1]`)。
- 數字必須大於 0。

## 4. Pseudocode

```text
START
1. While reading N:
   a. Read sequence into `num`.
   b. Check if `num[i] < 1` or `num[i] <= num[i-1]`: set `isB2 = false`.
   c. If `isB2` is true:
      i. Iterate `i` from 1 to `n`, `j` from `i` to `n`:
         - Sum `s = num[i] + num[j]`.
         - If `seen[s]` is true: `isB2 = false`, break.
         - Else: `seen[s] = true`.
   d. Print result formatted as Case #count.
END
```

## 5. Fail Code vs Correct Code

### Fail Code (Logic Flaw)
你的原程式碼試圖用「插入排序」的概念邊算和邊排序，導致邏輯非常混亂，且對於 B2 的唯一性檢查判斷式容易出現誤差，特別是 `sum[tmp] == sum[tmp-1]` 的邏輯並不夠完整。

### Correct Code
```cpp
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int n, count = 1;
    while (cin >> n) {
        vector<int> num(n);
        bool isB2 = true;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            if (num[i] < 1 || (i > 0 && num[i] <= num[i - 1])) isB2 = false;
        }

        if (isB2) {
            bool seen[20001] = {false};
            for (int i = 0; i < n && isB2; i++) {
                for (int j = i; j < n; j++) {
                    int s = num[i] + num[j];
                    if (seen[s]) { isB2 = false; break; }
                    seen[s] = true;
                }
            }
        }

        cout << "Case #" << count++ << ": It is " 
             << (isB2 ? "" : "not ") << "a B2-Sequence." << endl << endl;
    }
    return 0;
}
```

**Why it works:**
使用 `vector` 處理動態輸入，並透過 `bool seen[20001]` 來快速檢測重複的和，這種方式保證了時間效率且邏輯清晰。注意 UVa 題目要求每組測資輸出後要多一個換行。

## 6. Difference and Reflection

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 邊計算邊排序，容易錯失判斷 | 預先驗證遞增，後利用標記法驗證和的唯一性 |
| Efficiency | 插入排序法 $O(N^2)$ 且邏輯複雜 | 使用布林陣列標記，$O(N^2)$ 但空間與時間極優 |
| Output | 結尾格式可能不穩 | 符合題目要求的雙換行 |

### Reflection
- **Mistake:** 原本想在讀入時就排好序並檢查，但這會讓邏輯變成 $O(N^3)$ 以上的複雜度，且極難除錯。
- **Learned:** 對於「唯一性檢查」的問題，使用 `bool` 陣列（或雜湊表）紀錄是否出現過，是解決這類問題的金科玉律。