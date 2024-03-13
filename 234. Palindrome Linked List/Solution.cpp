/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public :
        bool isPalindrome(ListNode *head) {

            if(head == NULL)
                return false;

            ListNode *slow = head;
            ListNode *fast = head;
            ListNode *prev = NULL;

            while(fast != NULL && fast->next != NULL) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            prev = NULL;
            ListNode *slowTemp = slow;
            while(slowTemp != NULL)
                slowTemp = slowTemp->next;
            ListNode *reverseListHead = reverseTheList(slow);
            while(reverseListHead != NULL && head != NULL) {
                if(head->val != reverseListHead->val)
                return false;

                reverseListHead = reverseListHead->next;
                head = head->next;
            }
            return true;
        }

        ListNode *reverseTheList(ListNode *head){
            ListNode *prev = NULL;

            while(head != NULL && head->next !=NULL) {
                ListNode *temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            if(head != NULL)
                head->next = prev;
            return head;
        }
};
