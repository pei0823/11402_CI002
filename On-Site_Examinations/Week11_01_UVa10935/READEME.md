# UVa 10935 - Throwing cards away I

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10935
- **Problem Title:** Throwing cards away I
- **Problem Link:** [UVa 10935 Throwing cards away I](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876)
- **Source Code (Correct/Accepted):** [src/10935.cpp](./src/10935.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  多筆測試資料，每筆輸入一個正整數 $N$。當輸入為 0 時程式結束。
- **What is the expected output?**
  輸出丟棄卡片的順序，以及最後剩下的那一張卡片。
- **What are the main rules?**
  1. 丟棄最上面一張。
  2. 將新的最上面一張移到最下面。
  3. 重複以上動作直到只剩一張為止。

## 3. Thinking Logic and Solution Strategy

- **Method:** 使用 `std::queue` 模擬卡片堆。
- **Logic:**
  - `front()`：取得最上面的卡片。
  - `pop()`：移除卡片。
  - `push()`：將移動到的卡片放到尾端。
- **Why this works:** Queue 的 FIFO 特性與題目描述的「丟棄後再移到尾端」完全吻合。

## 4. Pseudocode

```text
START
1. While reading N and N != 0:
   a. Create a queue `q` and push 1 to N into it.
   b. Create a vector or queue `discarded` to store thrown cards.
   c. While q.size() > 1:
      i.   Store q.front() in `discarded`, then q.pop().
      ii.  If q is not empty:
           - Move q.front() to the back: q.push(q.front()), q.pop().
   d. Print "Discarded cards:" + `discarded`.
   e. Print "Remaining card: " + q.front().
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    long long int n;
    while (cin >> n && n != 0) {
        queue<long long int> q;
        for (int i = 1; i <= n; i++) q.push(i);

        cout << "Discarded cards:";
        bool first = true;
        while (q.size() > 1) {
            if (!first) cout << ",";
            cout << " " << q.front();
            q.pop();
            first = false;

            // 移動下一張到後面
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        cout << endl << "Remaining card: " << q.front() << endl;
    }
    return 0;
}
```

## 6. Difference and Reflection

| Item | Assessment |
|---|---|
| Logic | 完美利用 Queue 的 FIFO 特性 |
| Edge Cases | 處理了 N=1 時不需要丟棄的情況 |
| Output | 逗號與空格格式準確 |

- **Mistake:** 原程式碼中用了兩個 Queue 來存，其實只需要一個 Queue 做操作，丟棄的直接印出即可，減少空間浪費。
- **Learned:** 在處理移動元素到後面的動作時，先 `push` 再 `pop` 是經典手法。
- **Future:** 遇到類似卡片或循環問題，Queue 是處理順序模擬的首選。