#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int array[15000] = {};
    int count = 1;

    while (cin >> array[count]) {

        int follow = count;
        while (array[follow] < array[follow - 1]) {
            int tmp = 0;
            tmp = array[follow];
            array[follow] = array[follow - 1];
            array[follow - 1] = tmp;
            follow--;
        }
        if (count == 1) {
            cout << array[count] << endl;
            count++;
           continue;
        }
        if (count % 2 == 0) {
            int numm = (array[count / 2] + array[count / 2 + 1]) / 2;
            cout << numm<<endl;
        }
        else {
            int numm = count / 2+1;
            cout << array[numm] << endl;
        }
        count++;
    }
    
}