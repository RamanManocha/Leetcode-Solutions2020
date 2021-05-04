
155. Min Stack


155. Min Stack
Easy

4976

469

Add to List

Share
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2




class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> Min;
	
    MinStack(){
        
    }
    
    void push(int val) {
        s.push(val);
        if(Min.empty())
            Min.push(val);
        else Min.push(min(Min.top(),val));
    }
    
    void pop() {
        s.pop();
        Min.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return Min.top();
    }
};





2. Implicit Stack using STL Vector :-

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> v;
    vector<int> Min;
	
    MinStack() {
	
    }
    
    void push(int val) {
        v.push_back(val);
        if(Min.empty())
            Min.push_back(val);
        else Min.push_back(min(Min.back(),val));
    }
    
    void pop() {
        v.pop_back();
        Min.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return Min.back();
    }
};
3.) One-Liner Solution using pair<,>







class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<pair<int,int>> s;           //CAN USE A VECTOR AS WELL
    
    MinStack(){
        
    }
    
    void push(int val) {
        if(s.empty())
            s.push(pair(val,val));
        else
            s.push(pair(val,min(val,s.top().second)));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};


