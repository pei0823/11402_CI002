#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    /*stack<int> num;
    num.push(10);
    num.pop();
    num.top();*/
    
    int n;
    cin >> n;
    int count = 0;
    cin.ignore();
    for(int nn=0;nn<n;nn++){
        stack<char> num;
        count++;
        string str = {};
        
        getline(cin, str);
        int boool = 1;
      

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[')
                num.push(str[i]);
            else if (str[i] == ')') {
                if (num.size() == 0) {
                   
                    boool = 0;
                    break;
                }
                if (num.top() == '(') {
                    
                    num.pop();
                    
                }
                    
                else {
                    
                    boool = 0;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (num.size() == 0) {
                    boool = 0;
                    
                    break;
                }
                if (num.top() == '[') {
                   
                    num.pop();
                }
                else {
                    boool = 0;
                    
                    break;
                }
            }
        }
        if (num.empty() && boool==1)cout << "Yes" << endl;

        else if(!num.empty() || boool == 0)cout << "No" << endl;
    }
    
    
    
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
