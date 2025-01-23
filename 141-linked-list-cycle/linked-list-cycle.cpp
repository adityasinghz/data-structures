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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *last = head;

        while(fast && fast->next){
            fast = fast->next->next;
            last = last->next;
            if(last==fast) return true;
           
        }
        return false;
    }
};