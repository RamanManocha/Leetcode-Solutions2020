Recursive solution to sort a stack


Stack before sorting : 5 | -2 | 9 | -7 | 3    where 3 is the top element
Stack after sorting  : -7 | -2 | 3 | 5 | 9    where 9 is the top element





Algorithm 
We can use below algorithm to sort stack elements: 

sortStack(stack S)
    if stack is not empty:
        temp = pop(S);  
        sortStack(S); 
        sortedInsert(S, temp);
Below algorithm is to insert element is sorted order: 

sortedInsert(Stack S, element)
    if stack is empty OR element > top element
        push(S, elem)
    else
        temp = pop(S)
        sortedInsert(S, element)
        push(S, temp)
Illustration: 



Let given stack be
-3    <-- top of the stack
14
18
-5
30 
Let us illustrate sorting of stack using above example:
First pop all the elements from the stack and store poped element in variable ‘temp’. After poping all the elements function’s stack frame will look like:

temp = -3    --> stack frame #1
temp = 14    --> stack frame #2
temp = 18    --> stack frame #3
temp = -5    --> stack frame #4
temp = 30       --> stack frame #5
Now stack is empty and ‘insert_in_sorted_order()’ function is called and it inserts 30 (from stack frame #5) at the bottom of the stack. Now stack looks like below:

30    <-- top of the stack 
Now next element i.e. -5 (from stack frame #4) is picked. Since -5 < 30, -5 is inserted at the bottom of stack. Now stack becomes: 

30    <-- top of the stack
-5
Next 18 (from stack frame #3) is picked. Since 18 < 30, 18 is inserted below 30. Now stack becomes:

30    <-- top of the stack
18    
-5
Next 14 (from stack frame #2) is picked. Since 14 < 30 and 14 < 18, it is inserted below 18. Now stack becomes: 

30    <-- top of the stack
18
14    
-5
Now -3 (from stack frame #1) is picked, as -3 < 30 and -3 < 18 and -3 < 14, it is inserted below 14. Now stack becomes:

30    <-- top of the stack
18
14
-3    
-5
  
  
  

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
// Insert the given key into the sorted stack while maintaining its sorted order.
// This is similar to the recursive insertion sort routine
void sortedInsert(stack<int> &stack, int key)
{
    // base case: if the stack is empty or
    // the key is greater than all elements in the stack
    if (stack.empty() || key > stack.top())
    {
        stack.push(key);
        return;
    }
 
    /* We reach here when the key is smaller than the top element */
 
    // remove the top element
    int top = stack.top();
    stack.pop();
 
    // recur for the remaining elements in the stack
    sortedInsert(stack, key);
 
    // insert the popped element back into the stack
    stack.push(top);
}
 
// Recursive method to sort a stack
void sortstack(stack<int> &stack)
{
    // base case: stack is empty
    if (stack.empty()) {
        return;
    }
 
    // remove the top element
    int top = stack.top();
    stack.pop();
 
    // recur for the remaining elements in the stack
    sortstack(stack);
 
    // insert the popped element back into the sorted stack
    sortedInsert(stack, top);
}
 
void printStack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
 
int main()
{
    vector<int> list = { 5, -2, 9, -7, 3 };
 
    stack<int> stack;
    for (int i: list) {
        stack.push(i);
    }
 
    cout << "Stack before sorting: ";
    printStack(stack);
 
    sortstack(stack);
 
    cout << "Stack after sorting: ";
    printStack(stack);
 
    return 0;
}


