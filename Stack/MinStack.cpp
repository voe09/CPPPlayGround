/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (min_val_.empty()) {
            min_val_.push_back(x);
        } else {
            min_val_.push_back(min(min_val_.back(), x));
        }
        stk_.push_back(x);
    }
    
    void pop() {
        min_val_.pop_back();
        stk_.pop_back();
    }
    
    int top() {
        return stk_.back();
    }
    
    int getMin() {
        return min_val_.back();
    }
    
public:
    vector<int> min_val_;
    vector<int> stk_;
};
