/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// approach first(1)
class Solution1 {
    private:
    void leafnode(TreeNode* root, vector<TreeNode*>& leafNode)
    {
        if(root==nullptr) return ;
        
        if(root->left==nullptr  and root->right==nullptr)
        {
            leafNode.push_back(root);
            return;
        }
        
        else
        {
            leafnode(root->left,leafNode);
            leafnode(root->right,leafNode);
        }
    }
    
void findparent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent)
{
    
    if(node==nullptr) return;
    
    if(node->left)
    {
        parent[node->left]=node;
        findparent(node->left,parent);
    }
    if(node->right)
    {
        parent[node->right]=node;
        findparent(node->right,parent);
    }
    
}
    
int findlen(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent)
{
    return 0;
}
    
public:
    int maxDepth(TreeNode* root) {
        unordered_map<TreeNode* , TreeNode*> parent;
        findparent(root,parent);
        vector<TreeNode*> leafNode;
        leafnode(root,leafNode);
        int maxi=0;
        //for(auto i:leafNode)
        //{
        //    cout<<i->val<<" ";
        //}
        
        for(auto leaf:leafNode)
        {
            int len=findlen(leaf,parent);
            maxi=max(maxi,len);
        }
        
        return maxi;
        
    }
};
// approach second(2)
class Solution2 {
    public:
    int maxDepth(TreeNode* root) {

        if(root==nullptr) return 0;
        
        int maxi=0;
        search(root,0,maxi);
        return maxi;
    }
    
private:
    void search(TreeNode* root, int len, int& maxi)
    {
        len++;
        if(!root->left and !root->right){
            maxi=max(maxi,len);
        }
        else
        {
            if(root->left) search(root->left,len,maxi);
            if(root->right) search(root->right,len,maxi);
        }
    }
};

// approach third(3)
class Solution3 {
    public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        vector<TreeNode*> lon;
        vector<TreeNode*> path;
        search(root,path,lon);
        return lon.size();
  
    }
  private:
    void search(TreeNode* root, vector<TreeNode*> path, vector<TreeNode*> &lon)
    {
        path.push_back(root);
        if(!root->left and !root->right){
            if(path.size()> lon.size())
                lon=path;
            //maxi=max(maxi,len);
        }
        else
        {
            if(root->left) search(root->left,path,lon);
            if(root->right) search(root->right,path,lon);
        }
    }
    
    
};

// approach fourth(4)
class Solution {
    public:
    int maxDepth(TreeNode* root) {
    
        if(root==nullptr) return 0;
        int l=maxDepth(root->left)+1;
        int r=maxDepth(root->right)+1;
        
        return max(l,r);
        
    }
};
