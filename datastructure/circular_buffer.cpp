#include <iostream>
using namespace std;
//size 必须为2的位数
template<typename T>
class CircularBuffer{
public:
    explicit CircularBuffer(int size){
        // _size = size &(size -1)//调整为2的倍数
        _size = size;
        _elements = new T[_size];
    }

    bool isFull(){
        return _end == (_start ^ _size);
    }
    bool isEmpty(){
        return _end == _start;
    }
    
    bool push(const T& val){
        if(isFull())
            return false;
        _elements[_end & (_size - 1)] = val;
        _end = increase(_end);
        return true;
    }
    bool pop(T& val){
        if(isEmpty()){
            return false;
        }
        val = _elements[_start & (_size - 1)];
        _start = increase(_start);
        return true;
    }
private:
    int increase(int p){
        return (p + 1) & (2 * _size - 1);
    }
private:
    int _size = 0;
    int _start = 0;
    int _end = 0;
    T *_elements =nullptr;
};

int main(int argc, char *argv[]){
    CircularBuffer<int> cbuffer(4);
    cout << "0:" << boolalpha << cbuffer.push(0) << endl;
    cout << "1:" << boolalpha << cbuffer.push(1) << endl;
    cout << "2:" << boolalpha << cbuffer.push(2) << endl;
    cout << "3:" << boolalpha << cbuffer.push(3) << endl;
    cout << "4:" << boolalpha << cbuffer.push(4) << endl;

    int val = 0;
    bool ret = cbuffer.pop(val);
    cout << "0:" << val << "," << boolalpha << ret << endl;
     ret = cbuffer.pop(val);
    cout << "1:" << val << "," << boolalpha << ret << endl;
     ret = cbuffer.pop(val);
    cout << "2:" << val << "," << boolalpha << ret << endl;
     ret = cbuffer.pop(val);
    cout << "3:" << val << "," << boolalpha << ret << endl;
     ret = cbuffer.pop(val);
    cout << "4:" << val << "," << boolalpha << ret << endl;
    return 0;
}
