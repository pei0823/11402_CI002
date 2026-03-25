#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int runtime = 1; runtime <= num; runtime++)
    {
        int fir, sec;
        cin >> fir >> sec;
        int num = 0;
        if (fir == sec) {
            cout << "Case " << runtime << ": " << num << endl;
            continue;
        }
         
        if (fir % 2 == 0)fir++;
        num += fir;

        for (int i = 0; i < 100; i++) {
            fir += 2;
            if (fir > sec) break;
            num += fir;
            if (fir == sec)break;
            
            
            //cout << fir << endl;
        }
        cout << "Case " << runtime << ": " << num << endl;
    }
}