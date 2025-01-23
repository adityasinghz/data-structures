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
    int sizeLL(ListNode *head){
         int ct = 0;
         while(head){
            head = head->next;
            ct++;
         }
         return ct;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       
       int len = sizeLL(head);
       
       if(head==nullptr || k%len == 0 || head->next==nullptr) return head;
       k%=len;

       int n = len - k-1;

       ListNode *p = head;

       for(int i=0;i<n;i++)p=p->next;

       ListNode *q = p->next;

       p->next = nullptr;

       ListNode *tail = q;

       while(tail&&tail->next){
           tail=tail->next;
       }

       tail->next = head;
       head = q;

       return head;

    }
};