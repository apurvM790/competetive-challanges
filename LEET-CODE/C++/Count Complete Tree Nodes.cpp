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
    private:
    void solve(TreeNode* node,int& count)
    {
        count++;
        
        if(node->left )
        {
            solve(node->left,count);
        }
        if(node->right )
        {
            solve(node->right,count);
        }
    }
public:
    int countNodes(TreeNode* root) {
        
        int count=0;
        if(root==nullptr) return count;
        solve(root,count);
        return count;
        
        
        
    }
};
