// 10783.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;

int main()
{
    long long int s=0, d=0;
    while (cin >> s >> d) { 
        long long int count=0;
        while (count < d) {
            count += s;
            
            if (count >= d) {
                cout << s<<endl;
                break;

            }
            s++;
        }
        
    }
}