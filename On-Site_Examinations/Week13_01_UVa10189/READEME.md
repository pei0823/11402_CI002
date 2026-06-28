# UVa 10189 - Minesweeper

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10189
- **Problem Title:** Minesweeper
- **Problem Link:** [UVa 10189 Minesweeper](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1130)
- **Source Code (Correct/Accepted):** [src/10189.cpp](./src/10189.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  多組測資，每組輸入 $n$ 行 $m$ 列的地圖，`*` 代表地雷，`.` 代表空地。當 $n=0, m=0$ 時結束。
- **What is the expected output?**
  將地圖轉化為掃雷遊戲的格式：地雷維持 `*`，空地則填入該格周圍 8 個方向的地雷總數。兩筆測資間需輸出一個空行。

## 3. Thinking Logic and Solution Strategy

### Strategy
1. **地雷標記：** 使用二維陣列，遇到 `*` 存為 `-1`，其餘初始化為 `0`。
2. **計算頻率：** 遍歷整個地圖，每發現一個 `-1` (地雷)，就將其周圍 8 個方向的格子 `+1` (若該格不是地雷)。
3. **輸出處理：** 依序印出陣列。若該格是 `-1` 則印 `*`，否則印出數字。

### Visualizing the Logic


## 4. Pseudocode

```text
START
1. Initialize field_count = 1.
2. While reading N and M (N!=0 or M!=0):
   a. If field_count > 1, print a blank line.
   b. Initialize grid[N+2][M+2] = 0.
   c. Read input, store '*' as -1.
   d. For every cell (i, j):
      If grid[i][j] == -1:
         Increment all 8 neighbors if they are not -1.
   e. Print formatted grid.
   f. field_count++.
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y, count = 1;
    while (cin >> x >> y && (x != 0 || y != 0)) {
        if (count > 1) cout << endl; // 測資間空一行
        
        // 使用 [x+2][y+2] 避免處理邊界越界問題
        vector<vector<int>> num(x + 2, vector<int>(y + 2, 0));
        
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                char thing; cin >> thing;
                if (thing == '*') num[i][j] = -1;
            }
        }

        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (num[i][j] == -1) {
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            if (num[i + di][j + dj] != -1)
                                num[i + di][j + dj]++;
                        }
                    }
                }
            }
        }

        cout << "Field #" << count++ << ":" << endl;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (num[i][j] == -1) cout << "*";
                else cout << num[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 判斷地雷周圍 8 格的邏輯完全正確 |
| Efficiency | $O(N \times M)$，對於 $100 \times 100$ 很足夠 |
| Formatting | 修正了測資間的換行問題 |

- **Mistake:** 原程式碼對於測資間的空行處理方式是每筆後都加一個 `cout << endl`，這會導致最後一筆測資後也有空行，導致 PE。
- **Learned:** 處理陣列邊界時，開 `[N+2][M+2]` 並將實際資料放在 `1~N` 和 `1~M`，可以省去寫一大堆 `if` 判斷索引是否越界。
- **Future:** 遇到地圖類題目，務必優先考慮陣列擴充邊界法，這能大幅減少程式碼長度與邏輯 Bug。