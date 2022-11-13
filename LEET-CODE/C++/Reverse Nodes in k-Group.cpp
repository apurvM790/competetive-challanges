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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        vector<int> nums;
        vector<int> temp;
        int n=k;
        while(head)
        {
            if(k)
            {
                temp.push_back(head->val);
                k--;
            }
            else
            {
                k=n;
                reverse(temp.begin(),temp.end());
                for(auto &i:temp)
                {
                    nums.push_back(i);
                }
                temp.clear();
                temp.push_back(head->val);
                k--;
            }
            head=head->next;
        }
        //cout<<temp.size();
        if(temp.size()==n) reverse(temp.begin(),temp.end());
        for(auto &i:temp)
            nums.push_back(i);
        
        head=new ListNode(nums[0]);
        ListNode* emp=head;
        for(int i=1;i<nums.size();i++)
        {
            emp->next=new ListNode(nums[i]);
            emp=emp->next;
        }
        return head;
        
    }
};
