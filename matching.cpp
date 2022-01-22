#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[22][1<<22];
ll solve(vector<vector<int>>&comp,int i,int n,int mask)
{
    if(i==n+1){
    if(mask==0)
    return 1;
    return 0;
    }
    if(dp[i][mask]!=-1)
    return dp[i][mask];
    ll ans=0;
    for(int w=0;w<n;w++)
    {
        bool aval=(((1<<w)&(mask))==0)? 0:1;
        if(aval and comp[i][w+1])
        {
            ans=((ans%mod) + solve(comp,i+1,n,((mask)^(1<<w)))%mod)%mod;
        }
    }
    return dp[i][mask]=ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    vector<vector<int>>comp(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>comp[i][j];
        }
    }
    cout<<solve(comp,1,n,(1<<n)-1);
}