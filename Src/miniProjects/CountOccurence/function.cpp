#include "header.h"
#include <iostream>
using namespace std;


int maxElement(int elements[], int size){
    int max = elements[0];
    for(int i = 0; i < size; i++){
        if(elements[i] > max){
            max = elements[i];
        }
    }
    return max;
}

void occurrences(int elements[], int size, int max){
    //dynamic memory allocation 
    int* result = new int[max + 1];
    
    for(int i = 0; i < size; i++){
        result[elements[i]] += 1;
    }

    for(int i = 0; i <= max; i++){
        cout << result[i];
        if(i != max){
            cout << ", "; 
        }
    }
}