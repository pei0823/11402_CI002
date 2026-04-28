#include<iostream>
using namespace std;

int main(){
    string a,b;
    int dp[101][101];  
    while(cin>>a>>b){
        int n = a.length();
        int m = b.length();

        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << dp[n][m] << endl;
     
    }
}