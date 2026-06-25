#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d, r;
    while (cin >> n >> d >> r) {
        if (n == 0 && d == 0 && r == 0) break;

        vector<int> morning(n), evening(n);
        for (int i = 0; i < n; i++) cin >> morning[i];
        for (int i = 0; i < n; i++) cin >> evening[i];

        sort(morning.begin(), morning.end());          
        sort(evening.begin(), evening.end(), greater<int>()); 

        long long total = 0;
        for (int i = 0; i < n; i++) {
            int sum = morning[i] + evening[i];
            if (sum > d) total += (sum - d) * r;
        }

        cout << total << endl;
    }
    return 0;
}