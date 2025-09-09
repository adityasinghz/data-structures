/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = slow;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast==slow){
                ListNode *ptr1 = head;
                ListNode *ptr2 = slow;

                while(ptr1!=ptr2){
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1;
            }
        }
        return nullptr;
    }
};