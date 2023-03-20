// Shortest XY distance in Grid

// Link - https://practice.geeksforgeeks.org/problems/7366ce450d84b55391fc787a681c4d60de359e72/1

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        vector<vector<int>>vis(N,vector<int>(M,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j] == 'X'){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
                
            }
        }
        int tm = 0;
        int ans = INT_MAX;;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,-1,0,+1};
        while(!q.empty()){
            // int t = q.front().first.first;
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = delrow[i]+r;
                int nc = delcol[i]+c;
                if(nr>=0 && nr<N && nc>=0 && nc<M && !vis[nr][nc]){
                    if(grid[nr][nc] == 'Y'){
                        ans = min(ans,t+1);
                    }
                    else{
                        q.push({{nr,nc},t+1});
                    }
                    vis[nr][nc]=1;
                }
            }
        }
        return ans;
    }
};
