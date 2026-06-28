#include <iostream>
#include <stack>
using namespace std;


int main()
{
    int d, n;
    while (true) {
        cin >> d>> n;
        if (d == 0 && n == 0)break;
        int dra[30000];
        int loow[30000];
        for (int i = 1; i <= d; i++) {
            cin>>dra[i];
            int tmp = i;
            while (dra[tmp] < dra[tmp - 1]) {
                if (tmp == 1)break;
                int tmpp = dra[tmp];
                dra[tmp] = dra[tmp - 1];
                dra[tmp - 1] = tmpp;
                tmp--;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> loow[i];
            int tmp = i;
            while (loow[tmp] < loow[tmp - 1]) {
                if (tmp == 1)break;
                int tmpp = loow[tmp];
                loow[tmp] = loow[tmp - 1];
                loow[tmp - 1] = tmpp;
                tmp--;
            }
        }
        int dracou = 1;
        int loowcou = 1;
        int loowsum=0;
        while (true) {
            if (dracou == d+1 || loowcou == n+1)break;
            if (dra[dracou] > loow[loowcou]) {
                //loowsum += loow[loowcou];
                loowcou++;
            }else if (dra[dracou] <= loow[loowcou]) {
                loowsum += loow[loowcou];
                dracou++;
                loowcou++;
            }
        }
        if (dracou == d + 1 && loowcou <= n + 1)cout << loowsum << endl;
        else if (dracou < d + 1 && loowcou == n + 1)cout << "Loowater is doomed!" << endl;
        else if (dracou == d + 1 && loowcou == n + 1)cout << "Loowater is doomed!" << endl;

    }
}//11292