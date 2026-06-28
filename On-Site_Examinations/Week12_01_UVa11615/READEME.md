# UVa 11615 - Family Tree

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11615
- **Problem Title:** Family Tree
- **Problem Link:** [UVa 11615 Family Tree](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2662)
- **Source Code (Correct/Accepted):** [src/11615.cpp](./src/11615.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  多筆測資。每筆給定樹的總深度 $D$ 以及兩個節點編號 $A$ 和 $B$。
- **What is the expected output?**
  計算在這棵深度為 $D$ 的完全二元樹中，扣掉節點 $A$ 和 $B$ 及其所有子孫之後，還剩下幾個節點。
- **What are the core rules?**
  這是一棵滿二元樹，根節點為 1，節點 $x$ 的左子為 $2x$，右子為 $2x+1$。

## 3. Thinking Logic and Solution Strategy

### Visualizing the Tree


### Logic
- **Total Nodes:** 一棵深度為 $D$ 的滿二元樹，總節點數為 $2^D - 1$。
- **Removing Subtrees:** 當我們選定一個節點 $A$（假設 $A \ge B$，我們只關心較大的那個節點），該節點及其以下的所有子孫都要被移除。
- **Calculation:** 移除的節點數量取決於節點 $A$ 所在的「深度」。若 $A$ 位於深度 $g$，則以 $A$ 為根的子樹深度為 $D - g + 1$，該子樹的節點數為 $2^{D-g+1} - 1$。
- **Result:** 總節點數 - 移除的節點數。

## 4. Pseudocode

```text
START
1. Read D, A, B.
2. Let A = max(A, B).
3. Calculate tree depth of A (let it be `g`):
   - Start from `tmpp = 1`, `gen = 1`.
   - While `tmpp <= A`: `tmpp *= 2`, `gen++`.
4. Calculate size of subtree rooted at A:
   - subtree_depth = D - gen + 1.
   - removed_nodes = 2^(subtree_depth) - 1.
5. Total nodes in full tree = 2^D - 1.
6. Print (Total nodes - removed_nodes).
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int d, a, b;
        cin >> d >> a >> b;
        if (b > a) swap(a, b);

        // 總節點數
        long long total_nodes = (1LL << d) - 1;

        // 計算 A 所在的深度
        int gen = 0;
        int temp = a;
        while (temp > 0) {
            temp >>= 1;
            gen++;
        }

        // 以 A 為根的子樹，其深度為 d - gen + 1
        // 該子樹節點數 = 2^(d - gen + 1) - 1
        long long removed_nodes = (1LL << (d - gen + 1)) - 1;

        cout << total_nodes - removed_nodes << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 轉為數學公式 $O(D)$ |
| Efficiency | 使用位移運算 `<<` 取代次方運算 |
| Insight | 成功將樹狀結構轉化為子樹節點數計算 |

- **Mistake:** 原程式碼用迴圈算 `minus`，雖然正確但容易產生邊界錯誤。使用 `(1LL << power) - 1` 來計算 $2^k-1$ 更加簡潔且不易出錯。
- **Learned:** 位元運算 `1LL << d` 等同於 $2^d$，處理樹狀結構問題時非常好用。
- **Future:** 遇到滿二元樹問題，先想公式而非硬跑迴圈。