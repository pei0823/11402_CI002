# UVa 10954 - Add All

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10954
- **Problem Title:** Add All
- **Problem Link:** [UVa 10954 Add All](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895)
- **Source Code (Correct/Accepted):** [src/10954.cpp](./src/10954.cpp)

## 2. Problem Statement in My Own Words

- **What is the input?**
  多筆測資。每筆給定整數 $N$ 和 $N$ 個數字。當 $N=0$ 時結束。
- **What is the expected output?**
  將這些數字全部合併成一個數，合併的規則是每次選擇兩個最小的數字相加，合併的費用是這兩個數字的和。輸出累積的總費用。
- **What is the core task?**
  在每次合併步驟中，確保選取的兩個數字是當前序列中最小的，這能使總成本降至最低。

## 3. Thinking Logic and Strategy

### Strategy: Greedy Algorithm
這是一個典型的「貪婪法 (Greedy)」問題。若我們希望總加總成本最小，我們應確保：
1. 每次合併都選最小的兩個數字。
2. 合併後的新數字放回集合，再次選取最小的。
這剛好符合**最小堆疊 (Min-Priority Queue)** 的操作特性。

### Visualizing the Strategy


## 4. Pseudocode

```text
START
1. While reading N and N != 0:
   a. Create a Min-Priority Queue `pq`.
   b. Push all numbers into `pq`.
   c. total_cost = 0.
   d. While pq.size() > 1:
      i.   a = pq.top(), pq.pop().
      ii.  b = pq.top(), pq.pop().
      iii. sum = a + b.
      iv.  total_cost += sum.
      v.   pq.push(sum).
   e. Print total_cost.
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        // 使用優先權佇列實現 Min-Heap
        // greater<long long> 確保最上方是最小值
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for (int i = 0; i < n; i++) {
            long long val;
            cin >> val;
            pq.push(val);
        }
        
        long long total_cost = 0;
        while (pq.size() > 1) {
            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();
            
            long long sum = first + second;
            total_cost += sum;
            pq.push(sum);
        }
        
        cout << total_cost << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | Greedy 策略 + Min-Heap，解法最優 |
| Efficiency | $O(N \log N)$，使用 Priority Queue 效率極高 |
| Correctness | 處理了累積加總的溢位問題 (使用 long long) |

- **Mistake:** 原程式碼使用插入排序法 $O(N^2)$。雖然這題 $N=5000$ 還能勉強過，但若 $N$ 進一步增大，執行時間會顯著變慢。
- **Learned:** 涉及到「每次選取最小/最大值」的問題，直接優先考慮 `priority_queue`。
- **Future:** 遇到需要多次排序或合併的題目，不要試圖維護一個有序陣列，改用 `priority_queue` 或 `multiset` 會讓程式更簡潔。