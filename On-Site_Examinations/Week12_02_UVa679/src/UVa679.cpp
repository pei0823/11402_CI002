// UVa679.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
#include <iostream>
using namespace std;

int main()
{
    
    int n = 0;
    while (cin >> n && n != -1) {

    
    for (int nn = 0; nn < n; nn++) {
        int d, a;
        cin >> d >> a ;
        
       
        int tmp = 2;
        int gen = 1;
        int start=1, end=1;
        

        for (int i = 1; i < d; i++) {
            start *= 2;
        }
        end = start * 2 - 1;
        //cout << start <<" "<< end << endl;
        int mid=(start + end) / 2;
        int out;
        if (a % 2 == 0) {
            mid += a / 2;
            out = mid;
        }
        else if (a % 2 == 1) {
            start += a / 2;
            out = start;
        }
        cout << out<<endl;
 
    }
    }
}
