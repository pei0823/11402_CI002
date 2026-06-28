# UVa 10359 - Tiling

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10359
- **Problem Title:** Tiling
- **Problem Link:** [UVa 10359 Tiling](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1300)
- **Source Code (Correct/Accepted):** [src/10359.cpp](./src/10359.cpp)

## 2. Problem Statement in My Own Words

- **Input:** 多組測資 $N$ ($0 \le N \le 250$)。
- **Output:** 用 $2 \times 1$ 和 $2 \times 2$ 的磚塊填滿 $2 \times N$ 牆面的方法數。
- **Logic:** - 最後擺一塊 $2 \times 1$ 磚：方法數 $f(N-1)$。
  - 最後擺兩塊 $2 \times 1$ 水平磚或一塊 $2 \times 2$ 磚：方法數 $2 \times f(N-2)$。



## 3. Correct Code (BigInt Approach)

```cpp
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// 使用 BigInt 類別處理大數運算
struct BigInt {
    vector<int> digits;
    BigInt(long long n = 0) {
        if (n == 0) digits.push_back(0);
        while (n > 0) { digits.push_back(n % 10000); n /= 10000; }
    }
    BigInt operator+(const BigInt& other) const {
        BigInt res; res.digits.clear();
        int carry = 0, n = max(digits.size(), other.digits.size());
        for (int i = 0; i < n || carry; ++i) {
            int sum = carry + (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0);
            res.digits.push_back(sum % 10000);
            carry = sum / 10000;
        }
        return res;
    }
    // 乘 2 運算
    BigInt mul2() const {
        BigInt res; res.digits.clear();
        int carry = 0;
        for (int d : digits) {
            int val = d * 2 + carry;
            res.digits.push_back(val % 10000);
            carry = val / 10000;
        }
        if (carry) res.digits.push_back(carry);
        return res;
    }
};

int main() {
    vector<BigInt> f(251);
    f[0] = BigInt(1);
    f[1] = BigInt(1);
    for (int i = 2; i <= 250; i++) f[i] = f[i - 1] + f[i - 2].mul2();

    int n;
    while (cin >> n) {
        const BigInt& res = f[n];
        cout << res.digits.back();
        for (int i = res.digits.size() - 2; i >= 0; i--)
            cout << setfill('0') << setw(4) << res.digits[i];
        cout << endl;
    }
    return 0;
}
```

## 4. Reflection

| Item | Assessment |
|---|---|
| Logic | $f(n) = f(n-1) + 2 \times f(n-2)$ |
| BigInt | 使用基數 10000 分段儲存 |
| Output | 使用 `setw(4)` 與 `setfill('0')` 解決補零問題 |

- **Mistake:** 原程式碼中 `if (arr[n][j] < 1000) cout << "0"` 的補零邏輯會因為判斷順序與位數限制而變得極其複雜。
- **Learned:** 在 C++ 中處理大數輸出補零，使用 `<iomanip>` 的 `setw` 和 `setfill` 是最標準且優雅的手段。
- **Future:** 看到需要計算大數的遞迴題目，若不想寫複雜的 `BigInt` 類別，可以考慮 Python，但若必須用 C++，預先寫好 `BigInt` 模板是比賽必備技能。