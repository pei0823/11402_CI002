#include <iostream>
using namespace std;

int main()
{
    long long int num = 0;
    while (cin >> num) {
        if (num == 0)break;
        long long int count=0;
        for (int i = 0; i <= num; i++) {
            count += i * i;
        }
        cout << count << endl;
    }
}
