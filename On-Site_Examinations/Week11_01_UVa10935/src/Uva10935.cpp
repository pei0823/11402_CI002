#include <iostream>
#include <queue>
using namespace std;

int main()
{
    long long int n;
    int count = 0;
    while (cin >> n && n != 0 ) 
    {
        if (n < 0)break;
        //if (n > 50)break;
        queue<long long int> num = {};
        queue<long long int> dis = {};
        for (int i = 1; i <= n; i++) {
            num.push(i);
        }
        while (num.size() != 1) {
            dis.push(num.front()); 
            num.pop();
            num.push(num.front());
            num.pop();
        }
        cout << "Discarded cards:";
        if (dis.size() != 0) {
        cout <<" "<< dis.front();
        dis.pop();
        int nn = dis.size();
        for (int i = 0; i < nn; i++) {
            cout << ", "<<dis.front() ;
            dis.pop();
        }
        }
       
        cout << endl << "Remaining card: " << num.front()<<endl;
    }
    


    
}