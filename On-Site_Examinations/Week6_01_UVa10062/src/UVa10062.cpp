// UVa10062.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str)) {
        //int num[200] = {0};//?
        int ascii[300] = { 0 };
        for (int i = 0; i < str.size(); i++) {
            int x = (int)str[i];
            ascii[x]++;
        }
        //int i = 0;
        while (true) {
            int min = 10000;
            int num = 0;
            for (int i = 0; i < 300; i++) {
                if (ascii[i] <= min || ascii[i] != 0) {
                    min = ascii[i];
                    num = i;
                }
            }
            if (min == 10000)break;
            cout << num << " " << min << endl;
            ascii[num] = 0;

        }cout << endl;
        
   }
    
}
