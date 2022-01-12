class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        int total=n*n;
        int index=1;
        int count=0;
        int startrow=0;
        int startcol=0;
        int endrow=n-1;
        int endcol=n-1;
        while(count<total)
        {
            for(int i=startcol;i<=endcol and count<total;i++)
            {
                res[startrow][i]=index++;
                count++;
            }
            startrow++;
            for(int i=startrow;i<=endrow and count<total;i++)
            {
                res[i][endcol]=index++;
                count++;
            }
            endcol--;
            for(int i=endcol;i>=startcol and count<total;i--)
            {
                res[endrow][i]=index++;
                count++;
            }
            endrow--;
            for(int i=endrow;i>=startrow and count<total;i--)
            {
                res[i][startcol]=index++;
                count++;
            }
            startcol++;
        }
        return res;
    }
};
