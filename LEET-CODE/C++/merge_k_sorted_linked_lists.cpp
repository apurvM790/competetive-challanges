/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// using O(n) extra space and then sort that array and then return the head of new root...
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            ListNode* temp=nullptr;
            return temp;
        }
        //if(lists.size()==1){
        //    return lists[0];
        //}
        vector<int> nm;
        for(auto &i:lists)
        {
            ListNode* temp=i;
            if(temp!=nullptr)
            {
                while(temp!=nullptr)
                {
                    nm.push_back(temp->val);
                    temp=temp->next;
                }
            }
            
        }
        //for(auto &i:nm)
        //    cout<<i<<" ";
        sort(nm.begin(),nm.end());
        if(nm.size()!=0)
        {    
            ListNode* root=new ListNode(nm[0]);
            ListNode* temp=root;
            for(int i=1;i<nm.size();i++)
            {
                temp->next=new ListNode(nm[i]);
                temp=temp->next;
            }
            return root;
        }
        ListNode* root=nullptr;
        return root;
        
    }
};
