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
    void reorderList(ListNode* head) {
        ListNode* list1=head;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* l2=slow;
        ListNode* prev2=NULL;
        
        while(l2)
        {
            ListNode* temp=l2->next;
            l2->next=prev2;
            prev2=l2;
            l2=temp;
        }
        ListNode* list2=prev2;

        while(list2->next)
        {
            ListNode* l1=list1->next;
            ListNode* l2=list2->next;


            list1->next=list2;
            list2->next=l1;
            list1=l1;
            list2=l2;


        }
        
    
        
        
    }
};
