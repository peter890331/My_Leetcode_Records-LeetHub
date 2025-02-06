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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp){
            count++;
            temp = temp->next;
        }
        int mid = floor(count/2);
        while (head){
            if (mid == 0){
                return head;
            }
            mid--;
            head = head->next;
        }
        return head;
    }
};