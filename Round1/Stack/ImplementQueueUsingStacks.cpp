/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, 
size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. 
You may simulate a stack by using a list or deque (double-ended queue), 
as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek 
operations will be called on an empty queue).
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (!stk_.empty()) {
            tmp.push(stk_.top());
            stk_.pop();
        }
        stk_.push(x);
        while(!tmp.empty()) {
            stk_.push(tmp.top());
            tmp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = stk_.top();
        stk_.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        return stk_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk_.empty();
    }

private:
    stack<int> stk_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
