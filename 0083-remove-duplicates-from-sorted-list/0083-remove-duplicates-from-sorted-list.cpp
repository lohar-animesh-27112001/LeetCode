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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        int temp = head->val;
        ListNode *tempNode = head;
        while(tempNode->next != nullptr) {
            while(tempNode->next->val == temp) {
                ListNode* nextNode = tempNode->next;
                tempNode->next = nextNode->next;
                if(tempNode->next == nullptr) {
                    return head;
                }
            }
            tempNode = tempNode->next;
            if(tempNode != nullptr) {
                temp = tempNode->val;
            } else {
                return head;
            }
        }
        return  head;
    }
};