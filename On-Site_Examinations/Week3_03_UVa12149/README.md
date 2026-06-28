# UVa 12149 - Feynman

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 12149
- **Problem Title:** Feynman
- **Problem Link:** [UVa 12149 Feynman](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3291)
- **Source Code (Fail):** [src/12149-fail.cpp](./src/12149-fail.cpp)
- **Source Code (Correct/Accepted):** [src/12149.cpp](./src/12149.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  多筆測資。每筆輸入包含一個整數 $N$ ($0 < N \le 100$)，代表一個 $N \times N$ 的方格棋盤。當輸入為 `0` 時，代表測資結束。
- **What is the expected output?**
  針對每一個 $N$，輸出在該 $N \times N$ 的棋盤中，總共包含了幾個大小不同的正方形。
- **What are the main rules or constraints?**
  正方形的大小可以是 $1 \times 1$、$2 \times 2$，一直到 $N \times N$。輸入若為 `0` 必須立刻結束程式，不能輸出結果。
- **What is the core task you must solve?**
  找出正方形數量與棋盤邊長 $N$ 之間的數學規律，並利用程式計算出總和。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  一開始先在紙上畫圖觀察：
  - $1 \times 1$ 棋盤：有 1 個正方形。
  - $2 \times 2$ 棋盤：有 4 個 $1 \times 1$ 正方形 + 1 個 $2 \times 2$ 正方形 = 5 個。
  - $3 \times 3$ 棋盤：有 9 個 $1 \times 1$ + 4 個 $2 \times 2$ + 1 個 $3 \times 3$ = 14 個。
- **What difficulty did you notice at the beginning?**
  其實沒有太大的困難，只要把紙上觀察到的規律轉換成數學算式即可。可以明顯看出這是一個平方和的數列：$1^2 + 2^2 + 3^2 + \dots + N^2$。

### Final Strategy

- **What method did you finally use?**
  直接使用一個 `for` 迴圈，從 1 跑到 $N$，每次把 `i * i` 加進總和變數 `count` 裡面。
- **Why does this method work?**
  因為在 $N \times N$ 的棋盤中：
  邊長為 1 的正方形有 $N \times N = N^2$ 個；
  邊長為 2 的正方形有 $(N-1) \times (N-1) = (N-1)^2$ 個；
  ...
  邊長為 $N$ 的正方形有 $1 \times 1 = 1^2$ 個。
  把它們全部加起來就是總數，用迴圈累加剛好完美對應這個公式。
- **What edge cases did you consider?**
  特別處理了 `num == 0` 的情況，使用 `if (num == 0) break;` 確保程式會在讀到 0 的時候直接停止，不會去印出多餘的 0。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Loop continuously while reading `num` from input.
2. If `num == 0`, BREAK the loop and END the program.
3. Initialize `count = 0` (Ensure it resets for every test case).
4. Loop `i` from 1 to `num`:
   - Add `i * i` to `count`.
5. Output `count`.
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main() {
    long long int num = 0;
    while (cin >> num) {
        long long int count = 0;
        for (int i = 0; i <= num; i++) {
            count += i * i;
        }
        cout << count << endl;
    }
}
```

**Why it failed:**

- **忘記處理結束條件：** 題目特別規定當輸入為 `0` 時要結束程式。這段程式碼漏掉了 `if (num == 0) break;`，導致它會把 `0` 當成一組正常的測資去計算，並在最後印出 `0`，這在 UVa 系統上通常會得到 Wrong Answer (WA)。

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long int num = 0;
    while (cin >> num) {
        if (num == 0)break;
        long long int count=0;
        for (int i = 0; i <= num; i++) {
            count += i * i;
        }
        cout << count << endl;
    }
}
```

**Why it works:**

- 完美抓到了數學規律，透過迴圈順利完成平方和的累加。
- 加上了 `if (num == 0) break;` 作為終止條件，符合題意要求。
- 變數使用了 `long long int`，雖然這題 $N \le 100$ 算出來的結果大約是 338350（可以用一般 `int` 裝下），但提早開 `long long int` 是一個很好的安全防護習慣。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 沒有攔截結束訊號 | 精準攔截結束訊號 |
| Edge Cases | 未處理輸入為 0 的要求 | 輸入為 0 時立刻終止程式 |
| Output Handling | 會多印出一行 0 | 完全符合題目的輸出筆數 |
| Other | 容易拿到 WA | 順利取得 AC |

### Reflection

- **What mistake did you make?**
  在寫這類有特定結束條件（例如：遇到 0 結束、遇到 -1 結束）的題目時，有時候會專注於把核心的演算法寫出來，反而忘記加上 `break` 條件。
- **What did you learn from debugging this problem?**
  這題展示了「找規律」在程式解題中的重要性。如果沒有看出平方和的規律，想要用陣列或座標系統去暴力搜尋所有的正方形會極度複雜且浪費時間。數學觀察力能大幅簡化程式碼。
- **If you solve a similar problem again, what will you do better?**
  除了用迴圈慢慢加，這題其實可以直接帶入高中數學學過的**平方和公式**：$\frac{N(N+1)(2N+1)}{6}$。如果之後遇到 $N$ 極大的情況（例如高達 $10^9$），迴圈會 Time Limit Exceeded (TLE)，這時候直接回傳公式解 `N * (N + 1) * (2 * N + 1) / 6`，程式效能就會直接變成完美的 $O(1)$。