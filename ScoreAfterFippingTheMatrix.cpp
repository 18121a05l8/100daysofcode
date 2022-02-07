class Solution {
public:
    void print(vector<vector<int>>&grid)
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==0)
                        grid[i][j]=1;
                    else
                        grid[i][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            int count=0;
            for(int j=0;j<m;j++)
            {
                if(grid[j][i]==1)
                    count++;
                    
            }
            if(count<(m+1)/2)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[j][i]==0)
                        grid[j][i]=1;
                    else
                        grid[j][i]=0;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            int res=0;
            int k=n-1;
            for(int j=0;j<n;j++)
            {
                res+=pow(2,k)*grid[i][j];
                k--;
            }
            ans+=res;
        }
        return ans;
    }
};
