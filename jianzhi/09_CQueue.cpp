/*
用两个栈实现一个队列。
队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead","deleteHead"]
[[],[3],[],[],[]]
输出：[null,null,3,-1,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
#include<iostream>
#include <stack>
using namespace std;

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stack_in.push(value);
    }
    
    int deleteHead() {
        if(stack_out.empty()){
            while(!stack_in.empty()){
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        if(stack_out.empty())
            return -1;
        int ret = stack_out.top();
        stack_out.pop();
        return ret;
    }
private:
    std::stack<int> stack_in;
    std::stack<int> stack_out;
};
int main(int argc, char *argv[])
{
    CQueue *obj = new CQueue;
    obj->appendTail(5);
    obj->deleteHead();
    obj->appendTail(4);
    obj->appendTail(3);
    obj->appendTail(2);
    obj->appendTail(1);
    for(int i = 0; i < 6; ++i)
    {
        std::cout << obj->deleteHead() << std::endl;
    }
    return 0;
}