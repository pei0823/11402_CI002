// cola.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;


int main()
{
	int n=0;
	while (cin >> n) {
		int n1 = n;
		int n2 = n; n2 += 1;
		int n3 = n; n3 += 2;
		int num=n;
		int numplus=n;
		int numplusplus = n;
		int max=0;

		while (n1 >= 3) {
			num += n1 / 3;
			n1 = n1 / 3 + n1 % 3;
		}
		if (max < num)max = num;
		while (n2 >= 3) {
			numplus += n2 / 3;
			n2 = n2 / 3 + n2 % 3;
		}
		if (n2 < 1)numplus = 0;
		if (max < numplus)max = numplus;
		while (n3 >= 3) {
			numplusplus += n3 / 3;
			n3 = n3 / 3 + n3 % 3;
		}
		if (n3 < 2)numplusplus = 0;
		if (max < numplusplus)max = numplusplus;

		cout << max<< endl;
	}
}


