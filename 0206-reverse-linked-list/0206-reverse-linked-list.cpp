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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        } else if(head->next == nullptr) {
            ListNode* newHead = new ListNode(head->val);
            return newHead;
        }
        ListNode* node = reverseList(head->next);
        ListNode* temp = node;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new ListNode(head->val);
        return node;
    }
};