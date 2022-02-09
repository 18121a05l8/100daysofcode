class LRUCache {
public:
    list<pair<int,int>>dq;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            int val=mp[key]->second;
            dq.erase(mp[key]);
            dq.push_front(make_pair(key,val));
            mp[key]=dq.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            if(dq.size()==cap)
            {
                int last=(dq.back()).first;
                dq.pop_back();
                mp.erase(last);
            }
        }
        else
            dq.erase(mp[key]);
        dq.push_front(make_pair(key,value));
        mp[key]=dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
