# UVa 10041 - Vito's Family

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10041
- **Problem Title:** Vito's Family
- **Problem Link:** [UVa 10041 Vito's Family](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=982)
- **Source Code (Correct/Accepted):** [src/10041.cpp](./src/10041.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  第一行是測試案例數 $T$。接下來每行第一個數字是 $R$（親戚數量），後面跟著 $R$ 個親戚所在的地址。
- **What is the expected output?**
  找出一個點，使得所有親戚到這個點的距離總和最小，並輸出該最小距離總和。
- **What are the core rules?**
  距離定義為絕對值差 $|x_1 - x_2|$。

## 3. Thinking Logic and Solution Strategy

### Strategy: Median Property
數學上，對於一組數值，使其到某一點距離總和最小的點，就是**中位數 (Median)**。
1. 將所有地址排序。
2. 找到中間的那個地址。
3. 計算所有親戚到中位數的距離總和。

### Efficiency
- 使用 `std::sort` 排序，時間複雜度 $O(R \log R)$，比插入排序 $O(R^2)$ 快得多。

## 4. Pseudocode

```text
START
1. Read T.
2. Loop T times:
   a. Read R and R numbers into array `A`.
   b. Sort `A`.
   c. median = A[R / 2].
   d. total_dist = 0.
   e. For each x in A: total_dist += abs(x - median).
   f. Print total_dist.
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        vector<int> a(r);
        for (int i = 0; i < r; i++) cin >> a[i];
        
        // 排序後直接取中位數
        sort(a.begin(), a.end());
        int median = a[r / 2];
        
        int total_dist = 0;
        for (int x : a) {
            total_dist += abs(x - median);
        }
        cout << total_dist << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 掌握中位數性質，解法最優 |
| Efficiency | 使用 STL sort，$O(R \log R)$ |
| Input | 避免複雜的字串拆解，直接讀取數字 |

- **Mistake:** 原程式碼使用字串解析（`str[i]-'0'`）容易出錯，特別是當地址是雙位數時會失敗。
- **Learned:** 處理數字輸入時，除非格式非常特殊，否則直接用 `cin >> num` 處理即可，不需要費力拆字串。
- **Future:** 看到「求距離總和最小」的問題，第一時間就要想到中位數。