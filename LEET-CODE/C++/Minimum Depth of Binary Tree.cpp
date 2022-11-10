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
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if(root==nullptr) return 0;
        return f(root);
        
    }
    
private:
    int f(TreeNode* node)
    {
        assert(node);
        if(!node->left and !node->right) return 1;
        int ans=INT_MAX;
        if(node->left)
        {
            int l=f(node->left)+1;
            ans=min(l,ans);
        }
        if(node->right)
        {
            int r=f(node->right)+1;
            ans=min(r,ans);
        }
        
        return ans;
    }
};
