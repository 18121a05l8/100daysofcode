class Solution {
public:
    class Node{
        public:
        int data;
        int row;
        int col;
        Node(int d,int r,int c)
        {
            data=d;
            row=r;
            col=c;
        }
    };
    class compare{
        public:
        bool operator()(Node *a,Node *b)
        {
            return a->data>b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*,vector<Node*>,compare>heap;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int k=nums.size();
        int n=nums[0].size();
        for(int i=0;i<k;i++)
        {
            int element=nums[i][0];
            mini=min(mini,element);
            maxi=max(maxi,element);
            heap.push(new Node(element,i,0));
        }
        int start=mini;
        int end=maxi;
        while(not heap.empty())
        {
            Node *temp=heap.top();
            heap.pop();
            mini=temp->data;
            if(maxi-mini<end-start)
            {
                start=mini;
                end=maxi;
            }
            if(temp->col+1<nums[temp->row].size())
            {
                maxi=max(maxi,nums[temp->row][temp->col+1]);
                heap.push(new Node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else
                break;
        }
        return {start,end};
    }
};
