// https://leetcode.com/problems/min-stack/

#include <algorithm>
#include <stack>

using namespace std;

class MinStack {
    stack<int> items;
    stack<int> mins;

  public:
    MinStack() { mins.push(numeric_limits<int>::max()); }

    void push(int val) {
        items.push(val);
        mins.push(min(mins.top(), val));
    }

    void pop() {
        items.pop();
        mins.pop();
    }

    int top() { return items.top(); }

    int getMin() { return mins.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() { return 0; }
