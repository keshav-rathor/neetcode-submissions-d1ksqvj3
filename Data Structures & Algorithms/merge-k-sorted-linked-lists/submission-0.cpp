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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        ListNode* ans=lists[0];

        for(int i=1;i<n;i++)
        {
            ans=merge(ans,lists[i]);
        }
        return ans;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* ans=new ListNode;
        ListNode* temp=ans;
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                temp->next=new ListNode(l1->val);
                l1=l1->next;
                
            }
            else
            {
                temp->next=new ListNode(l2->val);
                l2=l2->next;
            }
            temp=temp->next;

        }
        if(l1) temp->next=l1;
        else temp->next=l2;
        return ans->next;
    }
};
