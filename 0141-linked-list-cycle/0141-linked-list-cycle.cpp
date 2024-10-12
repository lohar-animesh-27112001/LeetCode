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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
    bool hasCycle2(ListNode *head) {
        vector<ListNode*> visited;
        ListNode *temp = head;
        while(temp != nullptr) {
            for(auto p:visited) {
                if(temp == p){
                    return true;
                }
            }
            visited.push_back(temp);
            temp = temp->next;
        }
        return false;
    }
};