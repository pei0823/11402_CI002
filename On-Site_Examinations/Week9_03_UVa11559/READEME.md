# UVa 11559 - Event Planning

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11559
- **Problem Title:** Event Planning
- **Problem Link:** [UVa 11559 Event Planning](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2554)
- **Source Code (Correct/Accepted):** [src/11559.cpp](./src/11559.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  多筆測試資料。每筆包含參加人數、總預算、飯店數量、參訪週數。接著是每家飯店的「每人房價」以及「各週提供的床位數」。
- **What is the expected output?**
  輸出完成活動所需的「最低總費用」。若無法在預算內找到合適飯店，則輸出 `stay home`。
- **What are the main rules or constraints?**
  1. 飯店房價是「每人」的價格。
  2. 同一週內，該飯店必須有足夠的床位容納所有參與者。
  3. 總費用不能超過總預算。

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts
- **Method:** 窮舉所有飯店與所有週次，尋找滿足條件的最小值。
- **Logic:** 對每一家飯店，檢查它在每一週提供的床位是否足夠，若足夠則計算 `價格 * 人數`，並與目前記錄的最低價 (`final`) 比較。

### Final Strategy
- **Optimization:** 設定 `final` 為一個極大值（如 5,000,000），若最後發現 `final` 沒被更新過，表示沒有任何飯店符合條件，印出 `stay home`。

## 4. Pseudocode

```text
START
1. While reading participants, budget, hotels, weeks:
   a. Initialize final = infinity.
   b. For each hotel:
      i. Read price.
      ii. For each week:
          - Read available_beds.
          - If available_beds >= participants AND (price * participants) <= budget:
            - final = min(final, price * participants)
   c. If final <= budget, print final. Else, print "stay home".
END
```

## 5. Correct Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int people, budget, hotelnum, weeknum;
    while (cin >> people >> budget >> hotelnum >> weeknum) {
        int price, bednum;
        int final = 5000001; // 初始化為超過預算的最大值
        
        for (int i = 0; i < hotelnum; i++) {
            cin >> price;
            for (int j = 0; j < weeknum; j++) {
                cin >> bednum;
                // 檢查：床位夠且總價在預算內 (包含等於)
                if (bednum >= people) {
                    int tmp = price * people;
                    if (tmp <= budget && final > tmp) {
                        final = tmp;
                    }
                }
            }
        }
        
        if (final > budget) cout << "stay home" << endl;
        else cout << final << endl;
    }
    return 0;
}
```

## 6. Difference and Reflection

| Item | Assessment |
|---|---|
| Logic | 邏輯正確，符合 Event Planning 需求 |
| Edge Cases | 修正了 `tmp < budget` 誤判等於預算的情況 |
| Output | 嚴格遵守格式 |

- **Mistake:** 原本的 `tmp < budget` 會漏掉剛好等於預算的狀況；`bednum > people` 其實題目允許 `bednum == people`。
- **Learned:** 處理金錢或邊界問題時，條件式一定要確認是否包含「等於」。
- **Future:** 養成初始化變數時，取一個明顯超過任何可能結果的值作為初始旗標，能簡化後續的 `if` 判斷。