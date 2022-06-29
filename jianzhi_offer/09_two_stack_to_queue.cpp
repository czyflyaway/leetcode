#include <iostream>
#include <stack>

using namespace std;
class CQueue
{
private:
    stack<int> sTail;
    stack<int> sHead;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        sTail.push(value);
    }

    int deleteHead()
    {
        if (sHead.empty())
        {
            while (!sTail.empty())
            {
                sHead.push(sTail.top());
                sTail.pop();
            }
        }
        if (sHead.empty())
        {
            return -1;
        }
        int ret = sHead.top();
        sHead.pop();
        return ret;
    }
};

int main(int argc, char *argv[])
{

    {
        CQueue *queue = new CQueue();
        cout << queue->deleteHead() << endl;
        queue->appendTail(3);
        cout << queue->deleteHead() << endl;
    }

    {
        CQueue *queue = new CQueue();
        queue->appendTail(3);
        cout << queue->deleteHead() << endl;
        cout << queue->deleteHead() << endl;
        queue->appendTail(5);
        queue->appendTail(4);
        queue->appendTail(3);
        queue->appendTail(2);
        queue->appendTail(1);
        cout << queue->deleteHead() << endl;
        cout << queue->deleteHead() << endl;
        cout << queue->deleteHead() << endl;
        cout << queue->deleteHead() << endl;
        cout << queue->deleteHead() << endl;
        cout << queue->deleteHead() << endl;
    }
    return 0;
}