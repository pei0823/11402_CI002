#include <iostream>
#include <string>
using namespace std;


int main()
{
	int x, y;
	int count = 1;
	while(cin >> x >> y && x!=0 &&y!=0){
		cout << "Field #" << count << ":" << endl;
		count++;
		int num[120][120] = {};
		
		for (int i = 1; i <= x; i++) {
			
			
			for (int j = 1; j <= y; j++) {
				char thing;
				cin >> thing;
				if (thing == '*')num[i][j] = -1;
				else if (thing == '.')num[i][j] = 0;
				//cout << thing << num[i][j] << endl;;
			}
		}


		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (num[i][j] == -1) {
					if(num[i - 1][j - 1]!=-1)num[i - 1][j - 1] += 1;
					if (num[i][j - 1] != -1)num[i][j - 1] += 1;
					if (num[i + 1][j - 1] != -1)num[i + 1][j - 1] += 1;
					if (num[i - 1][j] != -1)num[i - 1][j] += 1;
					if (num[i + 1][j] != -1)num[i + 1][j] += 1;
					if (num[i - 1][j + 1] != -1)num[i - 1][j + 1] += 1;
					if (num[i][j + 1] != -1)num[i][j + 1] += 1;
					if (num[i + 1][j + 1] != -1)num[i + 1][j + 1] += 1;
				}
			}
		}

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (num[i][j] == -1)cout << "*";
				else cout << num[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}



}
