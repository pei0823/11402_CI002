#include <iostream>
#include <string>
using namespace std;
char alpha[27] = { 0,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//a49


int main()
{
    string str1;
    string str2;
    while (getline(cin, str1)) {
        int a[27] = { 0 };
        getline(cin, str2);
        for (int i = 0; i < str1.size(); i++) {
            for (int j = 0; j < str2.size(); j++) {
                if (str1[i] == str2[j]) {
                    int tmp = str1[i]-'0'-48;
                    a[tmp]++;
                    str1[i] = '-1';
                    str2[j] = '0';
                }
            }
        }
        int tmp = 1;
        while (tmp != 27) {
            if (a[tmp] <= 0) {
                tmp++;
            }
            else {
                cout << alpha[tmp];
                a[tmp]--;
                tmp = 1;
            }
                
        }cout << endl;
        

    }
}//10252