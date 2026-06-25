#include <iostream>
#include <string>
using namespace std;
/*
0 1
1 1
2 3
3 5
4 11
5 21
6 43
7 85
8 171
9 341
10 683



*/

int main()
{
    long long int arr[251][40] = { 0 };
    arr[0][1] = 1;
    arr[1][1] = 1;
    arr[2][1] = 3;
    for (int i = 3; i <= 250; i++) {
        for (int j = 1; j <= 40; j++) {
            arr[i][j] = arr[i - 1][j] * 2;
        }
        if (i % 2 == 1)arr[i][1] -= 1;
        else arr[i][1] += 1;

        for (int j = 1; j <= 39; j++) {
            arr[i][j + 1] += arr[i][j] / 10000;
            arr[i][j] %= 10000;
        }

        /*for (int j = 10; j >= 1; j--) {
            if(arr[i][j]!=0)
             cout << arr[i][j];
        }cout << endl;*/

    }
    int n;
    while (cin >> n) {
        //cin >> n;

        for (int j = 20; j >= 1; j--) {
            if (arr[n][j] != 0) {

                if (arr[n][j + 1] != 0 || arr[n][j+2]!=0) {
                    if (arr[n][j] < 1000)cout << "0";
                    else if (arr[n][j] < 100)cout << "00";
                    else if (arr[n][j] < 10)cout << "000";
                    else if (arr[n][j] < 1)cout << "0000";
                    
                   
                }
                cout << arr[n][j];

            }
                
        }cout << endl;

    }

}