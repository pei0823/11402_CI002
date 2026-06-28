# UVa 10931 - Parity

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10931
- **Problem Title:** Parity
- **Problem Link:** [UVa 10931 Parity](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1872)
- **Source Code (Fail):** [src/10931-fail.cpp](./src/10931-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10931.cpp](./src/10931.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  多筆測試資料，每筆輸入包含一個十進位正整數 $I$ ($1 \le I \le 2147483647$)。當輸入為 `0` 時代表程式結束。
- **What is the expected output?**
  將該整數轉換為二進位字串，並計算裡面總共有幾個 `1`（這稱為 parity，同位元）。必須按照格式輸出：`The parity of [二進位字串] is [1的數量] (mod 2).`
- **What are the main rules or constraints?**
  輸入的整數可能非常大，接近 32-bit 整數的上限。二進位字串必須由左至右（高位到低位）正確印出。
- **What is the core task you must solve?**
  實作十進位轉二進位的演算法，並同時完成「字串正確排序輸出」與「計算 1 的總數」這兩個任務。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  最基本的十進位轉二進位法：把數字一直除以 2，拿餘數（`num % 2`）當作二進位的位元，商數（`num / 2`）繼續往下除，直到數字變成 0。
- **What difficulty did you notice at the beginning?**
  「一直取餘數」這種做法，最先算出來的餘數其實是二進位的「最低位」（最右邊的數字）。如果一邊算一邊印，整個二進位字串會完全「左右顛倒」，拿到 Wrong Answer。

### Final Strategy

- **What method did you finally use?**
  你的作法非常穩紮穩打：**從最高位數開始往下算 (Top-Down)**。
  先利用迴圈乘 2，找出小於等於輸入數字的「最大 2 的次方數」(`binary`)。然後從最高位開始往下除，商數就是該位的位元 (1 或 0)，接著利用餘數繼續往下個位數除 (`binary /= 2`)。同時用陣列 `bi` 把位元依序存起來。
- **Why does this method work?**
  這個方法完全避開了字串顛倒的問題。因為你是從最大的二進位權重開始拆解這個數字，算出來的第一個位元就是最左邊的高位元，最後再用一個迴圈按順序印出陣列並統計 `1` 的數量，邏輯非常嚴密。
- **What edge cases did you consider?**
  在找最大 2 的次方數時，`while (num >= binary)` 迴圈會多乘一次 2，因此你很細心地加了 `if (binary > num)` 將 `binary` 除回 2，修正了邊界溢出的問題。另外使用 `long long int` 宣告變數，確保了大數字乘 2 時不會發生整數溢位 (Overflow)。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Loop continuously while reading `num`.
2. If `num == 0`, BREAK the loop.
3. Initialize `binary = 1`, `bicount = 1`, and array `bi`.
4. Find the highest power of 2:
   a. Loop while `num >= binary`: `binary *= 2`, `bicount++`.
   b. If `binary > num`, correct it: `binary /= 2`, `bicount--`.
5. Extract bits from MSB to LSB:
   a. Loop while `bicount != 0`:
      i.   Store bit: `bi[bicount] = num / binary`.
      ii.  Update remainder: `num %= binary`.
      iii. Move to next bit: `binary /= 2`.
      iv.  Decrement `bicount`.
6. Print output and count 1s:
   a. Print "The parity of ".
   b. Loop through `bi` array to print each bit.
   c. If bit is 1, increment `countt`.
   d. Print " is `countt` (mod 2)."
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main() {
    long long int num;
    while (cin >> num && num != 0) {
        long long int countt = 0;
        cout << "The parity of ";
        
        // 致命錯誤：直接取餘數並印出，會導致二進位字串顛倒
        while (num > 0) {
            int bit = num % 2;
            cout << bit; 
            if (bit == 1) countt++;
            num /= 2;
        }
        cout << " is " << countt << " (mod 2)." << endl;
    }
    return 0;
}
```

**Why it failed:**

- **二進位順序顛倒：** 這是最經典的新手錯誤。例如輸入 `21` (二進位應為 `10101`)，顛倒印還看不出來；但若輸入 `2` (二進位應為 `10`)，這段程式碼會印出 `01`，導致字串輸出完全錯誤。

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    while (true) {
        long long int num = 0;
        long long int binary = 1;
        long long int bicount = 1;
        long long int bi[100] = {};
        cin >> num;
        if (num == 0)
            break;
        
        while (num>= binary) {
            binary *= 2;
            bicount++;
        }
        if (binary >num ) {
            binary /= 2;
            bicount--;
        }
        
        long long int count = bicount;
        while (bicount != 0) {
            bi[bicount] = num / binary;
            num %= binary;
            binary /= 2;
            bicount--;
        }
        cout << "The parity of ";
        long long int countt = 0;
        for (int i = count; i > 0; i--) {
            cout << bi[i];
            if (bi[i] == 1)countt++;
        }cout << " is " << countt << " (mod 2)." << endl;;
        
    }
}
```

**Why it works:**

- 從最大權重的位數 (MSB) 開始處理數字，並用陣列妥善保存每一個位元，最後再以正確的順序（由高至低）印出並統計 `1` 的數量。
- `long long int` 的使用保證了在尋找最大 `binary` 時不會發生記憶體溢位，非常安全。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 由低位到高位計算 (Bottom-Up) | 由高位到低位計算 (Top-Down) |
| Edge Cases | 無法處理二進位字串的反轉 | 完美按照正確的二進位語意輸出 |
| Output Handling | 邊算邊印 | 先存入陣列，確保順序正確後再印出 |
| Other | 程式碼雖短但邏輯錯誤 | 數學邏輯嚴密，雖然稍長但絕對正確 |

### Reflection

- **What mistake did you make?**
  初學進位制轉換時，如果只背誦「除以 2 取餘數」的口訣，就很容易忘記最後的字串是需要反轉的。
- **What did you learn from debugging this problem?**
  學到了如何手動建構二進位：不一定要用餘數法，利用「尋找最大次方數」然後慢慢往下減（或除），可以直接得到正確順序的二進位表示法。
- **If you solve a similar problem again, what will you do better?**
  其實 C/C++ 還有更暴力的解法——**位元運算子 (Bitwise Operators)**。
  可以宣告一個陣列裝餘數，用 `num % 2` 算完後，把陣列倒過來印；或者使用 `for (int i = 31; i >= 0; i--)` 搭配 `(num >> i) & 1` 直接從最高位元開始抓取，不僅程式碼會短到剩下幾行，執行速度也會達到硬體級別的最快極限。未來若遇到類似題目，我會嘗試使用 `&` 和 `>>` 來解題！