// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    int count = 1;
    while (cin >> n) {
        int num[10000];
        int sum[10000];
        int sumcount=1;
        int boool = 1;
        cin >> num[1];
        for (int i = 2; i <= n; i++) {
            cin >> num[i];
            if (num[i] <= 0 || num[i] == num[i - 1] ) {
                boool = 0;
                break;
            }else 
            for (int j = 1; j <= i; j++) {
                sum[sumcount] = num[i] + num[j];
                int tmp = j;
                while (sum[tmp] < sum[tmp - 1]) {
                    int t = sum[tmp];
                    sum[tmp] = num[tmp - 1];
                    sum[tmp - 1] = t;
                    tmp--;
                    if (tmp == 1)break;
                }
                if (sum[tmp] == sum[tmp - 1]) {
                    boool = 0;
                    break;
                }
            }
           


        }
    if (boool == 0) {
                cout << "Case #"<<count<<": It is not a B2 - Sequence."<<endl;
            }
            if (boool == 1) {
                cout << "Case #" << count << ": It is a B2 - Sequence."<<endl;
            }
            count++;
    }
       

}