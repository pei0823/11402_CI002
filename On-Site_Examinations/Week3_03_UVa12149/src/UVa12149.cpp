// 12149.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
 //

#include <iostream>
using namespace std;

int main()
{
    long long int num = 0;
    while (cin >> num) {
        if (num == 0)break;
        long long int count=0;
        for (int i = 0; i <= num; i++) {
            count += i * i;
        }
        cout << count << endl;
    }
}
