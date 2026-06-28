# UVa 11349 - Symmetric Matrix

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11349
- **Problem Title:** Symmetric Matrix
- **Problem Link:** [UVa 11349 Symmetric Matrix](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2324)
- **Source Code (Correct/Accepted):** [src/11349.cpp](./src/11349.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  包含多組測資。每組給定矩陣大小 $N \times N$ 以及矩陣內容。
- **What is the expected output?**
  判斷是否為「對稱矩陣」。條件為：
  1. 所有元素必須非負 ($M[i][j] \ge 0$)。
  2. 對稱性：$M[i][j] = M[N-1-i][N-1-j]$ (即矩陣繞中心旋轉 180 度後與原矩陣相同)。

## 3. Thinking Logic and Solution Strategy

### Strategy
不要試圖找對角線或旋轉中心，直接利用對稱定義：
對於一個 $N \times N$ 的矩陣，只要檢查所有的 $M[i][j]$ 是否等於 $M[N-1-i][N-1-j]$ 即可。

### Visualizing Symmetry


## 4. Pseudocode

```text
START
1. Read number of test cases.
2. For each test case:
   a. Read N.
   b. Read Matrix M[N][N].
   c. If any M[i][j] < 0, isSymmetric = false.
   d. For i from 0 to N-1, For j from 0 to N-1:
      - If M[i][j] != M[N-1-i][N-1-j], isSymmetric = false.
   e. Print "Test #x: Symmetric." or "Non-symmetric.".
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        char dummy1, dummy2;
        int n;
        cin >> dummy1 >> dummy2 >> n; // 跳過格式 "N = n"
        
        vector<vector<long long>> mat(n, vector<long long>(n));
        bool isSymmetric = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
                if (mat[i][j] < 0) isSymmetric = false;
            }
        }

        if (isSymmetric) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != mat[n - 1 - i][n - 1 - j]) {
                        isSymmetric = false;
                        break;
                    }
                }
                if (!isSymmetric) break;
            }
        }

        cout << "Test #" << k << ": " << (isSymmetric ? "Symmetric." : "Non-symmetric.") << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 簡潔的 $O(N^2)$ 對稱檢查 |
| Efficiency | 使用 `long long` 避免數值過大溢位 |
| Formatting | 修正了 `if (is = 0)` 的邏輯錯誤 |

- **Mistake:** 原程式碼中 `if (is = 0)` 是指派運算，永遠為假；且矩陣對稱性的判斷過於複雜。
- **Learned:** 矩陣對稱性檢測最簡單的定義就是「旋轉 180 度後是否相等」，這等同於比較 `M[i][j]` 與 `M[N-1-i][N-1-j]`。
- **Future:** 遇到矩陣對稱問題，直接比較索引倒轉後的數值即可，無需計算座標平移。