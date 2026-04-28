// s1133341-UVa12503.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int turn;
	cin >> turn;
	for (int t = 0; t <turn;t++) {
		int num;
		int list[100] = {};
		cin >> num;
		string ord;
		int numm = 0;
		for (int i = 1; i <= num; i++) {
			cin >> ord;
			
			if (ord[0] == 'L') {
				numm--;
				list[i] = -1;
			}
			else if (ord[0] == 'R') {
				numm++;
				list[i] = 1;
			}
			else if (ord[0] == 'S') {
				string as;
				int n;
				cin >> as >> n;
				list[i] = list[n];
				numm += list[i];

			}
		}
		cout << numm << endl;
	}
}

