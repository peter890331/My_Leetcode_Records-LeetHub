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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};

        ListNode* node = head;
        vector<int> local_m;
        int local_count = 1;
        int min_ = INT_MAX;

        while(node->next != nullptr){
            int left = node->val;
            node = node->next;
            local_count++;
            int now = node->val;
            int right = node->next ? node->next->val : now; // 防止访问空指针
            if ((now>left && now>right) || (now<left && now<right)){
                local_m.push_back(local_count);
            }
        }

        int local_m_size = local_m.size();
        if (local_m_size<2) return {-1, -1};
        
        // for (int i=1; i<local_m_size; i++) cout<<local_m[i]<<',';
        for (int i=1; i<local_m_size; i++) min_ = min(min_, local_m[i]-local_m[i-1]);
        int max_ = local_m[local_m_size-1] - local_m[0];

        return {min_, max_};
    }
};