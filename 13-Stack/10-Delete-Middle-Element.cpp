// Delete middle element from stack (CodeStudio)

// Problem Statement

// You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.
// A stack is a linear data structure where both insertion and deletion of elements take place at the top. 
// It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, 
// where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, 
// on the top of the stack only.


// Sample Input 1:
// 2  - No. of test case
// 4  - No of elements
// 1 2 3 4 5
// 7  - No. of elements
// 83 74 67 49 94 8 11 1

// Sample Output 1:
// 1 2 4 5
// 83 74 67 94 8 11 1

void solve(stack<int>&inputStack, int count, int size)
{
    if(count == size/2)
    {
        inputStack.pop();
        return ;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
    // Recursive call
    solve(inputStack, count+1, size);
    
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N)
{
	
    int count = 0;
    solve(inputStack, count, N);
}

