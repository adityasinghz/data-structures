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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int>freq;
        while(headA){
         freq[headA]=true; 
         headA=headA->next;
        }
        while(headB) {
            if(freq[headB]) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};