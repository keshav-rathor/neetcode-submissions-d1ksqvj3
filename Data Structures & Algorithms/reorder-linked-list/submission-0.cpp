class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* temp;
        ListNode* curr = slow;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* end = prev;

        ListNode* front = head;
        while (end->next) {
            ListNode* f_nxt = front->next;
            ListNode* e_nxt = end->next;

            front->next = end;
            end->next = f_nxt;

            front = f_nxt;
            end = e_nxt;
        }
    }
};
