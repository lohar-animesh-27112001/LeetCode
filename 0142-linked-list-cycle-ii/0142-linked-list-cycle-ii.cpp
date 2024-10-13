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
        ListNode* slow = head;
        ListNode* speed = head;
        while(speed != nullptr && speed->next != nullptr) {
            slow = slow->next;
            speed = speed->next->next;
            if(slow == speed) {
                slow = head;
                while(slow != speed) {
                    slow = slow->next;
                    speed = speed->next;
                }
                return speed;
            }
        }
        return nullptr;
    }
};