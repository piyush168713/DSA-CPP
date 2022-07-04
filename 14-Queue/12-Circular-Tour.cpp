/*

Circular Tour

Problem Statement

You have been given a circular path. There are N petrol pumps on this path that are numbered from 0 to N - 1 (Both inclusive). 
Each petrol pump has two values associated with it:
1)The amount of petrol that is available at this particular petrol pump.
2)The distance to reach the next petrol pump.
You are on a truck having an empty tank of infinite capacity. You can start the tour from any of the petrol pumps. Your task is to calculate the first petrol pump from where the truck will be able to complete the full circle or determine if it is impossible to do so.
You may assume that the truck will stop at every petrol pump and it will add the petrol from that pump to its tank. The truck will move one kilometre for each litre of petrol consumed.

Input Format
The first line of input contains an integer 'N' representing the number of petrol pumps.
Each of the next N lines will contain a pair of space-separated integers representing the amount of petrol that pump has and the distance to reach the next petrol pump, respectively.

Output Format :
Print an integer representing the index of the first petrol pump from which we should start the tour. If no such petrol pump exists, print ‘-1’.

Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.  Make sure that the output has 0 - based indexing.

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1

Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).

*/

int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)
{
    long long int deficit = 0;   // when you get -ve balance then store balance     // in deficit
    long long int balance = 0;
    long long int start = 0;
    
    for(int i = 0; i < N; i++)
    {
        balance += petrol[i] - distance[i];
        if(balance < 0)
        {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    
    if(deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}
