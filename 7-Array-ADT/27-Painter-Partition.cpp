// Problem Statement (CodeStudio)

// Given an array/list of length ‘N’, where the array/list represents the boards and 
// each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters 
// are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards 
// under a constraint that any painter will only paint the continuous sections of boards.

// Sample Input
// 2
// 4 2
// 5 5 5 5
// 4 2
// 10 20 30 40

// Sample Output
// 10
// 60

// Explanation
// In the first test case, we can divide the boards into 2 equal-sized partitions, 
// so each painter gets 10 units of the board and the total time taken is 10.


bool isPossible(vector<int> &boards, int k, int mid){
	int painterCount = 1;
	int boardSum = 0;
	for(int i=0; i<boards.size(); i++){
		if(boardSum + boards[i] <= mid)
		{
			boardSum += boards[i];
		}
		else
		{
			painterCount++;
			if(painterCount > k || boards[i] > mid)
			{
				return false;
			}
			boardSum = boards[i];
		}
	}
	return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
	int s=0;
	int sum=0;
	for(int i=0; i<boards.size(); i++)
	{
		sum = sum+boards[i];
	}
	int e=sum;
	int mid = s+(e-s)/2;
	int ans=-1;
	while(s<=e)
	{
		if(isPossible (boards, k ,mid))
		{
			ans=mid;
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
		mid = s+(e-s)/2;
	}
	return ans;
}
