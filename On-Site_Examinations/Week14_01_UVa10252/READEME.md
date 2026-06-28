# UVa 10252 - Common Permutation

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10252
- **Problem Title:** Common Permutation
- **Problem Link:** [UVa 10252 Common Permutation](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1193)
- **Source Code (Correct/Accepted):** [src/10252.cpp](./src/10252.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  多筆測試資料，每兩行一組。每筆包含兩個字串。
- **What is the expected output?**
  找出兩個字串中共同包含的字元，並將這些字元依照字母順序輸出。
- **What are the core rules?**
  若某個字母在兩字串中各出現 $N$ 次與 $M$ 次，則輸出該字母 $\min(N, M)$ 次。

## 3. Thinking Logic and Solution Strategy

### Strategy
1. **計數統計：** 分別統計兩個字串中 `a-z` 各字母出現的次數（使用大小為 26 的陣列）。
2. **取交集：** 遍歷 0 到 25 的索引，取出兩者計數的最小值 `min(countA[i], countB[i])`。
3. **按序輸出：** 根據該最小值，將字母重複輸出對應次數。

## 4. Pseudocode

```text
START
1. While reading str1 and str2:
   a. countA[26] = {0}, countB[26] = {0}.
   b. For char c in str1: if isalpha(c), countA[c - 'a']++.
   c. For char c in str2: if isalpha(c), countB[c - 'a']++.
   d. For i from 0 to 25:
      i. times = min(countA[i], countB[i]).
      ii. Print character ('a' + i) repeated 'times' times.
   e. Print newline.
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string str1, str2;
    while (getline(cin, str1) && getline(cin, str2)) {
        int count1[26] = {0}, count2[26] = {0};
        
        for (char c : str1) if (c >= 'a' && c <= 'z') count1[c - 'a']++;
        for (char c : str2) if (c >= 'a' && c <= 'z') count2[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            int common = min(count1[i], count2[i]);
            for (int k = 0; k < common; k++) {
                cout << (char)('a' + i);
            }
        }
        cout << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | $O(N)$ 統計與輸出，非常高效 |
| Efficiency | 空間複雜度僅 $O(1)$ (固定 26 個變數) |
| Correctness | 利用 `min` 函式處理共同出現次數，邏輯嚴謹 |

- **Mistake:** 原程式碼使用雙層迴圈進行比對並修改字串 (`str1[i] = '-1'`)，這不僅會破壞原始資料，且若有多個相同字母，效率會變得極差。
- **Learned:** 處理字母頻率統計問題，建立長度 26 的 `int` 陣列映射是最標準的做法。
- **Future:** 看到這類字元統計與比對問題，第一時間就要想到 `count[26]` 陣列法，絕對不要用雙層迴圈暴力比對。