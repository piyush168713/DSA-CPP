// Surround the 1's

class Solution {
public:
    int Count(vector<vector<int> >& v) {
        // Code here
         int count=0;
         int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++)
        { 
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1){
                int c=0;
                if(i-1>=0)
                {
                    if(v[i-1][j]==0) c++;
                }
                if(i+1<n)
                {
                    if(v[i+1][j]==0) c++;
                }
                if(j-1>=0  )
                {
                    if(v[i][j-1]==0)
                    c++;
                }
                if(j+1<m  )
                {
                    if( v[i][j+1]==0)
                    c++;
                }
                if(i-1>=0 and j-1>=0  )
                {
                    if(v[i-1][j-1]==0)
                   c++; 
                }
                if(i+1<n and j+1<m)
                {
                    if(v[i+1][j+1]==0)
                    c++;
                }
                if(i+1<n and j-1>=0  )
                {
                    if(v[i+1][j-1]==0)
                    c++;
                }
                if(i-1>=0 and j+1<m   )
                {
                    if(v[i-1][j+1]==0)
                    c++;
                }
                
                if(c%2==0 and c>0) count++;
                }
            }
        }
        return count;
    }
};
