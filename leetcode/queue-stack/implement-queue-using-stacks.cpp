// https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>

using namespace std;

class MyQueue {
    stack<int> storage;

  public:
    MyQueue() {}

    void push(int x) {
        stack<int> temp;
        while (!storage.empty()) {
            temp.push(storage.top());
            storage.pop();
        }
        storage.push(x);
        while (!temp.empty()) {
            storage.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        int x = storage.top();
        storage.pop();
        return x;
    }

    int peek() { return storage.top(); }

    bool empty() { return storage.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() { return 0; }
