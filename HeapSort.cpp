void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n and arr[largest]<arr[left])
        largest=left;
    if(right<=n and arr[largest]<arr[right])
        largest=right;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n)
{
    int t=n;
    while(t>1)
    {
        swap(arr[t],arr[1]);
        t--;
        heapify(arr,t,1);
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
    cout<<endl;
    heapsort(arr2,n);
     for(int i=1;i<=n;i++)
        cout<<arr2[i]<<" ";
    
}
