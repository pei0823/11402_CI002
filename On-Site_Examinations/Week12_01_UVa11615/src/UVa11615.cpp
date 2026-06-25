#include <iostream>
using namespace std;

int main()
{
    
    int n = 0;
    cin >> n;
    for (int nn = 0; nn < n; nn++) {
        int d, a, b;
        cin >> d >> a >> b;
        if (b > a)a = b;
        int tmp = 1;
        int tmpp = 2;
        for (int i = 2; i <= d; i++) {
            tmp += tmpp;
            tmpp *= 2;
        } //cout << tmp << endl;

        tmpp = 2;
        int gen = 1;
        while (tmpp < a) {
            gen++;
            tmpp *= 2;
        } //cout << gen << endl;

        int minus=0;
        tmpp = 2;
        for (int i = gen; i < d; i++) {
            minus += tmpp;
            tmpp *= 2;
        }
        cout <<  tmp-minus << endl;
        
    }
}