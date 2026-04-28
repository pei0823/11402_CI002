#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        // 找到中間的位置
        int mid = left + (right - left) / 2;

        // 如果中間那個剛好就是我們要找的
        if (arr[mid] == target) {
            return mid;
        }

        // 如果中間的數字太小，往右邊找
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // 如果中間的數字太大，往左邊找
        else {
            right = mid - 1;
        }
    }

    // 找不到就回傳 -1
    return -1;
}

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    
    int result = binarySearch(data, target);
    
    if (result != -1)
        cout << "找到了！索引位置在：" << result << endl;
    else
        cout << "抱歉，沒找到..." << endl;
        
    return 0;
}