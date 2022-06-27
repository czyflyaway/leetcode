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
void select_sort(int arr[], int len){
    
    for(int i = 0; i < len - 1; ++i){
        int minIndex = i;
        for(int j = i + 1; j < len; ++j)
        {
            if(arr[j] < arr[minIndex]){

                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
//双向选择排序(每次找出最大值和最小值)
void select_sort_2(int arr[], int len){

    int low = 0;
    int high = len - 1;
    while(low <= high){
        int min = low;
        int max = high;
        for(int i = low; low <= high; ++i){
            if(arr[i] < arr[min]){
                min = i;
            }
            if(arr[i] > arr[max]){
                max = i;
            }
        }
        swap(arr[low], arr[min]);
        if(max == low){
            max = min;
        }
        swap(arr[high], arr[max]);
        cout << "low, high" <<low <<"," << high << "\t:\t";
        low++;
        high--;

        print(arr, len);
    }
}
int main(int argc, char *argv[]){
    {
        int arr[] = {9, 8, 7 ,6, 5, 4, 3, 2, 1};
        print(arr, arr_len(arr));
        select_sort(arr, arr_len(arr));
        print(arr, arr_len(arr));
    }
    {
        int arr[] = {9, 8, 7 ,6, 5, 4, 3, 2, 1};
        print(arr, arr_len(arr));
        select_sort_2(arr, arr_len(arr));
        print(arr, arr_len(arr));
    }
    return 0;
}