# UVa 12503 - Robot Instructions

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 12503
- **Problem Title:** Robot Instructions
- **Problem Link:** [UVa 12503 Robot Instructions](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3947)
- **Source Code (Fail):** [src/12503-fail.cpp](./src/12503-fail.cpp)
- **Source Code (Correct/Accepted):** [src/12503.cpp](./src/12503.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  第一行是一個整數，代表有幾組測試資料。每組資料的第一行包含一個整數 `n`，代表指令的數量（1 到 100 之間）。接下來有 `n` 行指令，指令分為三種：`LEFT`、`RIGHT`，或是 `SAME AS i`。
- **What is the expected output?**
  輸出機器人執行完所有指令後的最終座標位置（機器人起點在 0）。
- **What are the main rules or constraints?**
  `LEFT` 代表位置減 1，`RIGHT` 代表位置加 1。`SAME AS i` 代表執行與第 `i` 個指令一模一樣的動作。
- **What is the core task you must solve?**
  正確記錄並解析前面的所有指令。當遇到 `SAME AS i` 時，能夠迅速查出並執行第 `i` 步的實際位移，同時更新當前的總座標。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  一開始的想法是讀取指令字串，遇到左就減，遇到右就加。如果遇到 `SAME AS`，就回去找第 `i` 步是什麼字串。
- **What difficulty did you notice at the beginning?**
  如果要把完整的字串記錄下來，後面遇到 `SAME AS` 還要重新判斷一次字串是左還是右，會讓程式碼變得很複雜。而且如果遇到連續的 `SAME AS`（例如第 4 步和第 3 步一樣，第 3 步又和第 2 步一樣），單純存字串處理起來會發生連鎖混亂。

### Final Strategy

- **What method did you finally use?**
  建立一個整數陣列 `list` 來記錄「歷史位移量」而不是「指令字串」。第 `i` 步往左就存 `-1`，往右就存 `1`。當指令是 `SAME AS i` 時，直接去陣列讀取 `list[i]` 的值加到總位移上，並且**把這個位移值也存進 `list[當前步數]` 裡**。
- **Why does this method work?**
  這就像是把所有動作都轉換成實質的數字 (+1 或 -1)。陣列直接扮演了快取的角色，無論前面的 `SAME AS` 怎麼連鎖，陣列裡記錄的永遠是最終換算出來的 +1 或 -1，查表速度極快且邏輯單純。
- **What edge cases did you consider?**
  輸入格式包含空格（如 `SAME AS 1`）。利用 `cin` 遇到空格會斷開的特性，用 `cin >> as >> n` 把不需要的字串 "AS" 吃掉，精準抓到後面的數字 `n`。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Read the number of test cases `turn`.
2. Loop `turn` times:
   a. Initialize position `numm = 0` and array `list` to record moves.
   b. Read the number of instructions `num`.
   c. Loop `i` from 1 to `num`:
      i.   Read string `ord`.
      ii.  If `ord[0]` is 'L', move left (`numm--`), and set `list[i] = -1`.
      iii. If `ord[0]` is 'R', move right (`numm++`), and set `list[i] = 1`.
      iv.  If `ord[0]` is 'S', read string `as` and integer `n`.
           - Set `list[i] = list[n]` to copy the actual move history.
           - Add `list[i]` to position `numm`.
   d. Output the final position `numm`.
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int turn;
    cin >> turn;
    for (int t = 0; t < turn; t++) {
        int num;
        int list[100] = {};
        cin >> num;
        string ord;
        int numm = 0;
        for (int i = 1; i <= num; i++) {
            cin >> ord;
            if (ord == "LEFT") {
                numm--;
                list[i] = -1;
            } else if (ord == "RIGHT") {
                numm++;
                list[i] = 1;
            } else if (ord == "SAME") {
                string as;
                int n;
                cin >> as >> n;
                numm += list[n];
                // 致命錯誤：忘記更新當前的 list[i] 狀態
            }
        }
        cout << numm << endl;
    }
}
```

**Why it failed:**

- 在處理 `SAME AS i` 的時候，雖然把位置 `numm` 加上了歷史的移動量，卻忘記把這個動作記錄到 `list[i]` 當中。
- 這樣會導致連鎖錯誤：如果指令 3 是 `SAME AS 2`，指令 4 是 `SAME AS 3`，由於第 3 步沒有更新 `list[3]`，它預設會是 0，導致第 4 步查詢時拿到 0，完全沒有產生位移。

### Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int turn;
    cin >> turn;
    for (int t = 0; t <turn;t++) {
        int num;
        int list[100] = {};
        cin >> num;
        string ord;
        int numm = 0;
        for (int i = 1; i <= num; i++) {
            cin >> ord;
            
            if (ord[0] == 'L') {
                numm--;
                list[i] = -1;
            }
            else if (ord[0] == 'R') {
                numm++;
                list[i] = 1;
            }
            else if (ord[0] == 'S') {
                string as;
                int n;
                cin >> as >> n;
                list[i] = list[n];
                numm += list[i];
            }
        }
        cout << numm << endl;
    }
}
```

**Why it works:**

- `list[i] = list[n];` 這一行完美解決了歷史紀錄的問題，確保了不論經過幾次 `SAME AS` 連鎖，陣列裡永遠保存的是最純粹的 `-1` 或 `1`。
- 利用判斷字首 `ord[0] == 'L'`、`'R'`、`'S'` 這個技巧非常聰明，避開了比對完整字串的麻煩，程式碼既精簡、執行速度也更快。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 處理 SAME 時未保存當前操作狀態 | 處理 SAME 時，將引用的操作結果賦值給當前 `list[i]` |
| Edge Cases | 無法處理連續的 `SAME AS` 連鎖 | 能正確追溯並傳遞所有前面的移動歷史 |
| Output Handling | 相同 | 相同 |
| Other | 比對完整字串 (`ord == "LEFT"`) | 僅比對字首 (`ord[0] == 'L'`)，減少效能與打字開銷 |

### Reflection

- **What mistake did you make?**
  初學這題時，很容易直觀上認為「我只要拿到第 `n` 步的結果加上去就好」，卻忽略了「目前的這一步，也可能成為未來別人的歷史」，因此漏寫了更新當前歷史紀錄的步驟。
- **What did you learn from debugging this problem?**
  學到了「狀態傳遞（連鎖更新）」的重要性。只要是需要參照歷史紀錄的問題，每一次的操作結束後，務必將當前的狀態也更新進歷史紀錄陣列中，才能保證資料的一致性。
- **If you solve a similar problem again, what will you do better?**
  **陣列大小的設定存在越界風險**。題目提到最多有 100 個指令，因為迴圈是從 `i = 1` 跑到 `i <= num` (最大 100)，`list[100]` 的合法索引是 0~99。當 `i = 100` 時存取 `list[i]` 會超出陣列邊界，導致未定義行為 (UB)。雖然在很多編譯器下可能僥倖通過，但未來遇到類似情況，宣告陣列大小時一定會習慣多給一點空間（例如 `int list[105] = {};`）以確保記憶體安全。