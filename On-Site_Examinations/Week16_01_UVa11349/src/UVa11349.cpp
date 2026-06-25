#include <iostream>
using namespace std;

int main()
{
    int co;
    cin >> co;
    for (int count = 1; count <= co; count++) {
        bool sym = 1;
        long long int num[101][101];
        int n;
        char nn, equ;
        cin >> nn >> equ >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> num[i][j];
                if (num[i][j] <= -1) sym = 0;
            }
        }
        int x = 1;
        int y = n;
        if (n % 2 == 0) {
            x = n / 2;
            y = n / 2 + 1;
        }
        else {
            x = n / 2;
            y = n / 2 + 2;
        }
        while (x != 0) {
            for (int i = 0; i <= y-x; i++) {
                if (num[x+i][x] != num[y - i][y])sym = 0;
            }
            for (int i = 0; i <= y-x; i++) {
                if (num[x][x+i] != num[y][y - i])sym = 0;
            }
            x--;
            y++;
        }
        cout << "Test #" << count << ": ";
        if (sym == 0)cout << "Non-symmetric." << endl;
        else cout << "Symmetric." << endl;
    }
}
