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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* secondHead = reverse(slow);

        while(secondHead){
           if(head->val!=secondHead->val) return false;
           head = head->next;
           secondHead = secondHead->next;
        }
        return true;
    }

    ListNode* reverse(ListNode *head){
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};