// using heap data structure...

class Solution {
public:
    struct valuecomp{
        char operator()(pair<char,int> &x, pair<char,int> &y){
            return y.second>x.second;
        }
    };
    
    string frequencySort(string s) {
        
        unordered_map<char,int> mp;
        for(auto i:s)
            mp[i]++;
        
        priority_queue<pair<char,int>,vector<pair<char,int>> ,valuecomp> max_heap;
        for(auto entry:mp){
            max_heap.push(entry);
        }
        pair<char,int> prev;
        string res="";
        while(!max_heap.empty()){
            prev.first=max_heap.top().first;
            prev.second=max_heap.top().second;
            max_heap.pop();
            for(int i=0;i<prev.second;i++){
                res+=prev.first;
            }
            
        }
        return res;
        
    }
};
