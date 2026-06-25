#include <iostream>
#include <string>
using namespace std;
char alpha[27] = { 0,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//a49


int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int dou = 0; dou < n; dou++) {
		int num[1000];
		string str;
		getline(cin, str);
		int sum=0;
		int count = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ') {
				int tmp = str[i]-'0';
				sum *= 10;
				sum += tmp;
			}
			else {
				num[count] = sum;
				sum = 0;
				
				int tmp = count;
				count++;
				while (num[tmp] < num[tmp - 1]) {
					if (tmp == 0)break;
					long long int mp = num[tmp];
					num[tmp] = num[tmp - 1];
					num[tmp - 1] = mp;
					tmp--;
				}
			}
		}
		num[count] = sum;
		sum = 0;
		int tmp = count;
		count++;
		
		while (num[tmp] < num[tmp - 1]) {
			if (tmp == 0)break;
			long long int mp = num[tmp];
			num[tmp] = num[tmp - 1];
			num[tmp - 1] = mp;
			tmp--;
		}
		int mid = 0;
		//int bigsum = 0;
		if (count % 2 == 1) {
			mid = (count+1) / 2;
			for (int i = 0; i < count;i++) {
				if (num[i] < num[mid])
					sum += num[mid] - num[i];
				else
					sum += num[i] - num[mid];
			}
		}
		else if (count % 2 == 0) {
			int firsum = 0;
			int secsum = 0;
			mid = count / 2;
			for (int i = 0; i < count; i++) {
				if (num[i] < num[mid])
					firsum += num[mid] - num[i];
				else
					firsum += num[i] - num[mid];
			}
			mid--;
			for (int i = 0; i < count; i++) {
				if (num[i] < num[mid])
					secsum += num[mid] - num[i];
				else
					secsum += num[i] - num[mid];
			}
			if (firsum > secsum)sum = secsum;
			else sum = firsum;
		}

		cout << sum<<endl;


	}


}

