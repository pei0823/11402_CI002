#include <iostream>
#include <string>
using namespace std;
char alpha[27] = { 0,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//a49


int main()
{
    long long int n;
    while (true) {
        long long int num[50001];
        cin >> n;
        if (n == 0)break;
        cin >> num[0];
        for (int i = 1; i < n; i++) {
            cin >> num[i];
            long long int tmp = i;
            while (num[tmp] < num[tmp - 1] ) {
                if (tmp == 0)break;
                long long int mp=num[tmp];
                num[tmp] = num[tmp - 1];
                num[tmp - 1] = mp;
                tmp--;
            }
        }
        long long int sum=num[0];
        long long int bigsum=0;
        for (int i = 1; i < n; i++) {
            sum = sum + num[i];
            bigsum += sum;
        }
        cout << bigsum << endl;

    }
}//10954