#include <iostream>
#include <thread>
#include <semaphore.h>
#include <condition_variable>
#include <mutex>

using namespace std;
sem_t empty;
sem_t apple;
sem_t orange;

std::mutex _lock;
std::condition_variable _cv;
int _flag = 2;
void func(int num){
    for(int i = 0; i < 5; ++i){
        unique_lock<std::mutex> lk(_lock);
        _cv.wait(lk, [=](){ return _flag == num;});
        for(int j = 0; j < num; ++j){
            cout << j << "";
        }
        cout << endl;
        _flag = (2 == num) ? 20 : 2;
        _cv.notify_one();
    }
}

int _first = 0;
void printThreadId(int id){

    for(int i = 0; i < 10; ++i){
        unique_lock<std::mutex> lk(_lock);
        _cv.wait(lk, [=](){return id == _first;});
        cout << char('A' + id);
        _first = (_first + 1 ) % 3;
        _cv.notify_all();
    }
    
}
int main(int argc, char *argv[]){

    // {
    //     //子线程循环 10 次，接着主线程循环 100 次，接着又回到子线程循环 10 次，接着再回到主线程又循环 100 次，如此循环50次，试写出代码
    //     std::thread child(func, 2);
    //     func(20);
    //     child.join();
    //     return 0;
    // }
    {
        std::thread t1(printThreadId, 0);
        std::thread t2(printThreadId, 1);
        // std::thread t3(printThreadId, 2);
        printThreadId(2);
        t1.join();
        t2.join();
        cout << endl;
        return 0;
    }
    return 0;
}
