// Add Minimum Characters

// Link - https://practice.geeksforgeeks.org/problems/55dbfdc246f3f62d6a7bcee7664cacf6be345527/1

class Solution{   
public:

    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    int addMinChar(string str){    
        //code here
        int n = str.size();
        
        for(int i = n-1; i >= 0; i--){
            if(str[0] == str[i] && isPalindrome(str,0,i))
                return n-i-1;
        }
        return 0;
    }
};
