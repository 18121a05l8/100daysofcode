//https://tutorialspoint.dev/data-structure/arrays/rearrange-array-arri#:~:text=Given%20an%20array%20of%20elements,display%20%2D1%20at%20that%20place.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n+1);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=-1 and arr[i]!=i)
        {
            int x=arr[i];
            while(arr[x]!=-1 and arr[x]!=x)
            {
                int y=arr[x];
                arr[x]=x;
                x=y;
            }
            arr[x]=x;
        }
        if(arr[i]!=i)
            arr[i]=-1;
            
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

}
