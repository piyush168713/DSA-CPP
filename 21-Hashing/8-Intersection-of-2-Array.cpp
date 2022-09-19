// Intersection of two arrays

// Link - https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        unordered_map<int, int> map;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            map[a[i]]++;
        }
        
        for(int i = 0; i < m; i++){
            if(map.find(b[i]) != map.end()){
                count++;
                map.erase(b[i]);   // erase the common element from map after compare
            }
        }
        return count;
    }
};
