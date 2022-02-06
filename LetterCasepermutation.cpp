class Solution {
public:
    void solve(vector<string>&ans,string s,int index,string res)
    {
        if(index>=s.size())
        {
            ans.push_back(s);
            return;
        }
        solve(ans,s,index+1,res);
        if(isalpha(s[index]))
        {
            if(isupper(s[index]))
                s[index]=tolower(s[index]);
            else
                s[index]=toupper(s[index]);
            solve(ans,s,index+1,res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        if(s.size()==0)
            return ans;
        solve(ans,s,0,"");
        return ans;
    }
};
