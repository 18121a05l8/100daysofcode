#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    // write your code here
    if(n==0)
    return 1;
    int m=powerLogarithmic(x,n/2);
    if(n%2==0)
    {
        return m*m;
    }
    else
    {
        return m*m*x;
    }
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}
