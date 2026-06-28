# UVa 12250 - Language Detection

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 12250
- **Problem Title:** Language Detection
- **Problem Link:** [UVa 12250 Language Detection](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3402)
- **Source Code (Correct/Accepted):** [src/12250.cpp](./src/12250.cpp)

## 2. Problem Statement in My Own Words

- **Input:** 多組測試資料，每組包含一個字串。當輸入為 `#` 時結束。
- **Output:** 根據輸入的問候語，輸出對應的語言。若不在已知清單中，輸出 `UNKNOWN`。
- **Rules:** 必須嚴格對照題目指定的問候語與語言對應表。

## 3. Thinking Logic and Strategy

### Strategy
使用 `if-else` 或 `map` 資料結構進行字串比對。由於語言種類固定且數量少，使用 `if-else` 是最直觀且高效的作法。

## 4. Pseudocode

```text
START
1. Initialize count = 1.
2. Loop continuously:
   a. Read string `in`.
   b. If `in` == "#", BREAK.
   c. Print "Case " + count + ": ".
   d. If `in` matches specific greeting, print language. Else, print "UNKNOWN".
   e. Increment count.
END
```

## 5. Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string in;
    int count = 1;
    while (cin >> in && in != "#") {
        cout << "Case " << count++ << ": ";
        
        if (in == "HELLO") cout << "ENGLISH" << endl;
        else if (in == "HOLA") cout << "SPANISH" << endl;
        else if (in == "HALLO") cout << "GERMAN" << endl;
        else if (in == "BONJOUR") cout << "FRENCH" << endl;
        else if (in == "CIAO") cout << "ITALIAN" << endl;
        else if (in == "ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
        else cout << "UNKNOWN" << endl;
    }
    return 0;
}
```

## 6. Reflection

| Item | Assessment |
|---|---|
| Logic | 簡單直接的字串比對 |
| Efficiency | $O(1)$ 常數級別比對 |
| Formatting | 修正了輸出格式，確保每行一個 Case |

- **Mistake:** 原程式碼中的 `if (count != 1) cout << endl;` 是多餘的，這在題目沒有要求兩組測資之間空行時，會導致格式錯誤。
- **Learned:** 觀察題目輸出範例，如果沒有明確寫出「兩組測資之間要空一行」，就絕對不要自己加 `endl`。
- **Future:** 寫這類簡單比對題目時，保持輸出格式的單純性最重要。