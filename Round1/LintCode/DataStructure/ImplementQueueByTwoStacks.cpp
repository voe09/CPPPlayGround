/*
As the title described, you should only use two stacks to implement a queue's actions.

The queue should support push(element), pop() and top() where pop is pop 
the first(a.k.a front) element in the queue.

Both pop and top methods should return the value of first element.

Have you met this question in a real interview? Yes
Example
push(1)
pop()     // return 1
push(2)
push(3)
top()     // return 2
pop()     // return 2
Challenge 
implement it by two stacks, do not use any other data structure and push, 
pop and top should be O(1) by AVERAGE.
 */

class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        new_.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        ShiftStack();
        int tmp = old_.top();
        old_.pop();
        return tmp;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        ShiftStack();
        return old_.top();
    }

private:
    void ShiftStack() {
        if (old_.empty()) {
            while (!new_.empty()) {
                old_.push(new_.top());
                new_.pop();
            }
        }
    }

private:
    stack<int> new_, old_;
};
