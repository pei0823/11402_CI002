#include <iostream>
#include <string>
using namespace std;


int main()
{
    int cas=0;
    cin >> cas;
    cin.ignore();
    for (int cass = 1; cass <= cas; cass++) {
        
        string gro;
        int n;
        cin >> n; cin.ignore();
        getline(cin, gro);
        //cout << gro;
        int tmp = 0;
        int sum = 0;
        while (true) {
            if (tmp > gro.size())break;
            if (gro[tmp] == '.') {
                sum++;
                if(tmp+1<=gro.size())gro[tmp + 1] = '#'; 
                if (tmp + 2 <= gro.size())gro[tmp + 2] = '#';
            }
            tmp++;
            
        }
        cout << "Case " << cass << ": "; 
        cout << sum<<endl;


    }

}//12405