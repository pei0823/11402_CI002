#include <iostream>
using namespace std;

int main()
{
	int  people, budget, hotelnum, weeknum;
	while (cin >> people >> budget >> hotelnum >> weeknum) {
		int price, bednum;
		int final = 5000000;//6
		for (int i = 0; i < hotelnum; i++) {
			cin >> price;
			for (int j = 0; j < weeknum; j++) {
				cin >> bednum;
				if (bednum > people) {
					int tmp = price * people;
					if (tmp < budget && final>tmp) {
						final = tmp;
						
					}
				}
			}
		}
		if (final == 5000000)cout << "stay home" << endl;
		else
		cout << final<<endl;
	}
}

