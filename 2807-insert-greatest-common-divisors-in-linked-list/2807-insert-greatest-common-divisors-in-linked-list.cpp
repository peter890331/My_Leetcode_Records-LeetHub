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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* num1; ListNode* num2; int gcd;
        num1 = head;
        num2 = head->next;
        while (num2){
            gcd = GCD(num1->val, num2->val);
            ListNode* gcd_node = new ListNode(gcd);
            num1->next = gcd_node;
            gcd_node->next = num2;
            num1 = num2;
            num2 = num2->next;
        }
        return head; 
    }
private:
    int GCD(int num1, int num2) {
        if(num2 == 0) return num1;
        return GCD(num2, num1%num2);
    }
};

// Reference from 【C++】GCD and LCM, https://ithelp.ithome.com.tw/articles/10284598.