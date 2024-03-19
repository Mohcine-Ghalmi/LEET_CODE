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
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        int sum = 0; 
        ListNode *rts = new ListNode(0);
        ListNode *r = rts;
        while(l1 != nullptr || l2 != nullptr) {
            sum /= 10;
            if(l1 != nullptr) {
                sum += l1->val;
                l1=l1->next;
            }
            if(l2 != nullptr) {
                sum += l2->val;
                l2= l2->next;
            }
            ListNode *temp = new ListNode(sum%10);
            rts->next = temp;
            rts = rts->next;
        }
        if(sum/10 == 1)
            rts->next = new ListNode(1);
        return r->next;
    }
};