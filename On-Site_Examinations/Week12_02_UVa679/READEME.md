# UVa 679 - Dropping Balls

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 679
- **Problem Title:** Dropping Balls
- **Problem Link:** [UVa 679 Dropping Balls](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=620)
- **Source Code (Correct/Accepted):** [src/679.cpp](./src/679.cpp)

## 2. Problem Statement in My Own Words

- **Input:** 多組測資。每組包含樹的深度 $D$ 以及球的數量 $I$。
- **Output:** 第 $I$ 顆球最終會落在哪一個節點。
- **Rules:** 每個節點有一個開關（初始為 OFF）。球經過時，若開關為 OFF，球往左跑並將開關切換為 ON；若為 ON，球往右跑並將開關切換為 OFF。

## 3. Thinking Logic and Solution Strategy

### Key Insight
每一顆球都會改變路徑上節點的狀態。對於一個根節點 $k$：
- 第 1, 3, 5... 顆球會選擇「左路」(走向 $2k$)。
- 第 2, 4, 6... 顆球會選擇「右路」(走向 $2k+1$)。

### Strategy
不需要模擬每一顆球，對於第 $I$ 顆球：
- 如果 $I$ 是奇數，它是該節點收到的第 $(I+1)/2$ 顆左轉球。
- 如果 $I$ 是偶數，它是該節點收到的第 $I/2$ 顆右轉球。
如此遞迴下去，直到達到深度 $D$ 為止。



## 4. Pseudocode

```text
START
1. While reading D and I:
   a. current_node = 1.
   b. Loop D-1 times:
      i.   If I is odd:
           - current_node = current_node * 2
           - I = (I + 1) / 2
      ii.  Else:
           - current_node = current_node * 2 + 1
           - I = I / 2
   c. Print current_node.
END
```

## 5. Correct Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, i;
        cin >> d >> i;
        
        int curr = 1;
        // 總共會經過 d-1 個分支決定方向
        for (int depth = 1; depth < d; depth++) {
            if (i % 2 != 0) { // 奇數球：往左
                curr = curr * 2;
                i = (i + 1) / 2;
            } else {          // 偶數球：往右
                curr = curr * 2 + 1;
                i = i / 2;
            }
        }
        cout << curr << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 利用奇偶性判斷方向，極度高效 |
| Complexity | $O(D)$，其中 $D$ 為深度，遠優於 $O(I \times D)$ |

- **Mistake:** 原程式碼試圖用數學公式一次算出結果，但忽略了二元樹路徑選擇是「動態」且「依賴球的順序」的。
- **Learned:** 看到二元樹且包含開關切換的問題，優先考慮每個節點的「流量分配」（奇偶性）。
- **Future:** 此類題型（Dropping Balls）是標準的樹結構路徑問題，務必掌握 $2k$ 與 $2k+1$ 的節點規律。