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
    // 函数功能：删除链表中所有值在 nums 数组中的节点，返回修改后的链表头节点。
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

    // 将 nums 数组中的元素存入 unordered_set 中，以便快速查找是否需要删除某个节点，
    // 使用 unordered_set 是因为它的 count 具有 O(1) 的时间复杂度。这样可以快速判断链表中的节点值是否存在于 nums 中。
    unordered_set<int> st(nums.begin(), nums.end());

    // 创建一个临时节点 temp，值为 0，并让它的 next 指向链表的头节点，
    // 这样可以方便地处理链表的第一个节点删除情况。
    ListNode* temp = new ListNode(0);
    temp->next = head;

    // newHead 保存 temp 的位置，用于返回最终修改后的链表头。
    ListNode* newHead = temp;

    // 遍历链表。
    while(temp->next){
        // 如果当前节点的值存在于 unordered_set 中，则需要删除该节点。
        if(st.count(temp->next->val)){
            // 将要删除的节点保存到临时指针 d 中。
            ListNode* d = temp->next;
            // 修改指针跳过当前节点，即将 temp 的 next 指向当前节点的 next。
            temp->next = temp->next->next;
            // 释放被删除节点的内存，防止内存泄漏。
            delete(d);
        }
        else{
            // 如果当前节点的值不在 nums 中，则继续遍历下一个节点。
            temp = temp->next;
        }
    }
    // 返回修改后的链表头，跳过了临时节点 temp。
    return newHead->next;
}
};

// intelligent_660606's solution.

// 在代码中，d 这个临时指针的主要作用是确保删除节点后能够正确释放内存。这是因为在链表操作中，直接断开节点的连接后，需要手动管理内存，防止内存泄漏。
// 删除节点时需要释放内存： 当 temp->next 指向要删除的节点时，如果你只是修改指针，让 temp->next = temp->next->next;，
// 这只是让链表跳过了这个节点，节点本身仍然存在于内存中，并没有被释放。如果没有释放它，它将变成 “悬空指针”（dangling pointer），导致内存泄漏。