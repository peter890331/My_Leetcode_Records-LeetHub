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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);  // Dummy node.
        dummy->next = head;                 // Dummy node 就是在鏈表表頭 head 前加一個節點指向 head，即 dummy -> head，保證鏈表的 head 不會在刪除操作中遺失。
        ListNode* now = head;
        ListNode* prev = dummy;
        while (now){
            if (now->val == val){
                prev->next = now->next;
            }
            else {
                prev = prev->next;
            }
            now = prev->next;
        }
        return dummy->next;
    }
};

// Dummy node.
// Reference from Linked List - 鏈表 - GitBook, https://algorithm.yuanbin.me/zh-tw/basics_data_structure/linked_list.html.