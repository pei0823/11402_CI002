# UVa 10008 - What's Cryptanalysis?

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10008
- **Problem Title:** What's Cryptanalysis?
- **Problem Link:** [UVa 10008 What's Cryptanalysis?](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=949)
- **Source Code (Fail):** [src/10008-fail.cpp](./src/10008-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10008.cpp](./src/10008.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- **What is the input?**
  第一行是一個整數 `n`，代表接下來會有 `n` 行文字。每行文字可能包含大小寫英文字母、數字、標點符號或空格。
- **What is the expected output?**
  統計所有文字中出現過的英文字母頻率（不分大小寫，全部視為大寫）。輸出時，頻率越高的字母排越前面；如果頻率一樣，則依照英文字母順序（A 到 Z）排列。每個字母一行，格式為 `字母 頻率`。
- **What are the main rules or constraints?**
  只統計英文字母 (A-Z, a-z)，忽略其他所有字元。字母必須統一轉為大寫統計與輸出。
- **What is the core task you must solve?**
  正確讀取帶有空格的整行字串，利用陣列紀錄每個字母出現的次數，並實作一個能同時兼顧「頻率大小」與「字母順序」的排序輸出邏輯。

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- **What was your first idea?**
  土法煉鋼！直接建一個大小為 28 的陣列，然後寫 26 個 `if` 條件判斷式。如果讀到 'a' 或 'A' 就把 `abc[1]` 加 1，讀到 'b' 或 'B' 就把 `abc[2]` 加 1，依此類推一路寫到 Z。輸出時再用一長串的 `if else` 把數字轉回字母印出來。
- **What difficulty did you notice at the beginning?**
  程式碼非常冗長且難以維護，光是複製貼上修改 26 次判斷式就很容易打錯字或漏掉。此外，讀取第一行測資數量後，如果直接混用 `cin` 和 `getline` 會遇到換行符號的坑。

### Final Strategy

- **What method did you finally use?**
  使用 ASCII 碼的數學運算特性。字母在電腦內部其實就是數字，大寫 A 是 65，小寫 a 是 97。只要判斷字元落在英文字母的區間內，就可以直接用減法算出它對應的陣列索引：例如 `txt[j] - 'a' + 1` 就能把 a~z 完美對應到 1~26。
- **Why does this method work?**
  利用字元的連續性，我們可以把 26 個 `if` 縮減成短短幾行程式碼。輸出時也是一樣，透過找目前陣列中的最大值 (`max`)，印出後再把該格歸零 (`abc[nmax] = 0`)，重複尋找直到最大值變成 0，就能達到由大到小排序輸出的效果。
- **What edge cases did you consider?**
  當字母頻率相同時，題目要求依照字母順序輸出。因為我是由前往後掃描陣列 `for (int j = 1; j <= 26; j++)` 去找 `max`，只要判斷式嚴格設定為 `abc[j] > max` (而不是 `>=`)，當出現相同頻率時，迴圈就會保留最前面（也就是字母順序最前面）的索引值，自然解決了同頻率排序的問題。

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. Read the number of lines `round`. (Careful with the leftover newline character).
2. Initialize an array `abc[27]` with 0 to store frequencies.
3. Initialize an `alphabet[27]` array to map 1~26 to 'A'~'Z'.
4. Loop to read each line using `getline`:
   a. Loop through each character in the string:
      - If char is 'a'~'z', increment `abc[char - 'a' + 1]`.
      - If char is 'A'~'Z', increment `abc[char - 'A' + 1]`.
5. Loop 26 times to print sorted results:
   a. Find the maximum value `max` and its index `nmax` in `abc` array.
   b. If `max == 0`, BREAK (all occurring letters printed).
   c. Print `alphabet[nmax]` and `max`.
   d. Set `abc[nmax] = 0` to exclude it from the next iteration.
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int round = 0;
    cin >> round;
    string txt;
    int abc[28] = { 0 };
    
    // Fail 1: 這裡會有 cin 殘留換行符號的問題，且 rounds <= round 會多跑一圈
    for (int rounds = 0; rounds <= round; rounds++) {
        getline(cin, txt);
        for (int i = 0; i < txt.size(); i++) {
            // Fail 2: 暴力窮舉，程式碼極度冗長
            if (txt[i] == 'a' || txt[i] == 'A') { abc[1]++; continue; }
            if (txt[i] == 'b' || txt[i] == 'B') { abc[2]++; continue; }
            // ... 中間省略 ...
            if (txt[i] == 'z' || txt[i] == 'Z') { abc[26]++; continue; }
        }
    }
    
    for (int i = 0; i < 27; i++) {
        int max = 0;
        int nmax= 0;
        for (int j = 1; j <= 26; j++) {
            if (abc[j] > max) {
                max = abc[j];
                nmax = j;
            }
        }
        if (max == 0)break;
        // Fail 3: 輸出依然使用暴力窮舉
        if (nmax == 1) { cout << "A ";}
        else if (nmax == 2) { cout << "B "; }
        // ... 中間省略 ...
        else if (nmax == 26) { cout << "Z "; }
        cout << max << endl;
        abc[nmax] = 0;
    }
}
```

**Why it failed:**

- **效率與可讀性極差：** 雖然邏輯上能算對，但用了幾十行的 `if else`，完全沒有發揮程式語言處理規律資料的優勢。
- **輸入坑：** 第一個 `cin >> round;` 讀完數字後，緩衝區還會留著一個換行符號 (`\n`)。接下來的迴圈如果第一圈就用 `getline`，會直接讀到一個空字串，導致後面的資料可能會少讀或多讀一行。

### Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main2(){

    char alphabet[27];
    int abc[27] = { 0 };
    
    // 建立對照表 (注意：這裡如果 i 從 1 開始，A的ASCII是65，需寫成 'A' + i - 1)
    for (int i = 1; i < 27; i++) {
        alphabet[i] = 'A' + i - 1; 
    }
    
    // 這裡用 27 是因為要讀多行，建議還是先 cin >> round 後用 cin.ignore()
    for(int i = 0; i < 27; i++) {
        string txt;
        getline(cin, txt);
        for (int j = 0; j < txt.size(); j++) {
            if (txt[j] >= 'a' && txt[j] <= 'z') {
                abc[txt[j] - 'a' + 1]++;
            }
            else if (txt[j] >= 'A' && txt[j] <= 'Z') {
                abc[txt[j] - 'A' + 1]++;
            }
        }
    }

    for(int i = 0; i < 27; i++) {
        int max = 0;
        int nmax = 0;
        for (int j = 1; j <= 26; j++) {
            if (abc[j] > max) {
                max = abc[j];
                nmax = j;
            }
        }
        if (max == 0)break;
        cout << alphabet[nmax] << " " << max << endl;
        abc[nmax] = 0;
    }
    return 0;
}
```

**Why it works:**

- **ASCII 轉換：** 用 `txt[j] - 'A' + 1` 直接將字元轉換為陣列索引 (1~26)，取代了 26 行的 `if else`，程式碼瞬間變得簡潔且專業。
- **陣列輸出：** 利用 `alphabet` 陣列儲存字母，輸出時直接呼叫 `alphabet[nmax]`，同樣省去了 26 行的判斷式。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | 暴力列舉每一個字母的 `if else` | 利用 ASCII 碼計算相對距離對應陣列索引 |
| Edge Cases | 未特別處理 `cin` 後的換行符號 | 直接讀取所有字串並利用字元區間過濾雜訊 |
| Output Handling | 26個 `if else` 轉換數字回字母 | 建立對照陣列直接用索引印出字母 |
| Other | 程式碼極度冗長 | 程式碼簡潔、可讀性高 |

### Reflection

- **What mistake did you make?**
  初學時常因為不熟悉字元(char)底層其實是數字(ASCII)，而不敢對字元做加減運算。另外，在寫 AI 幫忙優化的第二版時，其實有一個小 Bug：`alphabet[i] = 'A' + i;` 會讓 `i=1` 的時候變成 'B' (65+1=66)，正確的寫法應該是 `'A' + i - 1` 或乾脆把陣列索引改從 0 開始存。
- **What did you learn from debugging this problem?**
  學到了字元是可以拿來做加減法的！只要是處理英文大小寫轉換、或是統計字母頻率，直接把字元當成數字減去基準點 (`'A'` 或 `'a'`)，是 C/C++ 裡面非常經典且必須掌握的技巧。
- **If you solve a similar problem again, what will you do better?**
  1. 陣列習慣從 `0` 開始用（0~25對應A~Z），這樣可以直接寫 `abc[txt[j] - 'a']++`，不用加 1，輸出時直接印 `(char)(nmax + 'A')`，連 `alphabet` 這個陣列都可以省下來，程式碼會更精簡。
  2. 解決 `cin >> round;` 的問題：我會記得在下一行補上 `cin.ignore();` 來吃掉換行符號，這樣後面的 `getline` 才不會亂掉。