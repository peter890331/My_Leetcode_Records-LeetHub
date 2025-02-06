/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

// Floyd's Cycle Detection Algorithm（快慢指標法）.
// 它能夠高效檢測鏈結串列是否存在環。相比於使用哈希表存儲節點的方法，它具有更好的空間複雜度（O(1) 而不是 O(N)）。
// niits's solution.