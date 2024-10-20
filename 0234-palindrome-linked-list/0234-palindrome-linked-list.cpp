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
        vector<int> v;
        while(head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        vector<int> v_rev = v;
        reverse(v_rev.begin(), v_rev.end());
        if(v == v_rev) {
            return true;
        }
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " " << v_rev[i] << ",";
        }
        return false;
    }
};