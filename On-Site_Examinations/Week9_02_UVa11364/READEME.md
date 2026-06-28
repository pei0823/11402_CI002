# UVa 11364 - Parking

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11364
- **Problem Title:** Parking
- **Problem Link:** [UVa 11364 Parking](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2349)
- **Source Code (Correct/Accepted):** [src/11364.cpp](./src/11364.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  第一行是一個整數 $T$，代表測試案例的組數。每一組包含商店的數量 $N$，以及這 $N$ 間商店分別所在的直線座標位置。
- **What is the expected output?**
  輸出你為了拜訪所有商店並回到車子停放點，所需行走的最短總距離。
- **What are the main rules or constraints?**
  你可以把車停在任何一個位置。不管最後車停在哪，你必須要從車子出發，拜訪完所有商店，再走回車子。
- **What is the core task you must solve?**
  在線性的空間中，找出一組位置，使得從該位置出發並覆蓋所有點再回到原點的距離最小。

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts
- **Method:** 觀察法。
- **Logic:** 為了覆蓋最左邊的點 ($min$) 和最右邊的點 ($max$)，你必須至少走完這段區間。因為你必須回到原點，所以這段區間你必須走兩次。因此最短距離即為 $2 \times (max - min)$。

### Final Strategy
- **Implementation:** 不需要將所有位置存入陣列排序，只需在讀取時同步更新 `min` 與 `max` 的值，空間複雜度降至 $O(1)$，時間複雜度 $O(N)$。

## 4. Pseudocode

```text
START
1. Read T (test cases).
2. Loop T times:
   a. Read N (number of shops).
   b. Initialize min = 100, max = 0.
   c. Loop N times:
      i.   Read shop position `pos`.
      ii.  Update min = min(min, pos), max = max(max, pos).
   d. Calculate result = 2 * (max - min).
   e. Print result.
END
```

## 5. Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int ttt;
    cin >> ttt;
    for (int m = 0; m < ttt; m++) {
        int n;
        cin >> n;
        
        int min_val = 100; // 根據題目範圍，座標在 0-99 之間
        int max_val = 0;
        
        for (int i = 0; i < n; i++) {
            int nn;
            cin >> nn;
            if (nn < min_val) min_val = nn;
            if (nn > max_val) max_val = nn;
        }
        int sum = 2 * (max_val - min_val);
        cout << sum << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 非常簡潔的 $O(N)$ 解法 |
| Efficiency | 空間 $O(1)$，時間 $O(N)$，極佳 |
| Optimization | 不需要存陣列即可完成 |

- **Mistake:** 原程式碼中的 `min` 和 `max` 變數名稱有時會與 `algorithm` 標頭檔的函式衝突，建議改名為 `min_val` 或 `max_val` 以免編譯錯誤。
- **Learned:** 數學觀察比複雜的模擬重要。在某些幾何問題中，找出邊界值 (Min/Max) 往往就是解題關鍵。
- **Future:** 遇到這類一維線上的距離問題，先檢查是否只需關注最大值與最小值即可。