#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
 
// helper class for runtime polymorphism demo below
struct B
{
    virtual ~B() = default;
 
    virtual void bar() { std::cout << "B::bar\n"; }
};
 
struct D : B
{
    D() { std::cout << "D::D\n"; }
    ~D() { std::cout << "D::~D\n"; }
 
    void bar() override { std::cout << "D::bar\n"; }
};
 
// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}
 
// helper function for the custom deleter demo below
void close_file(std::FILE* fp)
{
    std::fclose(fp);
}
 
// unique_ptr-based linked list demo
struct List
{
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;
    };
 
    std::unique_ptr<Node> head;
 
    ~List()
    {
        // destroy list nodes sequentially in a loop, the default destructor
        // would have invoked its `next`'s destructor recursively, which would
        // cause stack overflow for sufficiently large lists.
        while (head)
            head = std::move(head->next);
    }
 
    void push(int data)
    {
        head = std::unique_ptr<Node>(new Node{data, std::move(head)});
    }
};
 #include <sstream>

 std::string revertVersion(unsigned long version)
 {
    std::string strVersion;
    int v1 = (version & 0xff000000) >> 24;
    int v2 = (version & 0x00ff0000) >> 16;
    int v3 = (version & 0x0000ff00) >> 8;
    int v4 = version & 0x000000ff;
    std::stringstream ss;
    ss << v1 << "." << v2 << "." << v3 << "." << v4;
    return ss.str();
 }
 unsigned long versionArr[] = { };

 #include <thread>
 thread_local int g_n = 1;
 void f(){
    g_n++;
    printf("id=%d,  g_n=%d\n", std::this_thread::get_id(), g_n);
 }
 void foo(){
    thread_local int i = 0;
    printf("id=%d,  i=%d\n", std::this_thread::get_id(), i++);
 }
 void f2(){
    foo();
    foo();
 }

 #include <vector>

int main()
{
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        std::vector<int> vec1;
        vec1.swap(vec);

    }
    {
        g_n++;
        f();
        std::thread t1(f);
        std::thread t2(f);
        t1.join();
        t2.join();


        f2();
        std::thread t3(f2);
        std::thread t4(f2);
        t3.join();
        t4.join();

        return 0;
    }
    {
        for(auto version : versionArr){
            std::cout << version << "\t" << revertVersion(version) << std::endl;
        }
        return 0;
    }
    std::cout << "1) Unique ownership semantics demo\n";
    {
        // Create a (uniquely owned) resource
        std::unique_ptr<D> p = std::make_unique<D>();
 
        // Transfer ownership to `pass_through`,
        // which in turn transfers ownership back through the return value
        std::unique_ptr<D> q = pass_through(std::move(p));
 
        // `p` is now in a moved-from 'empty' state, equal to `nullptr`
        assert(!p);
    }
 
    std::cout << "\n" "2) Runtime polymorphism demo\n";
    {
        // Create a derived resource and point to it via base type
        std::unique_ptr<B> p = std::make_unique<D>();
 
        // Dynamic dispatch works as expected
        p->bar();
    }
 
    std::cout << "\n" "3) Custom deleter demo\n";
    std::ofstream("demo.txt") << 'x'; // prepare the file to read
    {
        using unique_file_t = std::unique_ptr<std::FILE, decltype(&close_file)>;
        unique_file_t fp(std::fopen("demo.txt", "r"), &close_file);
        if (fp)
            std::cout << char(std::fgetc(fp.get())) << '\n';
    } // `close_file()` called here (if `fp` is not null)
 
    std::cout << "\n" "4) Custom lambda-expression deleter and exception safety demo\n";
    try
    {
        std::unique_ptr<D, void(*)(D*)> p(new D, [](D* ptr)
        {
            std::cout << "destroying from a custom deleter...\n";
            delete ptr;
        });
 
        throw std::runtime_error(""); // `p` would leak here if it were instead a plain pointer
    }
    catch (const std::exception& e) { std::cout << "Caught exception:" << e.what() << std::endl;; }
 
    std::cout << "\n" "5) Array form of unique_ptr demo\n";
    {
        std::unique_ptr<D[]> p(new D[3]);
    } // `D::~D()` is called 3 times
 
    std::cout << "\n" "6) Linked list demo\n";
    {
        List wall;
        for (int beer = 0; beer != 1'000'000; ++beer)
            wall.push(beer);
 
        std::cout << "1'000'000 bottles of beer on the wall...\n";
    } // destroys all the beers
}