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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB) {

            ptrA = (ptrA ? ptrA->next : headB);
            ptrB = (ptrB ? ptrB->next : headA);

            // if (ptrA != NULL){
            //     ptrA = ptrA->next;
            // }
            // else {
            //     ptrA = headB;
            // }
            // if (ptrB != NULL){
            //     ptrB = ptrB->next;
            // }
            // else {
            //     ptrB = headA;
            // }

        }
        return ptrA;
    }
};

// Reference from Shobhit Verma's solution.
// Reference from 【LeetCode】160. Intersection of Two Linked Lists 解題報告, https://bclin.tw/2022/06/19/leetcode-160/.
// 原理是，part A 與 part B 的長度可能不同，但藉由讓兩個指標兩條路線都走，使得走的長度相同。