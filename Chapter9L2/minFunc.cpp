#include "minFunc.h"

const int * min(const int arr[], int arrSize) {
    if(arrSize == 0){
        return nullptr;
    }
    else if(arrSize == 1){
        return &arr[0];
    }
    else {
        return min(arr + (arr[arrSize - 1] < *arr), arrSize - 1);

        const int * test = min(arr, arrSize - 1); 
        
        if(arr[arrSize - 1] < *test) {
            return &arr[arrSize - 1]; 
        } 
        else {
            return test; 
        }
    }
}