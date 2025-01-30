/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* temp = NULL;
    while (head != NULL){
        struct ListNode* next = head->next;
        head->next = temp;
        temp = head;
        head = next;
    }
    return temp;
}