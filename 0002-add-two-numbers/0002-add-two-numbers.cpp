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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> arr1 = {};
        vector<int> arr2 = {};

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while(temp1 != NULL) {
            arr1.insert(arr1.begin(), temp1->val);
            temp1 = temp1->next;
        }

        while(temp2 != NULL) {
            arr2.insert(arr2.begin(), temp2->val);
            temp2 = temp2->next;
        }

        int n = arr1.size();
        int m = arr2.size();

        vector<int> ans_arr = {};
        int carry = 0;

        int i = 0;

        while(i < n || i < m || carry != 0) {
            int digit1 = 0;
            int digit2 = 0;

            if(i < n) {
                digit1 = arr1[n-i-1];
            }

            if(i < m) {
                digit2 = arr2[m-i-1];
            }

            int sum = digit1 + digit2 + carry;

            ans_arr.insert(ans_arr.begin(), sum % 10);

            carry = sum / 10;

            i++;
        }

        reverse(ans_arr.begin(), ans_arr.end());

        ListNode* l3;
        ListNode* ans_listnode = NULL;
        bool first_time = true;

        for(int i = 0; i < ans_arr.size(); i++) {
            ListNode* temp = new ListNode();
            temp->val = ans_arr[i];
            temp->next = NULL;

            if(first_time == true) {
                l3 = temp;
                ans_listnode = l3;
                first_time = false;
            } else {
                l3->next = temp;
                l3 = l3->next;
            }
        }

        return ans_listnode;
    }
};

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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         vector<int> arr1 = {};
//         vector<int> arr2 = {};
//         int num1 = 0;
//         int num2 = 0;
//         ListNode* temp1 = l1;
//         ListNode* temp2 = l2;
//         while(temp1 != NULL) {
//             arr1.insert(arr1.begin(), temp1->val);
//             temp1 = temp1->next;
//         }
//         while(temp2 != NULL) {
//             arr2.insert(arr2.begin(), temp2->val);
//             temp2 = temp2->next;
//         }
//         int n = arr1.size();
//         int m = arr2.size();
//         for(int i = 0; i < n; i++) {
//             int temp = pow(10, i);
//             num1 = num1 + temp * arr1[n-i-1];
//         }
//         for(int i = 0; i < m; i++) {
//           }   long temp = pow(10, i);
//             num2 = num2 + temp * arr2[m-i-1];
       
//         int ans = num1 + num2;
//         ListNode* l3;
//         ListNode* ans_listnode = NULL;
//         bool first_time = true;
//         while(ans != 0) {
//             ListNode* temp = new ListNode();
//             temp->val = ans % 10;
//             temp->next = NULL;
//             if(first_time == true) {
//                 l3 = temp;
//                 ans_listnode = l3;
//                 first_time = false;
//             } else {
//                 l3->next = temp;
//                 l3 = l3->next;
//             }
//             ans = ans / 10;
//         }
//         if(ans_listnode == NULL) {
//             ans_listnode = new ListNode();
//             ans_listnode->val = 0;
//             ans_listnode->next = NULL;
//         }
//         return ans_listnode;
//     }
// };