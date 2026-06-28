# UVa 11389 - The Bus Driver Problem

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11389
- **Problem Title:** The Bus Driver Problem
- **Problem Link:** [UVa 11389 The Bus Driver Problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2384)
- **Source Code (Correct/Accepted):** [src/11389.cpp](./src/11389.cpp)

## 2. Problem Statement in My Own Words

- **Input:** $n$ (路線數), $d$ (每日允許的路線總長度), $r$ (超時費率)。接著輸入 $n$ 個早班路線長度與 $n$ 個晚班路線長度。
- **Output:** 司機為滿足所有路線所需的最小超時加班費總額。
- **Core Rules:** 任何一天，早班路線長度 + 晚班路線長度若超過 $d$，則超出部分需乘以 $r$ 計算費用。我們需要重新分配早晚班路線的配對來最小化總費用。

## 3. Thinking Logic and Strategy

### Strategy: Greedy Algorithm
若要讓超出 $d$ 的部分最少，我們應該讓「很長的路線」配對「很短的路線」。
1. 將早班路線從小到大排序。
2. 將晚班路線從大到小排序。
3. 兩兩配對後計算超時費用，若總和小於等於 $d$，則不產生超時費。



## 4. Pseudocode

```text
START
1. While reading n, d, r:
   a. Read morning_routes, evening_routes.
   b. Sort morning_routes ascending.
   c. Sort evening_routes descending.
   d. total_overtime_pay = 0.
   e. For i from 0 to n-1:
      i. daily_sum = morning_routes[i] + evening_routes[i].
      ii. If daily_sum > d:
          total_overtime_pay += (daily_sum - d) * r.
   f. Print total_overtime_pay.
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d, r;
    while (cin >> n >> d >> r && (n || d || r)) {
        vector<int> morning(n), evening(n);
        for (int i = 0; i < n; i++) cin >> morning[i];
        for (int i = 0; i < n; i++) cin >> evening[i];

        // 核心邏輯：最短的早班配最長的晚班
        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());

        long long total = 0;
        for (int i = 0; i < n; i++) {
            int sum = morning[i] + evening[i];
            if (sum > d) {
                total += (long long)(sum - d) * r;
            }
        }
        cout << total << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 貪婪法最優，$O(N \log N)$ |
| Sorting | 巧妙運用 `greater<int>()` 實現反向排序 |
| Data Types | 使用 `long long` 避免運算過程中的溢位 |

- **Mistake:** 原程式碼邏輯已相當完美，若要說改進，就是確保輸入判斷 `(n || d || r)` 比 `(n == 0 && d == 0 && r == 0)` 更簡潔。
- **Learned:** 這種「配對求極值」的問題，排序後的「反向配對」幾乎是標準解法。
- **Future:** 遇到類似路線分配、任務分配需要最小化超額成本的問題，先排序，再嘗試反向配對。