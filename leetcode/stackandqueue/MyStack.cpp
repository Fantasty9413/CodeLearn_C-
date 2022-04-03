# include <iostream>
# include <queue>
using namespace std;

class MyStack {
public:
    queue<int> que;

    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int len = que.size();
        while(len > 1)
        {
            this->push(que.front());
            que.pop();
            len--;
        }
        int result = que.front();
        que.pop();
        return result;
    }
    
    int top() {
        int len = que.size();
        while(len > 1)
        {
            this->push(que.front());
            que.pop();
            len--;
        }
        int result = que.front();
        this->push(result);
        que.pop();
        return result;                
    }
    
    bool empty() {
        return que.empty();
    }
};