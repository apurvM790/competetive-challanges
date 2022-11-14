/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   if(root==nullptr) return res;
   queue<Node*> q;
   q.push(root);
   while(!q.empty())
   {
       int n=q.size();
       Node* temp=q.front();
       res.push_back(temp->data);
       while(n)
       {
           temp=q.front();
           q.pop();
           if(temp->left) q.push(temp->left);
           if(temp->right) q.push(temp->right);
           n--;
       }
   }
   
   return res;
}
