#include <iostream>
#include <string>
using namespace std;


int main()
{
	int nnn;
	cin >> nnn;
	for (int nn = 1; nn <= nnn; nn++) {
		char nu, equ;
		int n;
		cin >> nu >> equ >> n;
		bool is = 1;
		long long int num[120][120] = {0};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> num[i][j];
				if(num[i][j]<0) { is = 0; break; }
			}
		}

		int x, y;
		float tt=(1+n)/2;
		if (n % 2 == 0)x = tt; y = tt + 1;
		if (n % 2 == 1)x = tt - 1; y = tt + 1;

			while (x!=1) {
				if (num[x][x] != num[y][y]) { is = 0; break; }
				int tmp = 0;
				while (tmp <= n - 1) {
					if (num[x + tmp][x] != num[y - tmp][y]) { is = 0; break; }
				}
				tmp = 0;
				while (tmp <= n - 1) {
					if (num[x][x + tmp] != num[y][y - tmp]) { is = 0; break; }
				}
				x -= 1;
				y += 1;
			}
		
		
		cout << "Test #" << nn << ": ";
		if (is = 0)cout << "Non-symmetric." << endl;
		else cout << "Symmetric." << endl;


	}




}
//11349