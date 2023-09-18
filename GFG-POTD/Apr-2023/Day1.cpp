// Make Array Elements Equal

// Link - https://practice.geeksforgeeks.org/problems/1f05c7c12b1084f270c57566b2110967c046730d/1

class Solution {
  public:
    long long int minOperations(int N) {
        // Code here
        int mid = N/2;
        
        return N%2==0?(long)mid*(long)mid:(long)mid*(long)(mid+1);
    }
};
