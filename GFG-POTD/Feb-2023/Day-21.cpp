// Fill the Matrix

// Link - https://practice.geeksforgeeks.org/problems/2145720aebf8ea0b07f76b17217b3353a0fbea7f/1

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        int firstCorner = x-1+y-1;
        int secCorner = x-1+m-y;
        int thirdCorner = n-x+y-1;
        int fourthCorner = n-x+m-y;
        
        return max(max(firstCorner, secCorner), max(thirdCorner, fourthCorner));
    }
};
