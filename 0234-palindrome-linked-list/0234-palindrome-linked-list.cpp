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
        vector<int> list;
        while (head){
            list.push_back(head->val);
            head = head->next;
        }
        int a = 0;
        int b = list.size()-1;
        while (a<b){
            if (list[a] != list[b]){
                return false;
            }
            a++;
            b--;
        }
        return true;
    }
};