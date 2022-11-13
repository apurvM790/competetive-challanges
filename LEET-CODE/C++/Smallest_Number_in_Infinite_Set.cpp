class SmallestInfiniteSet {
public:
    set<int> s;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
            {
                s.insert(i);
                min_heap.push(i);
            }
        
    }
    
    int popSmallest()
    {
        
        int val=min_heap.top();
        s.erase(val);
        min_heap.pop();
        return val;
        
    }
    
    void addBack(int num) {
        
        if(s.find(num)==s.end())
        {
            s.insert(num);
            min_heap.push(num);
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
