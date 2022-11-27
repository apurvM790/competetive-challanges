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


// using stack to find next greater element in the array
//time O(n) ... space O(n)

class Solution {
    stack<int> s;
    private:
    void greater(vector<int>& arr, int n)
    {
    
        s.push(arr[0]);
        
        for (int i = 1; i < n; i++) {
        
            if (s.empty()) {
                s.push(arr[i]);
                continue;
            }
        
            while (s.empty() == false && s.top() < arr[i]) {
                s.pop();
            }
            s.push(arr[i]);
        }
        
    }
public:
    ListNode* removeNodes(ListNode* head) {
        
        vector<int> arr;
        ListNode* temp=head;
        
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        greater(arr,arr.size());
        
        vector<int> lis;
        while(!s.empty())
        {
            lis.push_back(s.top());
            s.pop();
        }
        reverse(lis.begin(),lis.end());
        
        head=new ListNode(lis[0]);
        temp=head;
        for(int i=1;i<lis.size();i++)
        {
            temp->next=new ListNode(lis[i]);
            temp=temp->next;
        }
        
        return head;
        
        
    }
};
