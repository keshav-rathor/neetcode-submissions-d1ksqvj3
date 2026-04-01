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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(!head || !head->next) return NULL;
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* j=head;
        ListNode* i=temp;
        int k=n;
        while(k--)
        {
            j=j->next;
        }

        while(j)
        {
            j=j->next;
            i=i->next;
        }
        i->next=i->next->next;
        return temp->next;

        
    }
};
