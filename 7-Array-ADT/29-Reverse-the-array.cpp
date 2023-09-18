// Problem Statement

// Reverse The Array - CdoeStudio

// Link - https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298


void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
    int n = arr.size();
    int s = 0, e = n-1;
    
    while(s <= e)
    {
        if(s >= m+1 && e <= n-1){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
        else{
            s++;
        }
    }
}
