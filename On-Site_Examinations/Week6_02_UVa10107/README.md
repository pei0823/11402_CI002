# UVa 10107 - What is the Median?

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10107
- **Problem Title:** What is the Median?
- **Problem Link:** [UVa 10107 What is the Median?](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1048)
- **Source Code (Fail):** [src/10107-fail.cpp](./src/10107-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10107.cpp](./src/10107.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  多筆測試資料，每筆輸入是一個整數 $X$（最多 10,000 個數字）。這些數字會一個一個依序進來。
- **What is the expected output?**
  每讀入一個新數字，就必須輸出「到目前為止」所有已讀入數字的**中位數 (Median)**。
- **What are the main rules or constraints?**
  中位數的定義：將目前所有的數字由小到大排序。如果數字總數是奇數，中位數就是最中間的那個數字；如果是偶數，中位數則是中間兩個數字的平均值（題目要求取整數即可，可以直接用整數除法 `/2`）。
- **What is the core task you must solve?**
  維護一個可以隨時保持排序狀態的陣列，並在每次新增數字後，精準計算出當下的中位數並印出。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  最單純的想法是把數字全部存進陣列裡，然後每讀一個數字，就把整個陣列重新排序 (Sort) 一次，接著找中間的索引值印出來。
- **What difficulty did you notice at the beginning?**
  如果每次都重新排序整個陣列，當數字數量達到 10,000 個的時候，執行時間會變得很長。而且如果在取中位數時，沒有區分奇數和偶數的情況，或是陣列索引算錯，很容易會拿到 Wrong Answer。

### Final Strategy

- **What method did you finally use?**
  實作了類似**插入排序法 (Insertion Sort)** 的線上演算法。
  因為前面的數字其實「已經排好了」，所以當新數字進來時，我只需要不斷跟前面的數字比較 (`array[follow] < array[follow - 1]`)，如果比前面的小就交換，直到它找到屬於自己的正確位置為止。接著再用 `if (count % 2 == 0)` 判斷目前總數是奇數還是偶數，來決定要抓哪一個位置的數字印出。
- **Why does this method work?**
  這個做法非常適合「資料一個一個進來」的情境。每次只需處理新進來的那個數字，把它往前推到對的位置，大幅省去了重新排序已知序列的時間。
- **What edge cases did you consider?**
  第一筆資料進來時 (`count == 1`) 沒有前面的人可以比較，也不能除以 2，所以我特別加了 `if (count == 1)` 攔截，直接印出第一個數字並 `continue`。同時，我採用了 `1-based indexing`（從陣列索引 1 開始存），這樣在算偶數中間值 `count / 2` 與 `count / 2 + 1` 時邏輯非常直觀。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Initialize an array `array[15000]` and `count = 1`.
2. Loop continuously while reading a number into `array[count]`:
   a. Set a pointer `follow = count`.
   b. Loop while `follow > 1` AND `array[follow] < array[follow - 1]`:
      i. Swap `array[follow]` and `array[follow - 1]`.
      ii. Decrement `follow`. (This shifts the new number into sorted position)
   c. If `count == 1`:
      - Print `array[count]`, increment `count`, CONTINUE.
   d. If `count` is even (`count % 2 == 0`):
      - Calculate median = (array[count / 2] + array[count / 2 + 1]) / 2.
      - Print median.
   e. Else (`count` is odd):
      - Calculate median index = count / 2 + 1.
      - Print `array[median index]`.
   f. Increment `count`.
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int array[15000] = {};
    int count = 1;

    while (cin >> array[count]) {
        // Fail: 忘記排序，直接拿輸入當下的位置來算中位數
        if (count == 1) {
            cout << array[count] << endl;
        } else if (count % 2 == 0) {
            int numm = (array[count / 2] + array[count / 2 + 1]) / 2;
            cout << numm << endl;
        } else {
            int numm = count / 2 + 1;
            cout << array[numm] << endl;
        }
        count++;
    }
}
```

**Why it failed:**

- 完全忽略了中位數的先決條件是「必須排序」。直接把剛讀進來的未排序陣列拿去切一半，算出來的根本只是「輸入順序的中間值」，不是「數值大小的中位數」。

### Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int array[15000] = {};
    int count = 1;

    while (cin >> array[count]) {

        int follow = count;
        while (array[follow] < array[follow - 1]) {
            int tmp = 0;
            tmp = array[follow];
            array[follow] = array[follow - 1];
            array[follow - 1] = tmp;
            follow--;
        }
        if (count == 1) {
            cout << array[count] << endl;
            count++;
           continue;
        }
        if (count % 2 == 0) {
            int numm = (array[count / 2] + array[count / 2 + 1]) / 2;
            cout << numm<<endl;
        }
        else {
            int numm = count / 2+1;
            cout << array[numm] << endl;
        }
        count++;
    }
    
}
```

**Why it works:**

- 完美融入了 Insertion Sort 的精神。內層的 `while (array[follow] < array[follow - 1])` 確保了陣列在任何時刻都是由小到大排序好的狀態。
- 採用 1-based indexing（從 1 開始數），所以在計算中位數的索引時，`count/2` 與 `count/2 + 1` 剛好能精準抓到正中間的數值，邏輯清晰且不易寫錯。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 讀入後直接尋找索引中間值 | 讀入後**先向前交換至正確排序位置**，再找中間值 |
| Edge Cases | 沒特別處理第一筆測資的邏輯防呆 | 利用 `count == 1` 處理首筆測資，避免越界 |
| Output Handling | 相同 | 相同 |
| Other | WA (邏輯錯誤) | AC (漂亮實作線上排序) |

### Reflection

- **What mistake did you make?**
  初學這題很容易一味依賴 C++ 內建的 `sort()` 函數。雖然每次都用 `sort(array, array + count)` 也能過，但在大資料量時會非常耗時。
- **What did you learn from debugging this problem?**
  學習到如何手刻「線上排序 (Online Sorting)」。當資料是一筆一筆進來時，利用 Insertion Sort 的核心概念——「把新數字往前推到正確位置」——會比重新排序整個陣列有效率得多。
- **If you solve a similar problem again, what will you do better?**
  如果未來題目難度升級，數字多達 $10^5$ 或 $10^6$ 個，這個 $O(N^2)$ 的做法可能會拿到 Time Limit Exceeded (TLE)。那時候可以挑戰更進階的資料結構：利用**兩個 Priority Queue (一個 Max-Heap、一個 Min-Heap)** 來動態維護中位數，可以把時間複雜度降到極致的 $O(\log N)$！