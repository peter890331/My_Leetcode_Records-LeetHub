/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;

    struct ListNode* now = head;

    while(list1 != NULL && list2 != NULL){
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

// Reference from niits's solution.