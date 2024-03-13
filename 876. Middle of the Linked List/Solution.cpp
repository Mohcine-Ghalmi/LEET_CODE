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
    int lastnode(ListNode* head) {
        int i = 0;
        ListNode *tmp = head;
        while (tmp) {
            tmp = tmp->next;
            i++;
        }
        return (i);
    }
    ListNode* middleNode(ListNode* head) {
        int i = lastnode(head);
        if (i % 2 == 0)
            i = i / 2 + 1;
        else 
            i = round(i / 2.0);
       for (int j = 1; j < i; j++)
            head = head->next;
        return (head);
    }
};