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
    int findLen(ListNode* head){
       ListNode* tail = head;
       int len = 0;
       while(tail){
          tail = tail->next;
          len++;
       }
       return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next) return head;

        ListNode* tail = head;

        int len = findLen(head);
        
        int rot = len - (k%len) - 1;
         
        for(int i=0;i<rot;i++) tail = tail->next;
        
        ListNode* secondHead = tail->next;
        ListNode* secondTail = secondHead;

        while(secondTail && secondTail->next) secondTail=secondTail->next;
        
        tail->next = nullptr;

        if(secondTail) secondTail->next = head;
        else return head;
        
        return secondHead;
    }
};