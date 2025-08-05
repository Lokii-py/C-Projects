#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> arr, int st, int end){
    int idx = st - 1, pivot = end;

    for(int i = 0; i < end; i++){
        if(arr[i] < arr[pivot]){
            idx++;
            swap(arr[i], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);
    return idx;

}

void quickSort(vector<int>& arr, int st, int end){
    if(st < end){
        int pivotIdx = partition(arr, st, end);
        quickSort(arr, st, pivotIdx - 1); // left Half
        quickSort(arr, pivotIdx + 1, end); // right Half
    }

}

int main(){
    vector<int> test = {12, 32, 45, 6, 76, 1, 9};

    quickSort(test, 0, test.size() - 1);
    for (int num: test){
        cout << num <<  " ";
    }
    cout << endl;
}