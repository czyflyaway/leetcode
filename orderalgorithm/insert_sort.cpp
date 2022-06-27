#include <iostream>
using namespace std;

#define arr_len(arr) sizeof(arr) / sizeof(arr[0])

void print(int arr[], int len){
    for(int i = 0; i < len - 1; ++i){
        cout << arr[i] << ",";
    }
    cout << arr[len - 1] << std::endl;
}
void swap(int &l, int &r){
    l = l ^ r;
    r = l ^ r;
    l = l ^ r;
}
void insert_sort(int arr[], int len){
    for(int i = 1; i < len; ++i){
        for(int j = i; j > 0; --j){
            if(arr[j] >= arr[j - 1]){//如果直接大于最后一个元素，直接跳出
                break;
            } else{//否则交换元素
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}
int main(int argc, char *argv[]){
    {
        int arr[] = {9, 8, 7 ,6, 5, 4, 3, 2, 1};
        print(arr, arr_len(arr));
        insert_sort(arr, arr_len(arr));
        print(arr, arr_len(arr));
    }
    return 0;
}