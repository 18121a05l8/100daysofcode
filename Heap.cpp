#include<bits/stdc++.h>
using namespace std;
class Heap{
    int arr[100];
    int size;
   public : Heap()
    {
        arr[0]=-1;
        size=0;
    }
    void insert(int val)
    {
        size++;
        arr[size]=val;
        int index=size;
        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for(int i=1;i<=size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    void deletefromheap()
    {
        if(size==0)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size)
        {
            int leftone=2*i;
            int rightone=2*i+1;
            if(leftone<size and arr[i]<arr[leftone])
            {
                swap(arr[i],arr[leftone]);
                i=leftone;
            }
            else if(rightone<size and arr[i]<arr[rightone])
            {
                swap(arr[i],arr[rightone]);
                i=rightone;
            }
            else
                return;
        }
    }
};
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n and arr[largest]<arr[left])
        largest=left;
    if(right<n and arr[largest]<arr[right])
        largest=right;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
int main()
{
    Heap heap;
    heap.insert(55);
    heap.insert(59);
    heap.insert(63);
    heap.print();
    heap.deletefromheap();
    heap.print();
    heap.deletefromheap();
    heap.print();
    int arr2[]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--)
    {
        heapify(arr2,n,i);
    }
    for(int i=1;i<=n;i++)
        cout<<arr2[i]<<" ";
}
