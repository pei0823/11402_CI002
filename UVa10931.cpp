#include <iostream>
using namespace std;

int main()
{
    while (true) {
        long long int num = 0;
        long long int binary = 1;
        long long int bicount = 1;
        long long int bi[100] = {};
        cin >> num;
        if (num == 0)
            break;
        
        while (num>= binary) {
            binary *= 2;
            bicount++;
        }
        if (binary >num ) {
            binary /= 2;
            bicount--;
        }
        
            
        
        long long int count = bicount;
        while (bicount != 0) {
            bi[bicount] = num / binary;
            num %= binary;
            binary /= 2;
            bicount--;
        }
        cout << "The parity of ";
        long long int countt = 0;
        for (int i = count; i > 0; i--) {
            cout << bi[i];
            if (bi[i] == 1)countt++;
        }cout << " is " << countt << " (mod 2)." << endl;;
        

    }
    
}