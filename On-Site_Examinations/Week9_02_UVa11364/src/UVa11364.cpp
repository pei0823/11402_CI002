// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;

int main()
{
	int ttt;
	cin >> ttt;
	for (int m = 0; m < ttt; m++) {
		int num[10000];
		int n;
		cin >> n;
		
		int min = 10000;int max = 0;
		for (int i = 0; i < n; i++) {
			int nn = 0;
			cin >> nn;
			if (nn < min)min = nn;
			if (nn > max)max = nn;
		}
		int sum = 2*(max - min);
		cout << sum << endl; ;

	}
}