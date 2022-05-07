// Given an array of length ‘N’, where each element denotes the position of a stall. 
// Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. 
// To prevent the cows from hurting each other, you need to assign the cows to the stalls, 
// such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.

#include<iostream>
using namespace std;

int isPossible(int stalls[], int k, int mid)
{
    int cowCount=1;
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if(stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggresiveCows(int stalls[], int k){
    int s=0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int mid=s+(e-s)/2;
    int ans=-1;

    while(s<=e)
    {
        if(isPossible(stalls, k, mid))
        {
            ans=mid;
            s=mid+1;
        }
        else if{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    
}

int main(){
    int nums[]= {4, 2, 1, 3, 6};

    aggresiveCows(nums,2);

    return 0;
}