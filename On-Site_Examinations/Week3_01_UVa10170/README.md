# UVa 10170 - The Hotel with Infinite Rooms

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10170
- **Problem Title:** The Hotel with Infinite Rooms
- **Problem Link:** [UVa 10170 The Hotel with Infinite Rooms](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1111)
- **Source Code (Fail):** [src/10170-fail.cpp](./src/10170-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10170.cpp](./src/10170.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  多筆測資。每筆輸入包含兩個整數 $S$ 和 $D$。$S$ 代表第一組旅行團的人數，$D$ 代表你想要查詢的「第幾天」。
- **What is the expected output?**
  輸出一個整數，代表在第 $D$ 天時，剛好住在那裡的旅行團人數。
- **What are the main rules or constraints?**
  飯店每次只接待一組旅行團。如果這組旅行團有 $S$ 人，他們就會住滿 $S$ 天。他們退房的隔天，會有 $S+1$ 人的旅行團入住，並住滿 $S+1$ 天，人數依序遞增。$D$ 的最大值可以高達 $10^{15}$。
- **What is the core task you must solve?**
  模擬天數的累加：把 $S$、$(S+1)$、$(S+2)$... 一直加起來，直到總天數大於或等於 $D$，然後印出當下的團隊人數。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  用一個迴圈，設一個變數用來記錄經過的總天數 (`count`)，每次迴圈把目前的旅行團人數 (`S`) 加到 `count` 裡面。只要 `count` 還沒達到 `D`，就把人數 `S` 加 1 繼續跑。
- **What difficulty did you notice at the beginning?**
  邏輯很簡單，但是 $D$ 的範圍高達 $10^{15}$。C++ 裡一般的 `int` 大約只能裝到 $2 \times 10^9$，如果不小心用錯資料型態，數字絕對會溢位 (Overflow)，導致程式變成無窮迴圈或輸出負數。

### Final Strategy

- **What method did you finally use?**
  直接使用 `long long int` 宣告所有的變數（包含 $S$, $D$, 以及累加天數的 `count`），然後老老實實地用 `while` 迴圈去累加並模擬天數的推進。
- **Why does this method work?**
  `long long int` 的最大值約為 $9 \times 10^{18}$，完全可以容納題目的 $10^{15}$ 限制。只要資料型態正確，單純的累加模擬法就能順利算出答案。
- **What edge cases did you consider?**
  極端的 $D$ 值，以及當累加後 `count` 剛好等於 $D$ 的邊界情況。我在迴圈內直接判斷 `if (count >= d)` 提早 `break` 確保抓到正確的人數。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Read `s` and `d` until EOF (Ensure variables are `long long int`).
2. Loop for each test case:
   a. Initialize `count = 0`.
   b. Loop while `count < d`:
      i.   Add current group size `s` to `count` (`count += s`).
      ii.  If `count >= d`, we found the target day. Print `s` and BREAK loop.
      iii. Otherwise, increment group size (`s++`) for the next iteration.
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    // 致命錯誤：使用了 int
    int s=0, d=0;
    while (cin >> s >> d) { 
        int count=0;
        while (count < d) {
            count += s;
            if (count >= d) {
                cout << s << endl;
                break;
            }
            s++;
        }
    }
}
```

**Why it failed:**

- **整數溢位 (Integer Overflow)：** C++ 的 `int` 只有 32 bit，最高只能存到 `2,147,483,647`。當題目的 $D$ 給到天文數字（例如 $10^{15}$）時，`d` 和 `count` 都會爆炸變成負數，導致條件判斷錯亂（例如 Runtime Error 或 Time Limit Exceeded）。

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long int s=0, d=0;
    while (cin >> s >> d) { 
        long long int count=0;
        while (count < d) {
            count += s;
            
            if (count >= d) {
                cout << s<<endl;
                break;

            }
            s++;
        }
        
    }
}
```

**Why it works:**

- 全面把變數升級成 `long long int`，完美避開了因為數字過大造成的溢位問題，讓迴圈能正確比較 `count` 與 `d` 的大小。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 迴圈累加天數 | 迴圈累加天數 (相同) |
| Edge Cases | 無法處理 $D > 2 \times 10^9$ 的大測資 | 支援高達 $10^{15}$ 的極大測資 |
| Output Handling | 相同 | 相同 |
| Other | 變數型態為 `int` | 變數型態升級為 `long long int` |

### Reflection

- **What mistake did you make?**
  在初學寫題目的時候，很容易不管三七二十一全部都用 `int` 宣告，導致明明邏輯全對，卻在送出後拿到 WA 或 TLE， debug 半天找不到蟲在哪。
- **What did you learn from debugging this problem?**
  **「看測資範圍」是讀題的第一要務！** 只要題目提到 $10^{10}$ 以上的數字，連想都不用想，變數直接開 `long long` 就對了。
- **If you solve a similar problem again, what will you do better?**
  雖然目前的迴圈模擬法有 AC，但其實這題可以轉化為一元二次方程式的數學公式解：總天數是一個等差數列和。未來遇到時間限制更嚴格的題目，會嘗試直接帶數學公式用 $O(1)$ 或二分搜尋法 $O(\log N)$ 的方式算出 $S$，讓程式跑得更快。