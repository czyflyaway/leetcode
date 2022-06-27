#include <iostream>
using namespace std;

#define arr_len(arr) sizeof(arr) / sizeof(arr[0])

void print(int arr[], int len){
    for(int i = 0; i < len - 1; ++i){
        cout << arr[i] << ",";
    }
    cout << arr[len - 1] << std::endl;
}
//
void bubble_sort(int arr[], int len){
    for(int i = 0; i < len - 1; ++i){
        for(int j = 0; j < len - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
                arr[j]      = arr[j] + arr[j + 1];
                arr[j + 1]  = arr[j] - arr[j + 1];
                arr[j]      = arr[j] - arr[j + 1];
            }
        }
    }
}
int main(int argc, char *argv[]){
    {
        int arr[] = {9, 8, 7 ,6, 5, 4, 3, 2, 1};
        print(arr, arr_len(arr));
        bubble_sort(arr, arr_len(arr));
        print(arr, arr_len(arr));
    }
    return 0;
}