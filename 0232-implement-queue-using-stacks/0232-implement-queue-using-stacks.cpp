#include <stack>

class MyQueue {
private:
    std::stack<int> s1; // Input stack
    std::stack<int> s2; // Output stack

   
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    MyQueue() {
        
    }
    
    
    void push(int x) {
        s1.push(x);
    }
    
    
    int pop() {
        if (s2.empty()) {
            transfer();
        }
        int front_element = s2.top();
        s2.pop();
        return front_element;
    }
    
    
    int peek() {
        if (s2.empty()) {
            transfer();
        }
        return s2.top();
    }
    
  
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

