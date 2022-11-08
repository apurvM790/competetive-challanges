// using max heap algorithm....
class Solution {
public:
    int minRefuelStops(int target, int start, vector<vector<int>>& sta) {
        
        priority_queue<int> max_heap;
        int stops=0;// counting the number of stops
        for(auto i:sta) // iterating over the stations array
        {
            int pos = i[0]; //pos of particular station
            int fuel = i[1]; //fuel capacity of that station
            
          //main ajenda to use max heap is that after finding that our current fuel is less than the distance then we have to add the maximum fuel previous in our tank to cover more distance...
            while(start<pos)
            {
                if(max_heap.size()==0)
                {
                    return -1;
                }
                int val=max_heap.top();
                max_heap.pop();
                start+=val;
                stops++;
            }
            max_heap.push(fuel);
        }
        while(start<target)
            {
                if(max_heap.size()==0)
                {
                    return -1;
                }
                int val=max_heap.top();
                cout<<val<<" ";
                max_heap.pop();
                start+=val;
                stops++;
            }
        
        return stops;
        
        
    }
};
