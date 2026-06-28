# UVa 1121 - Subsequence

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 1121
- **Problem Title:** Subsequence
- **Problem Link:** [UVa 1121 Subsequence](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3562)
- **Source Code (Fail):** [src/1121-fail.cpp](./src/11121-fail.cpp)
- **Source Code (Correct/Accepted):** [src/1121.cpp](./src/1121.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  多筆測資，每筆包含整數 $N$ 和 $S$。接下來有 $N$ 個正整數組成的序列。
- **What is the expected output?**
  找出序列中「最短的連續子序列」，使得該子序列的總和 $\ge S$。輸出該子序列的長度；若找不到，輸出 0。
- **What are the main rules or constraints?**
  序列長度可達 $100,000$，且數字均為正整數。
- **What is the core task you must solve?**
  在 $O(N)$ 的時間內，動態調整子序列的「起點」與「終點」，尋找滿足條件的最小區間。

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts
- **First Idea:** 使用雙層迴圈 (Brute Force)，窮舉所有可能的起點與終點，檢查總和是否 $\ge S$。
- **Difficulty:** $O(N^2)$ 在 $N=100,000$ 的情況下需要 $10^{10}$ 次運算，遠超出一秒的限制，必然 TLE。

### Final Strategy (Sliding Window)
- **Method:** 滑動視窗 (Two Pointers)。
- **Why it works:** 因為序列全為正數，當區間總和不足 $S$ 時，我們擴大終點 (`right`)；當總和 $\ge S$ 時，為了尋找更短的序列，我們縮小起點 (`left`)。兩個指標皆只會從頭走到尾，總共跑 $O(N)$。

## 4. Pseudocode

```text
START
1. While reading N and S:
   a. Read sequence `num`.
   b. Initialize left=1, currentSum=0, minLen = infinity.
   c. For right = 1 to N:
      i.   currentSum += num[right]
      ii.  While currentSum >= S:
           - minLen = min(minLen, right - left + 1)
           - currentSum -= num[left]
           - left++
   d. Output (minLen == infinity ? 0 : minLen)
END
```

## 5. Fail Code vs Correct Code

### Fail Code (Brute Force)
```cpp
// 雙層迴圈，遇到 N=100,000 直接 TLE
for (int i = 0; i < ns; i++) {
    for (int j = i; j < ns; j++) {
        // ... 計算總和並更新長度 ...
    }
}
```

### Correct Code (Sliding Window)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int ns;
    long long s;
    while (cin >> ns >> s) {
        vector<int> num(ns);
        for(int i = 0; i < ns; i++) cin >> num[i];

        int left = 0, minLen = ns + 1;
        long long currentSum = 0;
        
        for (int right = 0; right < ns; right++) {
            currentSum += num[right];
            while (currentSum >= s) {
                minLen = min(minLen, right - left + 1);
                currentSum -= num[left++];
            }
        }
        cout << (minLen > ns ? 0 : minLen) << endl;
    }
    return 0;
}
```

## 6. Difference and Reflection

| Item | Fail Code | Correct Code |
|---|---|---|
| Complexity | $O(N^2)$ (TLE) | $O(N)$ (Accepted) |
| Logic | 暴力枚舉所有區間 | 維護一個「滿足條件的視窗」 |
| Efficiency | 極慢 | 極快 |

### Reflection
- **Mistake:** 當數據量高達 $10^5$ 時，應當反射性地排除雙層迴圈的寫法。
- **Learned:** Sliding Window 是處理「連續區間」類題目最核心的優化手段。
- **Future:** 遇到「連續子序列」且「總和」問題，優先考慮 Two Pointers 或滑動視窗。