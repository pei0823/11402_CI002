# UVa 673 - Parentheses Balance

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 673
- **Problem Title:** Parentheses Balance
- **Problem Link:** [UVa 673 Parentheses Balance](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614)
- **Source Code (Correct/Accepted):** [src/673.cpp](./src/673.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  第一行是一個整數 `n`，代表測資數量。接下來有 `n` 行字串，每行包含括號 `(` `)` `[` `]`。
- **What is the expected output?**
  若括號完全匹配，輸出 `Yes`；否則輸出 `No`。空字串也視為匹配。
- **What is the core task you must solve?**
  判斷字串中的括號是否符合「後進先出 (LIFO)」的配對規則。

## 3. Thinking Logic and Solution Strategy

### Strategy
- **Stack Usage:** 遇到左括號 `(` 或 `[` 就壓入堆疊 (`push`)；遇到右括號時，檢查堆疊是否為空，以及堆疊頂端 (`top`) 是否為對應的左括號。
- **Final Check:** 處理完所有字元後，堆疊必須是空的 (`empty`)，且過程中沒有發生過任何匹配錯誤。

### Edge Cases
- **Empty String:** 題目規定空字串要輸出 `Yes`。
- **Unbalanced:** 右括號先出現、或是左括號沒對應到、或是括號交錯 (如 `([)]`)。

## 4. Pseudocode

```text
START
1. Read number of test cases N.
2. Consume newline character.
3. Loop N times:
   a. Read line as string `str`.
   b. Initialize stack `s`, boolean `isBalanced = true`.
   c. For each char `c` in `str`:
      i. If `c` is '(' or '[': s.push(c).
      ii. If `c` is ')': If s empty or s.top != '(': isBalanced = false, break. Else s.pop().
      iii. If `c` is ']': If s empty or s.top != '[': isBalanced = false, break. Else s.pop().
   d. If `isBalanced` AND `s.empty()`: print "Yes". Else: print "No".
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string str;
        getline(cin, str);
        stack<char> s;
        bool isBalanced = true;

        for (char c : str) {
            if (c == '(' || c == '[') {
                s.push(c);
            } else if (c == ')') {
                if (s.empty() || s.top() != '(') {
                    isBalanced = false;
                    break;
                }
                s.pop();
            } else if (c == ']') {
                if (s.empty() || s.top() != '[') {
                    isBalanced = false;
                    break;
                }
                s.pop();
            }
        }
        
        if (isBalanced && s.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
```

## 6. Difference and Reflection

| Item | Assessment |
|---|---|
| Logic | 使用 Stack 完美處理 LIFO |
| Efficiency | $O(N)$，空間複雜度 $O(N)$ |
| Edge Cases | 修正了對空字串的判斷 |

- **Mistake:** 原程式碼對於空字串 (`getline` 讀到長度為 0) 的判定與 `boool` 變數的處理較為複雜，直接用 `isBalanced` flag 更清晰。
- **Learned:** 任何括號匹配問題，Stack 都是首選。
- **Future:** 遇到類似問題，確保在處理完字串後，同時檢查「堆疊是否為空」以及「過程中是否曾出錯」這兩個條件。