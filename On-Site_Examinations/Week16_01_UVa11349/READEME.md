# UVa 11349 - Symmetric Matrix

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11349
- **Problem Title:** Symmetric Matrix
- **Problem Link:** [UVa 11349 Symmetric Matrix](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2324)
- **Source Code (Correct/Accepted):** [src/11349.cpp](./src/11349.cpp)

## 2. Problem Statement in My Own Words

- **Input:** $T$ 個測試案例。每組輸入格式為 `N = n`，隨後是一個 $n \times n$ 的矩陣。
- **Output:** 判斷矩陣是否為「對稱矩陣」。
- **Symmetry Condition:**
  1. 所有元素必須大於或等於 0。
  2. 矩陣是對稱的，即 $M[i][j] == M[n-1-i][n-1-j]$ 對於所有 $i, j$ 成立。

## 3. Thinking Logic and Strategy

### Logic: Definition of Symmetry
對於一個大小為 $n \times n$ 的矩陣，其對稱性不需分奇偶數討論。我們只需遍歷整個矩陣，檢查每個點 `(i, j)` 是否與其對稱點 `(n-1-i, n-1-j)` 的值相等。



### Efficiency
- 時間複雜度：$O(N^2)$。
- 空間複雜度：$O(N^2)$。

## 4. Pseudocode

```text
START
1. Read T.
2. For count = 1 to T:
   a. Read "N = n".
   b. Initialize matrix M[n][n].
   c. Set isSymmetric = true.
   d. For i = 0 to n-1, For j = 0 to n-1:
      i. Read value into M[i][j].
      ii. If M[i][j] < 0, isSymmetric = false.
   e. For i = 0 to n-1, For j = 0 to n-1:
      i. If M[i][j] != M[n-1-i][n-1-j], isSymmetric = false.
   f. Print "Test #count: " + (isSymmetric ? "Symmetric." : "Non-symmetric.")
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
    for (int count = 1; count <= t; count++) {
        char dummy1, dummy2;
        int n;
        cin >> dummy1 >> dummy2 >> n;
        
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
                    // 對稱點定義：在 0-based 索引下，點 (i, j) 的對稱點為 (n-1-i, n-1-j)
                    if (mat[i][j] != mat[n - 1 - i][n - 1 - j]) {
                        isSymmetric = false;
                        break;
                    }
                }
                if (!isSymmetric) break;
            }
        }

        cout << "Test #" << count << ": " << (isSymmetric ? "Symmetric." : "Non-symmetric.") << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 修正為全矩陣對稱檢查，邏輯清晰 |
| Efficiency | $O(N^2)$ 遍歷，對於 UVa 時間限制非常充裕 |
| Robustness | 處理了負數檢查與對稱軸比對 |

- **Mistake:** 原程式碼試圖用 `x` 和 `y` 指標縮小範圍掃描，這會導致對於矩陣邊角元素的比對遺漏或是索引越界。
- **Learned:** 任何矩陣旋轉或對稱問題，直接使用 $N-1-index$ 的轉換公式是最保險且不容易出錯的做法。
- **Future:** 遇到矩陣對稱，務必第一時間寫出 `M[i][j] == M[n-1-i][n-1-j]`，這能解決 99% 的此類問題。