/*

First non-repeating character in a stream

Problem Statement

Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, 
each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"

Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'

Example 2:

Input: A = "zz"
Output: "z#"

Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'
 

Your Task:
You don't need to read or print anything. Your task is to complete the function FirstNonRepeating() which takes A as input parameter and 
returns a string after processing the input stream.

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char, int> count;
		    queue<int> q;
		    
		    string ans = "";
		    
		    for(int i = 0; i < A.length(); i++)
		    {
		        char ch = A[i];
		        
		        // increase count
		        count[ch]++;
		        
		        // push in queue
		        q.push(ch);
		        
		        while(!q.empty())
		        {
		            if(count[q.front()] > 1)
		            {
		               // repeating character
		               q.pop();
		            }
		            else
		            {
		                // non-repeating character
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        if(q.empty())
		            ans.push_back('#');
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
} 
