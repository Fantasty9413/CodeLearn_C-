# include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if(stOut.empty())       // 输出栈为空，输入栈填充
        {
            while(!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();       // stOut出栈
        stOut.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        stOut.push(result);
        return result;
    }
    
    bool empty() {
        if(stIn.empty() && stOut.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};