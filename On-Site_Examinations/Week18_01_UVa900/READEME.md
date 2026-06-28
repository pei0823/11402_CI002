# UVa 900 - Brick Wall Patterns

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 900
- **Problem Title:** Brick Wall Patterns
- **Problem Link:** [UVa 900 Brick Wall Patterns](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=841)
- **Source Code (Correct/Accepted):** [src/900.cpp](./src/900.cpp)

## 2. Problem Statement in My Own Words

- **Input:** 多組測資，每組輸入一個寬度 $N$（$1 \le N \le 50$）。當 $N=0$ 時結束。
- **Output:** 計算用 $2 \times 1$ 的磚塊填滿 $2 \times N$ 牆面的方法數。
- **Rules:** 磚塊可以垂直放 ($1 \times 2$) 或水平放（兩個 $2 \times 1$ 疊在一起佔用 $2 \times 2$ 的空間）。

## 3. Thinking Logic and Strategy

### Logic: Dynamic Programming
對於寬度為 $N$ 的牆，最後一塊磚塊的擺法只有兩種可能：
1. **最後是一塊垂直磚**：剩下的寬度為 $N-1$，方法數為 $f(N-1)$。
2. **最後是兩塊水平磚**：剩下的寬度為 $N-2$，方法數為 $f(N-2)$。
因此，遞迴式為 $f(N) = f(N-1) + f(N-2)$，這正是費氏數列。



## 4. Pseudocode

```text
START
1. Create array `arr[51]`.
2. Initialize arr[1] = 1, arr[2] = 2.
3. For i from 3 to 50:
   - arr[i] = arr[i-1] + arr[i-2].
4. While reading N and N != 0:
   - Print arr[N].
END
```

## 5. Correct Code

```cpp
#include <iostream>
using namespace std;

int main() {
    // 預先計算到 50，避免重複計算
    long long int arr[51];
    arr[0] = 1; // 寬度為0時定義為1種（數學慣例）
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= 50; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    int n;
    while (cin >> n && n != 0) {
        cout << arr[n] << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 費氏數列 (DP)，時間 $O(N)$，空間 $O(N)$ |
| Efficiency | 使用陣列預存，查詢速度極快 |
| Correctness | 題目 $N \le 50$，`long long` 足以存放結果 |

- **Mistake:** 原程式碼中 `arr[1]=1, arr[2]=2`，這對 $N \ge 1$ 的輸入沒問題。如果題目輸入包含 $0$ 可能需要微調。
- **Learned:** 任何涉及「組合路徑」且「可以拆解為子問題」的題目，先列出前幾項找規律。
- **Future:** 遇到類似磚塊鋪設、樓梯攀爬的問題，優先檢查是否為費氏數列變形。