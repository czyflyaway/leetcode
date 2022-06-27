#include <iostream>
using namespace std;

#define arr_len(arr) sizeof(arr) / sizeof(arr[0])

int binarySearch(int serachNum, int arr[], int len)
{
    if (0 == len)
        return -1;
    int left = 0;
    int right = len - 1;
    int mid = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == serachNum)
        {
            return mid;
        }
        else if (arr[mid] < serachNum)
        {
            left = mid + 1; 
        }
        else
        {
           right = mid - 1;
        }
    }
    return -1;
}

int search(int nums[], int size, int target) //nums是数组，size是数组的大小，target是需要查找的值
{
    int left = 0;
    int right = size - 1;	// 定义了target在左闭右闭的区间内，[left, right]
    while (left <= right) {	//当left == right时，区间[left, right]仍然有效
        int middle = left + ((right - left) / 2);//等同于 (left + right) / 2，防止溢出
        if (nums[middle] > target) {
            right = middle - 1;	//target在左区间，所以[left, middle - 1]
        } else if (nums[middle] < target) {
            left = middle + 1;	//target在右区间，所以[middle + 1, right]
        } else {	//既不在左边，也不在右边，那就是找到答案了
            return middle;
        }
    }
    //没有找到目标值
    return -1;
}

int main(int argc, char *argv[])
{
    // {
    //     int arr[] = {};
    //     int searchNum = 3;
    //     cout << "seach index:" << binarySearch(searchNum, arr, arr_len(arr)) << endl;
    // }
    // {
    //     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //     int searchNum = 3;
    //     cout << "seach index:" << binarySearch(searchNum, arr, arr_len(arr)) << endl;
    // }
    // {
    //     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //     int searchNum = 9;
    //     cout << "seach index:" << binarySearch(searchNum, arr, arr_len(arr)) << endl;
    // }
    {
        int arr[] = {-1,0,3,5,9,12};
        int searchNum =  2;
        cout << "seach index:" << search(arr, arr_len(arr), searchNum) << endl;
    }


    {
        int arr[] = {-1,0,3,5,9,12};
        int searchNum =  2;
        cout << "seach index:" << binarySearch(searchNum, arr, arr_len(arr)) << endl;
    }
    return 0;
}