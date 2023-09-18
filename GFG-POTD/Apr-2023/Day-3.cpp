// Remainder on dividing by 11

// Link - https://practice.geeksforgeeks.org/problems/aa8c89caad6b5c3a76ba5e6d65454f77aac3f3543526/1

class Solution
{

public:
    int xmod11(string x)
    {
        // code here
        int ans = 0;
        
        for(int i = 0; i < x.size(); i++){
            ans = ans*10 + x[i];
            ans %= 11;
        }
        return ans;
    }
};
