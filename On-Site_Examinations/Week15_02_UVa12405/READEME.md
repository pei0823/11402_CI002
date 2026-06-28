# UVa 12405 - Scarecrow

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 12405
- **Problem Title:** Scarecrow
- **Problem Link:** [UVa 12405 Scarecrow](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836)
- **Source Code (Correct/Accepted):** [src/12405.cpp](./src/12405.cpp)

## 2. Problem Statement in My Own Words

- **Input:** $T$ 組測試案例。每組包含田的長度 $N$ 與田的狀態（`.` 為空地，`#` 為障礙物）。
- **Output:** 輸出至少需要多少個稻草人，才能覆蓋所有的空地。
- **Rules:** 一個稻草人放在位置 $i$，可以覆蓋 $[i-1, i+1]$ (即三個連續位置)。

## 3. Thinking Logic and Strategy

### Strategy: Greedy Algorithm
為了用最少數量的稻草人，當我們從左到右掃描到第一個未被覆蓋的空地（`.`）時，我們必須在那塊地之後放一個稻草人，這樣最能向右延伸覆蓋範圍。
- 如果在位置 $i$ 發現沒覆蓋，我們將稻草人放在 $i+1$。
- 這樣可以同時覆蓋 $i, i+1, i+2$ 三個位置。
- 直接跳過這三格，繼續向後掃描。



## 4. Pseudocode

```text
START
1. While reading T:
   a. For each test case:
      i. Read N, read string `field`.
      ii. scarecrows = 0, i = 0.
      iii. While i < N:
           - If field[i] == '.':
             - scarecrows++, i += 3 (跳過被覆蓋的三格)
           - Else:
             - i++ (是障礙物，繼續向後找)
      iv. Print "Case x: scarecrows".
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cass = 1; cass <= t; cass++) {
        int n;
        cin >> n;
        string gro;
        cin >> gro;
        
        int scarecrows = 0;
        for (int i = 0; i < n; ) {
            if (gro[i] == '.') {
                // 在這裡放稻草人，可以覆蓋 i, i+1, i+2
                scarecrows++;
                i += 3; 
            } else {
                // 是障礙物，無法覆蓋，往下一格找
                i++;
            }
        }
        cout << "Case " << cass << ": " << scarecrows << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 貪婪法最優，確保覆蓋最廣範圍 |
| Efficiency | $O(N)$，掃描一次即完成 |
| Clarity | 透過 `i+=3` 的邏輯避開了複雜的陣列修改 |

- **Mistake:** 原程式碼中 `gro[tmp+1] = '#'` 的修改方式雖然能標記覆蓋，但 `while` 迴圈會不斷重複檢查已經標記過的格子，導致邏輯冗長。
- **Learned:** 在處理「覆蓋範圍」類型的 Greedy 題目時，直接移動索引 `i` 會比修改原始數據更有效率且不易錯。
- **Future:** 遇到類似「放置物品覆蓋範圍」的題目，先找左邊界，然後向右跳躍，這是最經典的 Greedy 手法。