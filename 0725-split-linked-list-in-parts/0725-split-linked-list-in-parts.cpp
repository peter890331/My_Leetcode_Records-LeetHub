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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int list_size = 0;
        ListNode* now = head;
        while (now){
            list_size++;
            now = now->next;
        }

        vector<ListNode*> ans;
        int split_size = list_size / k;
        int split_remain = list_size % k;
        // cout<<split_size<<','<<split_remain;
        now = head;

        for (int i=0; i<k; i++){

            ListNode* k_head = now;
            ListNode* k_end = now;

            int now_split_size = split_size + (split_remain>0? 1: 0);
            split_remain--;

            for (int j=0; j<now_split_size; j++){
                k_end = now;
                if (now) now = now->next;
            }

            if (k_end) k_end -> next = nullptr;
            ans.push_back(k_head);
        }

        return ans;

    }
};