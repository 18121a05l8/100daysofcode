class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int count=0;
        int startrow=0;
        int startcol=0;
        int endrow=row-1;
        int endcol=col-1;
        while(count<total)
        {
            for(int i=startcol;i<=endcol and count<total;i++)
            {
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            for(int i=startrow;i<=endrow and count<total;i++)
            {
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            for(int i=endcol;i>=startcol and count<total;i--)
            {
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            for(int i=endrow;i>=startrow and count<total;i--)
            {
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};
