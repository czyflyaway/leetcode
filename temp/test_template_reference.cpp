#include <type_traits>
#include <iostream>
using namespace std;
// template <typename T>
// void func_with_ponter(T* param){
//     cout << "i'm func_with_pointer\n";
//     using type = T;
//     std::cout <<"is int:" << std::boolalpha << std::is_integral<type>::value << std::endl;
//     std::cout <<"is pointer:" << std::boolalpha << std::is_pointer<type>::value << std::endl;
//     std::cout <<"is ref:" << std::boolalpha << std::is_reference<type>::value << std::endl;
// }
template<typename T>
void func_with_ref(T& param){
    cout << "i'm func_with_ref\n";
    using type = T;
    std::cout <<"is int:" << std::boolalpha << std::is_integral<type>::value << std::endl;
    std::cout <<"is pointer:" << std::boolalpha << std::is_pointer<type>::value << std::endl;
    std::cout <<"is ref:" << std::boolalpha << std::is_reference<type>::value << std::endl;
}
/*
    推导过程
    1、会忽略cv限定符
    2、忽略引用，但不忽略指针
    
*/
// template<typename T>
// void func_no_rp(T param){
//     cout << "i'm func_no_rp\n";
//     using type = T;
//     std::cout <<"is int:" << std::boolalpha << std::is_integral<type>::value << std::endl;
//     std::cout <<"is pointer:" << std::boolalpha << std::is_pointer<type>::value << std::endl;
//     std::cout <<"is ref:" << std::boolalpha << std::is_reference<type>::value << std::endl;
// }
int main(int argc, char *argv[]){
    std::cout << std::boolalpha << std::is_integral<int*>::value << std::endl;
    std::cout << std::boolalpha << std::is_integral<int>::value << std::endl;
    int x= 78;
    int &rx = x;
    const int cx = 100;
    const int &crx = x;

    //推导时会忽略掉实参的引用/指针类型
    //func_with_ref(x);//void func<int>(int&)
    //func_with_ref(rx);//void func<int>(int&)
    //func_with_ref(cx);//void func<int const>(int const&)
    //func_with_ref(crx);//void func<int const>(int const&)
    //func_with_ref(&cx);//当只有引用时，报错
    //func_with_ponter(&x);//void func_with_ponter<int>(int*)
    //func_with_ponter(&cx);//void func_with_ponter<int const>(int const*)

    //func_no_rp(x);//void func_no_rp<int>(int)
    //func_no_rp(rx);//void func_no_rp<int>(int)
    //func_no_rp(cx);//void func_no_rp<int>(int)
    //func_no_rp(crx);//void func_no_rp<int>(int)
    //func_no_rp(&x);//void func_no_rp<int*>(int*)
    //func_no_rp(&cx);//void func_no_rp<int const*>(int const*)
    //func_no_rp(&crx);//void func_no_rp<int const*>(int const*)
    // const int *px = &x;
    // func_no_rp(px);//void func_no_rp<int const*>(int const*)
    // const int * const py = &x;
    // func_no_rp(py);
    return 0;
}