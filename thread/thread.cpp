#include <thread>
#include <vector>
#include <mutex>
#include <stdarg.h>
#include <set>
#include <iostream>
using namespace std;

int time_count = 0;
// template <typename T>
// class container 
// {
//     mutable std::recursive_mutex _lock;
//     std::vector<T> _elements;
// public:
//     void add(T element) 
//     {
//         std::lock_guard<std::recursive_mutex> lk(_lock);
//         _elements.push_back(element);
//     }
 
//     void addrange(int num, ...)
//     {
//         va_list arguments;
 
//         va_start(arguments, num);
 
//         for (int i = 0; i < num; i++)
//         {
//             _lock.lock();
//             add(va_arg(arguments, T));
//             _lock.unlock();
//         }
 
//         va_end(arguments); 
//     }
 
//     void dump() const
//     {
//         std:lock_guard<std::recursive_mutex> lk(_lock);
//         for(auto e : _elements)
//             std::cout << e << std::endl;
//     }
// };
 
// void func(container<int>& cont)
// {

//     srand((unsigned int)time(0));
//     cont.addrange(3, rand(), rand(), rand());
// }

// int main()
// {
//     srand((unsigned int)time(0));
 
//     container<int> cont;
 
//     std::thread t1(func, std::ref(cont));
//     std::thread t2(func, std::ref(cont));
//     std::thread t3(func, std::ref(cont));
 
//     t1.join();
//     t2.join();
//     t3.join();
 
//     cont.dump();
 
//     return 0;
// }
 template <typename T>
class container 
{
public:
    std::mutex _lock;
    std::set<T> _elements;
 
    void add(T element) 
    {
        _elements.insert(element);
    }
 
    void remove(T element) 
    {
        _elements.erase(element);
    }
};
 
void exchange1(container<int>& cont1, container<int>& cont2, int value)
{  
    std::lock(cont1._lock, cont2._lock);
    cont1.remove(value);
    cont2.add(value);
 
    cont1._lock.unlock();
    cont2._lock.unlock();
}
int main()
{
    srand((unsigned int)time(NULL));
 
    container<int> cont1; 
    cont1.add(1);
    cont1.add(2);
    cont1.add(3);
 
    container<int> cont2; 
    cont2.add(4);
    cont2.add(5);
    cont2.add(6);
 
    std::thread t1(exchange1, std::ref(cont1), std::ref(cont2), 3);
    std::thread t2(exchange1, std::ref(cont2), std::ref(cont1), 6);
 
    t1.join();
    t2.join();
 
    return 0;
}


// void thread_1_func(){
//     cout << "thread_1_func\n";
// }
// void thread_2_func(int v){
//     v++;
//     cout << "thread_2_func:" << v << endl;
// }
// void thread_3_func(int v, int &rv){
//     rv++;
//     cout << "thread_3_func:" << v << "," << rv << endl;
// }
// int main(int argc, char *argv[]){
//     int v = 10;
//     int rv = 20;
//     std::thread thread_1(thread_1_func);
//     std::thread thread_2(thread_2_func, std::ref(v));
//     std::thread thread_3(thread_3_func, v, std::ref(rv));
    
//     thread_1.join();
//     thread_2.join();
//     thread_3.join();
//     cout << "v:" << v << endl;
//     cout << "rv:" << rv << endl;
//     return 0;
// }