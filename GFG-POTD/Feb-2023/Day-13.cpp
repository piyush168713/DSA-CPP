// Arithmetic Number

// Link- https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        if(C == 0) return A==B;
        return (B-A)%C==0 && (B-A)/C>=0;
    }
};
