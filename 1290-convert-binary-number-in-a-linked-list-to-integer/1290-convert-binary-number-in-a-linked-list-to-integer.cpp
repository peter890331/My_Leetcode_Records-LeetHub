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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        vector<int> integer;
        while (head){
            integer.push_back(head->val);
            head = head->next;
        }
        int n = integer.size();
        for (int i=0; i<n; i++){
            ans += pow(2, n-1-i) * integer[i];
        }
        return ans;
    }
};