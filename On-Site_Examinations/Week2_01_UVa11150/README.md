# UVa 11150 - Cola

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11150
- **Problem Title:** Cola
- **Problem Link:** [UVa 11150 Cola](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2091)
- **Source Code (Fail):** [src/11150-fail.cpp](./src/11150-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11150.cpp](./src/11150.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  多筆測資。每筆輸入一個整數 $n$，代表一開始買了幾瓶可樂。
- **What is the expected output?**
  輸出一個整數，代表你最多總共能喝到幾瓶可樂。
- **What are the main rules or constraints?**
  每 3 個空瓶可以換 1 瓶全新的可樂。你可以向朋友「借」空瓶來湊齊 3 個，但最後你必須要有足夠的空瓶「還」給朋友。
- **What is the core task you must solve?**
  在遵守「借了必須還」的規則下，找出能喝到最多瓶可樂的最佳策略（借 0 瓶、借 1 瓶或借 2 瓶）。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  一開始的想法很單純：就是一直把喝完的空瓶拿去除以 3，商數加進總喝掉的瓶數裡，餘數加上新的空瓶再繼續除以 3，直到空瓶數小於 3 為止。
- **What difficulty did you notice at the beginning?**
  只考慮自己手上的空瓶會漏掉題目的隱藏條件——「可以向朋友借空瓶」。有時候借了空瓶湊滿換新的喝完後，剛好能把空瓶還回去，這樣總數會變多。

### Final Strategy

- **What method did you finally use?**
  暴力窮舉（模擬法）。我直接把情況分成三條平行時空來跑迴圈：
  1. 不借空瓶 (`n1`)
  2. 借 1 個空瓶 (`n2`)
  3. 借 2 個空瓶 (`n3`)
- **Why does this method work?**
  因為最多也只能借 2 個空瓶（借 3 個相當於直接拿 1 瓶滿的，不合邏輯）。把三種情況獨立計算完後，針對有借空瓶的情況進行「驗算」——檢查最後剩下的空瓶數夠不夠還（例如借了 1 瓶，最後手上空瓶 `< 1` 就是不合法，該情況的總數歸零）。最後取這三個情況裡最大的數字就是答案。
- **What edge cases did you consider?**
  考慮了借了卻還不出來的情況，利用 `if (n2 < 1) numplus = 0;` 與 `if (n3 < 2) numplusplus = 0;` 強制將不合法的結果排除。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Read input `n` using a while loop for EOF.
2. Initialize 3 parallel states for the simulation:
   - State 0: bottles = n
   - State 1: bottles = n + 1 (borrowed 1)
   - State 2: bottles = n + 2 (borrowed 2)
3. For each state, loop while bottles >= 3:
   - add (bottles / 3) to the total drunk
   - update bottles = (bottles / 3) + (bottles % 3)
4. Validate State 1: if remaining bottles < 1, valid total = 0.
5. Validate State 2: if remaining bottles < 2, valid total = 0.
6. Find and output the maximum total among the three valid states.
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int total = n;
        int empty_bottles = n;
        while (empty_bottles >= 3) {
            total += empty_bottles / 3;
            empty_bottles = empty_bottles / 3 + empty_bottles % 3;
        }
        cout << total << endl;
    }
    return 0;
}
```

**Why it failed:**

- 完全沒有實作「向朋友借空瓶」的邏輯。
- 舉例來說，輸入若是 `8`，這個寫法算出來是 11，但如果先借 1 個空瓶，就可以喝到 12 瓶（正確答案）。

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n=0;
    while (cin >> n) {
        int n1 = n;
        int n2 = n; n2 += 1;
        int n3 = n; n3 += 2;
        int num=n;
        int numplus=n;
        int numplusplus = n;
        int max=0;

        while (n1 >= 3) {
            num += n1 / 3;
            n1 = n1 / 3 + n1 % 3;
        }
        if (max < num)max = num;
        
        while (n2 >= 3) {
            numplus += n2 / 3;
            n2 = n2 / 3 + n2 % 3;
        }
        if (n2 < 1)numplus = 0;
        if (max < numplus)max = numplus;
        
        while (n3 >= 3) {
            numplusplus += n3 / 3;
            n3 = n3 / 3 + n3 % 3;
        }
        if (n3 < 2)numplusplus = 0;
        if (max < numplusplus)max = numplusplus;

        cout << max<< endl;
    }
}
```

**Why it works:**

- 完整模擬了所有可能性（借 0、借 1、借 2）。
- 有加上「借了空瓶必須還」的檢查機制，若不符合則把該路徑的結果排除，邏輯嚴密。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 只有單線程，有幾個空瓶換幾瓶 | 三線程模擬，測試不同的初始空瓶狀態 |
| Edge Cases | 沒有考慮到「可以預借」這件事 | 完美攔截「借了還不出來」的無效操作 |
| Output Handling | 直接印出總數 | 取三種情況的最大值 `max` 印出 |
| Other | 程式碼短但有邏輯漏洞 | 變數較多，雖然稍長但非常直觀好懂 |

### Reflection

- **What mistake did you make?**
  直覺思考時很容易忘記題目裡「可以借空瓶」的寬容條件，導致少算了極限情況下的可樂瓶數。
- **What did you learn from debugging this problem?**
  遇到這種帶有「借貸關係」的題目，不一定要想出完美數學解，直接把所有合法的預借條件「展開成平行時空」去跑模擬，最後再做合法性檢驗，是個很穩定的解題策略。
- **If you solve a similar problem again, what will you do better?**
  下次會試著尋找這類題目的數學規律。例如這題其實等價於直接計算 `n + n / 2`，寫法可以濃縮到非常短，但目前的模擬法對於訓練邏輯思考已經很棒了。