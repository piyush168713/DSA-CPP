/*

Max Rectangle (GFG)

Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. 
The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the 
size of the matrix M. 

*/

class Solution{
private:

vector<int> nextSmallerElement(int* arr, int n)
    {
    stack<int> s;
    s.push(-1);
    // answer array
    vector<int> ans(n);
    
    for(int i = n-1; i>=0; i--)
    {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // if you get out from while loop, means ans is s.top()
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
 }

 vector<int> prevSmallerElement(int* arr, int n)
 {
    stack<int> s;
    s.push(-1);
    // answer array
    vector<int> ans(n);
    
    for(int i = 0;i<n; i++)
    {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // if you get out from while loop, means ans is s.top()
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
 }


int largestRectangle(int* heights, int n) {
   // Write your code here.
    //int n = heights.size();
     
     vector<int> next(n);
     next = nextSmallerElement(heights, n);
     
     vector<int> prev(n);
     prev = prevSmallerElement(heights, n);
     int area = 0;
     
     for(int i = 0; i<n; i++)
     {
         int l = heights[i];
         if(next[i] == -1){
             next[i] = n;
         }
         int b = next[i] - prev[i] - 1;
         int newArea = l*b;
         area = max(area, newArea);
     }
     return area;
 }
 
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area = largestRectangle(M[0], m);
        
        // for remaining row
        for(int i = 1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                
                // row update: by adding previous row's value
                if(M[i][j] != 0)
                M[i][j] = M[i][j] + M[i-1][j];
                else
                M[i][j] = 0;
                
            }
            
            // entire row is updated now
            area = max(area, largestRectangle(M[i], m));
        }
        return area;
    }
};
