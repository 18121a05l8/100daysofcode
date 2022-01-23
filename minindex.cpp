    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int minidx=INT_MAX;
        const int num=1e6+7;
        int idx[num];
        for(int i=0;i<num;i++) idx[i]=-1;
        for(int i=0;i<n;i++)
        {
            if(idx[arr[i]]!=-1)
            {
                minidx=min(minidx,idx[arr[i]]);
            }
            else
            {
                idx[arr[i]]=i;
            }
        }
        if(minidx==INT_MAX)
        cout<<-1<<endl;
        else
        cout<<1+minidx<<endl;
    }
