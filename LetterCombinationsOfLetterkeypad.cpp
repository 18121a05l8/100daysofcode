class Solution {
public:
    void solve(string digits,int index,string map[],vector<string>&ans,string output)
    {
        if(index>=digits.size())
        {
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string val=map[number];
        for(int i=0;i<val.size();i++)
        {
            output.push_back(val[i]);
            solve(digits,index+1,map,ans,output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0)
            return ans;
        string map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,0,map,ans,"");
        return ans;
    }
};
