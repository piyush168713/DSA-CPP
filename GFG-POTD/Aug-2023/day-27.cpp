// Reverse a String

class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int size = str.size();
        for(int i = 0; i < size/2; i++)
            swap(str[i], str[size-i-1]);
        
        return str;
    }
};
