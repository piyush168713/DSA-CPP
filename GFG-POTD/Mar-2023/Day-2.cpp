// Walls Coloring II

// Link - https://practice.geeksforgeeks.org/problems/9dacc32ad062be6e2ba8f6c41aad0b2b2376397d/1

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<costs[0].size();i++){
            pq.push({costs[0][i],i});
        }
        
        for(int i=1;i<costs.size();i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> temp;
            for(int j=0;j<costs[0].size();j++){
                if(pq.top().second==j){
                    auto a=pq.top();
                    pq.pop();
                    if(pq.empty()) return -1;
                    temp.push({costs[i][j]+pq.top().first,j});
                    pq.push(a);
                }else{
                    temp.push({costs[i][j]+pq.top().first,j});
                }
            }
            
            pq=temp;
        }
        return pq.top().first;
    }
};
