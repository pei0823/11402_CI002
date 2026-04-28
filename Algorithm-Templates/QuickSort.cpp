#include <iostream>
#include <vector>

using namespace std;

// 交換兩個數字的函式
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 整理檔案：把小的放基準點左邊，大的放右邊
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 選最後一個當基準點
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 取得切開的位置
        int pi = partition(arr, low, high);

        // 分別對左邊跟右邊繼續做排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> data = {10, 7, 8, 9, 1, 5};
    
    quickSort(data, 0, data.size() - 1);
    
    cout << "排序後的結果：";
    for (int x : data) cout << x << " ";
    
    return 0;
}