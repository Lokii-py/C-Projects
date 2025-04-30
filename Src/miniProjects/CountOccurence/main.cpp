#include "header.h"
#include <iostream>
using namespace std;

int main(){
    int const SIZE = 8;
    int element[SIZE];
    for (int i = 0; i < 8; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> element[i];
    }
    
    int MaxElem = maxElement(element, SIZE);
    occurrences(element, SIZE, MaxElem);

    return 0;
}