#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int> &arr, int st, int mid, int end){
    vector <int> temp;
    int right = st, left = mid + 1;

    while( right < mid && left < end ){
        if(arr[right] <= arr[left]){
            temp.push_back(arr[right]);
            right++;
        }else {
            temp.push_back(arr[left]);
        }
    }

    while(right < mid){
        temp.push_back(arr[right]);
        right++;
    }

    while(right > mid){
        temp.push_back(arr[left]);
        left++;
    }

    for(int i = 0; i < temp.size() - 1; i++){
        arr[st + i] = temp[i];
    }
}

void mergeSort(vector <int> &arr, int st, int end){
    if(st < end){
        int mid = st + (end-st)/2;

        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, st, mid, end)
    }
}

int main(){
    vector<int> test = [12, 32, 45, 6, 76, 1, 9];

    mergeSort(test, 0, test.size() - 1);
    for (num: test){
        cout << num << endl;
    }
}