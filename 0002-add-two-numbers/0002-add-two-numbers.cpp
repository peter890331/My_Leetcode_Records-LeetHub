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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        int num1 = 0;
        int num2 = 0;
        int nums = 0;
        string nums_ = "";
        while (node1 != nullptr){
            num1 *= 10;
            num1 += node1->val;
            node1 = node1->next;
        }
        while (node2 != nullptr){
            num2 *= 10;
            num2 += node2->val;
            node2 = node2->next;
        }
        string num1_ = to_string(num1);
        string num2_ = to_string(num2);
        reverse(num1_.begin(), num1_.end());
        reverse(num2_.begin(), num2_.end());
        nums = stoi(num1_) + stoi(num2_);
        cout<<num1<<','<<num2<<','<<nums<<endl;

        ListNode* head = new ListNode(nums % 10);
        ListNode* now = head;
        nums /= 10;
        while (nums > 0){
            now->next = new ListNode(nums % 10);
            now = now->next;
            nums /= 10;
        }
        return head;
    }
};