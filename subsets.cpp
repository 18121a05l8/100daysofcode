class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>res,int index,vector<int>&nums)
    {
        if(index>=nums.size())
        {
            ans.push_back(res);
            return;
        }
        solve(ans,res,index+1,nums);
        res.push_back(nums[index]);
        solve(ans,res,index+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()==0)
            return ans;
        vector<int>res;
        solve(ans,res,0,nums);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
