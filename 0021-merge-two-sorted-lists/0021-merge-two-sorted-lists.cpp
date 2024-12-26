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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* now = head;

        while (list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                now->next = list1;
                list1 = list1->next;
            }
            else {
                now->next = list2;
                list2 = list2->next;
            }
            now = now->next;
        }

        now->next = list1 ? list1 : list2;

        return head->next;
    }
};

// Reference from niits's solution.