#include <iostream>
#include <vector>
using namespace std;

class Sort{
public:
    // O(n^2) O(1)
    static void select_sort(std::vector<int> &arr){
        int len = arr.size();
        int min = 0;
        
        for(int i = 0; i < len - 1; ++i){
            min = i;
            for(int j = i + 1; j < len; ++j){
                if(arr[min] > arr[j]){
                    min = j;
                }
            }
            if(min != i){
                swap(arr[min], arr[i]);
            }
        }
    }
    //选择排序优化
    //每次同时选择出最小值和最大值
    static void select_sort_1(std::vector<int> &arr){
        int len = arr.size();
        int min = 0;
        int max = len - 1;
        for(int left = 0, right = len - 1; left < right; ++left, --right){
            min = left;
            max = right;
            for(int k = left; k <= right; ++k){
                if(arr[k] < arr[min]){
                    min = k;
                } else if(arr[k] > arr[max]){
                    max = k;
                }
            }
            if(min == left && max == right){
                continue;
            }
            swap(arr[min], arr[left]);
            if(left == max){
                max = min;
            }
            swap(arr[max], arr[right]);
        }
    }
    //时间复杂度：n - 1 + n - 2 + ... + 1 = n(n - 1) / 2;
    //空间复杂度：O(1)
    static void bubble_sort(std::vector<int> &arr){
        int len = arr.size();
        for(int i  = 0; i < len - 1; ++i){
            for(int j = 0; j < len - 1 - i; ++j){
                if(arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    //冒泡排序优化，只要没有再交换过，就直接退出循环
    static void bubble_sort_1(std::vector<int> &arr){
        int len = arr.size();
        bool exchanged = true;
        for(int i  = 0; exchanged && (i < len - 1); ++i){
            exchanged = false;
            for(int j = 0; j < len - 1 - i; ++j){
                if(arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                    exchanged = true;
                }
            }
        }
    }
    //冒泡排序优化，只要没有再交换过，
    //记录上次交换的位置
    static void bubble_sort_2(std::vector<int> &arr){
        int len = arr.size();
        bool exchanged = true;
        int lastExchangePos = len - 1;
        int pos = 0;
        for(int i  = 0; exchanged && (i < len - 1); ++i){
            exchanged = false;
            for(int j = 0; j < lastExchangePos; ++j){
                if(arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                    exchanged = true;
                    pos = j;
                }
            }
            lastExchangePos = pos;
        }
    }

    static void insert_sort(std::vector<int> &arr){
        int len = arr.size();
        for(int i = 0; i < len - 1; ++i){
            for(int j = i + 1; j > 0; j --){
                if(arr[j] < arr[j - 1]){
                    swap(arr[j], arr[j- 1]);
                    break;
                }
            }
        }
    }
    static void insert_sort_1(std::vector<int> &arr){
        int len = arr.size();
        for(int i = 1; i < len; ++i){
            int j = i - 1;
            int key = arr[i];
            while(key < arr[j] && j >= 0){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    static void shellsort(std::vector<int> &arr){
        int len = arr.size();
        for(int gap = len / 2; gap > 0; gap /= 2){
            for(int i = 0; i < gap; ++i){
                for(int j = i + gap; j < len; j += gap){
                    int key = arr[j];
                    int preIndex = j -gap;
                    while(preIndex >= 0 && key < arr[preIndex]){
                        arr[preIndex + gap] = arr[preIndex];
                        preIndex -= gap;
                    }
                    arr[preIndex + gap] = key;
                }
                
            }
        }
    }

    static void adjust_heap(std::vector<int> &arr, int cur, int len){
        int temp = arr[cur];
        for(int k = 2 * cur + 1; k < len; ++k){
            if(k + 1 < len && arr[k] < arr[k + 1]){
                k = k + 1;
            }
            if(arr[k] > temp){
                arr[cur] = arr[k];
                cur = k;
            }
        }
        arr[cur] = temp;
    }
    static void heap_sort(std::vector<int> &arr){
        int len = arr.size();
        for(int i = len / 2; i >= 0; --i){
            adjust_heap(arr, i, len);
        }
        for(int i = len - 1; i >= 0; --i){
            swap(arr[0], arr[i]);
            adjust_heap(arr, 0, i);
        }
    }
    static void merge_sort_merge(std::vector<int> &arr, int left, int mid, int right, std::vector<int> &res){
        int i = left;
        int j = mid + 1;
        int t = left;
        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]){
                res[t++] = arr[i++];
            } else{
                res[t++] = arr[j++];
            }
        }
        while(i <= mid){
            res[t++] = arr[i++];
        }
        while(j <= right){
            res[t++] = arr[j++];
        }

        t = left;
        while(left <= right){
            arr[left++] = res[t++];
        }
    }
    static void merge_sort_internal(std::vector<int> &arr, int left, int right, std::vector<int>& res){
        if(left >= right){
            return;
        }
        int mid = left + right >> 1;

        merge_sort_internal(arr, left, mid, res);
        merge_sort_internal(arr, mid + 1, right, res);
        merge_sort_merge(arr, left, mid, right, res);
    }
    static void merge_sort(std::vector<int> &arr){
        std::vector<int> res(arr.size(), 0);
        merge_sort_internal(arr, 0, arr.size() - 1, res);
    }
    
    static void countSort(std::vector<int> &arr){
        int min = 0;
        int max = 0;
        int len = arr.size();
        for(int i = 0; i < len; ++i){
            if(arr[i] < arr[min]){
                min = i;
            }
            if(arr[i] > arr[max]){
                max = i;
            }
        }
        int range = arr[max] - arr[min] + 1;

        std::vector<int> count(range, 0);

        for(int i = 0; i < len; ++i){
            count[arr[i] - arr[min]]++;
        }
        for(int i = 1; i < range; ++i){
            count[i] += count[i - 1];
        }
        std::vector<int> output(len, 0);
        for(int i = len - 1; i >= 0; --i){
            output[count[arr[i] - arr[min]] - 1] = arr[i];
        }
        for(int i = 0; i < len; ++i){
            arr[i] = output[i];
        }
    }

    static void quick_sort(std::vector<int> &arr){
        return quick_sort_internal(arr, 0, arr.size() - 1);
    }


private:
    static void quick_sort_internal(std::vector<int> &arr, int front, int end){
        if(front < end){
            int pivot = partion(arr, front, end);
            quick_sort_internal(arr, front, pivot - 1);
            quick_sort_internal(arr, pivot + 1, end);
        }
    }   
    //从小到大
    // static int partion(std::vector<int> &arr, int front, int end){
    //     int pivot = arr[end];
    //     int i = front - 1;
    //     for(int j = front; j < end; ++j){
    //         if(arr[j] < pivot){
    //             i++;
    //             swap(arr[i], arr[j]);
    //         }
    //     }
    //     i++;
    //     swap(arr[i], arr[end]);
    //     return i;
    // }
    //从大到小
    static int partion(std::vector<int> &arr, int front, int end){
        int pivot = arr[end];
        int i = front - 1;
        for(int j = front; j < end; ++j){
            if(arr[j] > pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        i++;
        swap(arr[i], arr[end]);
        return i;
    }
private:
    static void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

};
void print(const std::vector<int> &arr){
    for(auto val : arr){
        std::cout << val << " ";
    }
    std::cout << endl;
}
int main(int argc, char *argv[]){
    std::vector<int> arr{4,9,1,6,7,3,8,2,5};
    print(arr);
    // Sort::select_sort(arr);
    // Sort::select_sort_1(arr);
    // Sort::bubble_sort(arr);
    // Sort::bubble_sort_1(arr);
    // Sort::bubble_sort_2(arr);
    // Sort::insert_sort(arr);
    // Sort::insert_sort_1(arr);
//    Sort::shellsort(arr); 
    // Sort::heap_sort(arr);
    // Sort::merge_sort(arr);
    // Sort::countSort(arr);

    Sort::quick_sort(arr);

    print(arr);
    return 0;
}
