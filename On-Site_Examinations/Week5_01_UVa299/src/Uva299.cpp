#include <iostream>
using namespace std;

int main()
{
    int round = 0;
    cin >> round;
    for (int rounds = 0; rounds < round; rounds++) {
        int tcase = 0;
        cin >> tcase;
        if (tcase == 0) {
            cout<< "Optimal train swapping takes 0 swaps." << endl;
            continue;
        }
        int count = 0;
        int train[100] = {};
        for (int j = 1; j <= tcase; j++) {
            cin >> train[j];
        }
        int n = 1;
        while (n != tcase) {
            if (train[n] > train[n+1]) {// !
                int nn = train[n + 1];
                train[n + 1] = train[n];
                train[n] = nn;
                count++;
                n = 1;
            }
            else n++;
        }
        cout << "Optimal train swapping takes "<<count<<" swaps."<<endl;
    }
    
}
