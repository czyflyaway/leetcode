/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

提示：

各函数的调用总次数不超过 20000 次
*/

#include <iostream>
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stack_normal.push(x);
        if(stack_min.empty() || stack_min.top() >= x){
            stack_min.push(x);
        }
    }
    
    void pop() {
        int top = stack_normal.top();
        stack_normal.pop();
        if(top == stack_min.top()){
            stack_min.pop();
        }
    }
    
    int top() {
        return stack_normal.top();
    }
    
    int min() {
        return stack_min.top();
    }
    private:
    std::stack<int> stack_normal;
    std::stack<int> stack_min;
};

int main(int argc, char *argv[]){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.min() << std::endl; 
    minStack.pop();
    std::cout << minStack.top() << std::endl;
    std::cout << minStack.min() << std::endl;
    return 0;
}