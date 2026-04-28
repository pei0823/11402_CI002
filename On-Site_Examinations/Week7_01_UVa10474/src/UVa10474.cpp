// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;





int main()
{
    int n, q;
    int count = 1;
    while (true) {
        cin >> n >> q;
        if (n == 0 && q==0)break;
        int num[10000];
        cin >> num[1];
        for (int i = 2; i <= n; i++) {
            cin >> num[i];
            int tmp = i;
            while (num[tmp] < num[tmp-1]) {
                int t = num[tmp];
                num[tmp] = num[tmp-1];
                num[tmp-1] = t;
                tmp--;
                if (tmp == 1)break;
            }
        }
        cout << "CASE# " << count << ":" << endl; count++;
        for (int i = 1; i <= q; i++) {

            int numm;
            cin >> numm;

            int min = 1;
            int max = n;
            int tmp = (min + max) / 2;
            int cou = 0;
            if (numm == num[max] ) {
                tmp = max;
            }
            else if (numm == num[min]) {
                tmp = min;
            }
            else if (numm > num[max]) {
                tmp = 0;
            }
            else {
                while (numm != num[tmp]) {
                    if (numm < num[tmp]) {
                        max = tmp;
                    }
                    else if (numm > num[tmp]) {
                        min = tmp;
                    }
                    if (min == max) { tmp = 0; break; }
                    tmp = (min + max) / 2;
                    cou++;
                    if (max==min+1) {
                        tmp = 0; break;
                    }

                }
            }
            if (tmp != 0){
                while (num[tmp] == num[tmp - 1])tmp--;
            }
            

            if (tmp == 0) {
                cout << numm << " not found"<<endl;
            }
            else {
                cout << numm << " found at " << tmp << endl;
            }


        }



    }
}