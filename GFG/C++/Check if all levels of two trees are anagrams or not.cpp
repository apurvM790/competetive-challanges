
// using BFS algorithm...
class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        
        vector<vector<int>> t1;
        vector<vector<int>> t2;
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() or !q2.empty())
        {
            int n1=q1.size();
            int n2=q2.size();
            if(n1!=n2) return false;
            vector<int> r1;
            vector<int> r2;
            while(n1)
            {
                Node* temp1=q1.front();
                Node* temp2=q2.front();
                
                r1.push_back(temp1->data);
                r2.push_back(temp2->data);
                
                q1.pop();
                q2.pop();
                
                if(temp1->left) q1.push(temp1->left);
                if(temp1->right) q1.push(temp1->right);
                
                if(temp2->left) q2.push(temp2->left);
                if(temp2->right) q2.push(temp2->right);
                
                n1--;
            }
            t1.push_back(r1);
            t2.push_back(r2);
        }
        
        for(int i=0;i<t1.size();i++)
        {
            unordered_map<int,int> mp1;
            unordered_map<int,int> mp2;
            
            for(auto &j:t1[i])
                mp1[j]++;
            
            for(auto &j:t2[i])
                mp2[j]++;
                
            for(auto entry:mp1)
            {
                if(entry.second!=mp2[entry.first]) return false;
            }
        }
        return true;
        
        
        
    
    }
};
