# UVa 10783 - Odd Sum

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10783
- **Problem Title:** Odd Sum
- **Problem Link:** [UVa 10783 Odd Sum](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1724)
- **Source Code (Fail):** [src/10783-fail.cpp](./src/10783-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10783.cpp](./src/10783.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  第一行給定一個整數 T，代表測試資料的組數。接下來有 T 組資料，每組包含兩個整數 a 和 b (0 <= a <= b <= 100)。
- **What is the expected output?**
  算出 a 到 b 之間（包含 a 與 b 本身）所有「奇數」的總和。必須按照題目要求的格式輸出，例如：`Case 1: 總和`。
- **What are the main rules or constraints?**
  a 絕對不會大於 b。數值範圍很小（最大 100），所以總和也不會太大，不用擔心資料型態溢位的問題。
- **What is the core task you must solve?**
  找出指定區間內的奇數並全部加總，同時要精準處理輸出的文字格式，不能只單純印出數字。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  最直覺的想法是寫一個 `for` 迴圈從 a 跑到 b，在迴圈裡面用 `if (i % 2 != 0)` 來判斷目前的數字是不是奇數，是的話就把數字加進總和裡面。
- **What difficulty did you notice at the beginning?**
  邏輯本身很簡單，但最容易踩到的坑是忘記題目要求的 `Case X: ` 輸出格式，導致拿到 Wrong Answer。

### Final Strategy

- **What method did you finally use?**
  你的寫法更進階一點：先檢查起點 `fir` 是不是偶數，如果是偶數就 `+1` 強制讓它變成奇數，並把第一個奇數先加進總和。接下來只要利用迴圈每次 `+2` 往上跳，就能保證接下來碰到的每一個數字絕對都是奇數，直接加總即可。
- **Why does this method work?**
  因為奇數加上 2 必然還是奇數。這個作法省去了迴圈裡面每次都要做 `% 2` 的運算判斷，執行上更直接。
- **What edge cases did you consider?**
  你考慮了起點和終點一樣的情況 (`if (fir == sec)`)。不過你的實作在這裡其實隱藏了一個小 Bug（見下方 Reflection 說明）。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Read test cases count into `num`.
2. Loop `runtime` from 1 to `num`:
   a. Read start `fir` and end `sec`.
   b. Initialize sum variable (also named `num` in the code) to 0.
   c. If `fir == sec`:
      - Print output and continue to next case. (Note: this has a logic flaw)
   d. If `fir` is even, make it odd (`fir++`).
   e. Add `fir` to sum.
   f. Loop up to 100 times:
      - Add 2 to `fir`.
      - If `fir > sec`, break the loop.
      - Add `fir` to sum.
      - If `fir == sec`, break the loop.
   g. Print "Case " + runtime + ": " + sum.
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    for (int runtime = 1; runtime <= num; runtime++) {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int i = a; i <= b; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        // Fail: 忘記加上 "Case X: " 的格式
        cout << sum << endl;
    }
    return 0;
}
```

**Why it failed:**

- 完全忘記題目要求的 `Case 1: ` 輸出格式。這是在 UVa 平台上最常見的初學者錯誤，即便算出來的數字全對，系統還是會判定為 WA。

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int runtime = 1; runtime <= num; runtime++)
    {
        int fir, sec;
        cin >> fir >> sec;
        int num = 0;
        if (fir == sec) {
            cout << "Case " << runtime << ": " << num << endl;
            continue;
        }
         
        if (fir % 2 == 0)fir++;
        num += fir;

        for (int i = 0; i < 100; i++) {
            fir += 2;
            if (fir > sec) break;
            num += fir;
            if (fir == sec)break;
            
            
            //cout << fir << endl;
        }
        cout << "Case " << runtime << ": " << num << endl;
    }
}
```

**Why it works:**

- 正確處理了 `Case X: ` 的文字輸出。
- 透過直接對起點修正為奇數並以 `+2` 的步進方式，跳過所有偶數的檢查，邏輯具有巧思。（註：在 UVa 的寬鬆測資下順利 AC）

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 逐一檢查所有數字 | 直接找到第一個奇數後，每次加 2 進行跳躍加總 |
| Edge Cases | 未特別處理起點終點相同 | 嘗試處理 `fir == sec`，但略有瑕疵 |
| Output Handling | 只有印出總和數字 | 精準包含 `Case X: ` 的字串格式 |
| Other | 迴圈次數看區間大小 | 強制迴圈跑 100 次以內，並透過 `break` 提早結束 |

### Reflection

- **What mistake did you make?**
  初學解題時最容易被題目繁瑣的輸出格式騙到，這題的精髓不僅僅是求總和，還有細心的格式控制。另外，雖然這份程式碼 AC 了，但其實藏了一個邏輯小 Bug：當輸入剛好是相同的「奇數」（例如 3 和 3）時，前方的 `if (fir == sec)` 會直接觸發 `continue` 並輸出 0，但正確答案應該是 3。能通過是因為 UVa 的測資剛好沒有去檢查這個特例。
- **What did you learn from debugging this problem?**
  學到可以利用數學的規律性（奇數 + 2 還是奇數）來優化迴圈，這比每個數字慢慢拿去做除法取餘數 (`% 2`) 要聰明且快速許多。
- **If you solve a similar problem again, what will you do better?**
  1. **修正 Bug：** 其實不需要在最前面特別寫 `if (fir == sec)` 去攔截起點跟終點相同的狀況。只要把這段拔掉，讓底下的邏輯正常跑，輸入是 3 和 3 時，它就會順利輸出 3，這能讓程式碼更精簡也更無懈可擊。
  2. **避免變數遮蔽 (Shadowing)：** 程式碼中外層用 `num` 代表「測資總數」，內層又宣告了一次 `int num = 0;` 來代表「奇數總和」。雖然 C++ 允許這麼做（內層的會暫時遮住外層的），但在稍具規模的專案中很容易引發嚴重 Bug，下次會記得把總和改名為 `sum`。