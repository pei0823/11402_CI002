# UVa 11292 - The Dragon of Loowater

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11292
- **Problem Title:** The Dragon of Loowater
- **Problem Link:** [UVa 11292 The Dragon of Loowater](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2267)
- **Source Code (Correct/Accepted):** [src/11292.cpp](./src/11292.cpp)

## 2. Problem Statement in My Own Words

- **Input:** 龍的頭數 $D$ 與勇士數 $N$。接著輸入每個龍頭的大小，以及每個勇士能砍的大小。
- **Output:** 砍掉所有龍頭所需的最小花費；若無法砍完所有龍頭，輸出 `Loowater is doomed!`。
- **Core Task:** 龍頭必須由小到大砍，勇士也要由小到大派，這樣才能確保花費最小。

## 3. Thinking Logic and Strategy

### Strategy: Greedy Algorithm
1. **排序：** 將龍頭大小與勇士能力都從小到大排序。
2. **匹配：** 用雙指標掃描：
   - 如果當前勇士砍得下當前龍頭：勇士花費增加，進入下一個龍頭與下一個勇士。
   - 如果砍不下：代表當前勇士能力太弱，換下一個更強的勇士（指標往後移）。
3. **終止條件：** 若龍頭砍完了，輸出總花費；若勇士用完了但龍頭還在，輸出 doomed。



## 4. Pseudocode

```text
START
1. While reading D, N and D!=0 or N!=0:
   a. Read dragon_heads, knights. Sort both.
   b. knight_idx = 0, dragon_idx = 0, total_gold = 0.
   c. While dragon_idx < D and knight_idx < N:
      i. If knights[knight_idx] >= dragon_heads[dragon_idx]:
         - total_gold += knights[knight_idx]
         - dragon_idx++, knight_idx++
      ii. Else: knight_idx++
   d. If dragon_idx == D: print total_gold.
   e. Else: print "Loowater is doomed!"
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int d, n;
    while (cin >> d >> n && (d != 0 || n != 0)) {
        vector<int> heads(d), knights(n);
        for (int i = 0; i < d; i++) cin >> heads[i];
        for (int i = 0; i < n; i++) cin >> knights[i];
        
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        
        long long gold = 0;
        int d_idx = 0, k_idx = 0;
        
        while (d_idx < d && k_idx < n) {
            if (knights[k_idx] >= heads[d_idx]) {
                gold += knights[k_idx];
                d_idx++;
                k_idx++;
            } else {
                k_idx++; // 勇士太弱，換下一個
            }
        }
        
        if (d_idx == d) cout << gold << endl;
        else cout << "Loowater is doomed!" << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 貪婪法最優解，$O(N \log N)$ |
| Sorting | 使用 `std::sort` 解決了自刻排序的 Bug |
| Termination | 處理了 `Loowater is doomed!` 的判定 |

- **Mistake:** 原程式碼的手刻排序在 `tmp == 1` 時會中斷，導致第 1 個元素無法正確歸位。且處理「砍不下龍頭」的邏輯中，`loowsum` 的累加與指標移動順序較為複雜。
- **Learned:** 貪婪法最重要的前提是「排序」，先排好序，問題就會變成單純的陣列遍歷。
- **Future:** 看到需要「分配資源」(如：砍龍頭) 且要求「最小花費」的問題，優先思考 Greedy + Sorting。