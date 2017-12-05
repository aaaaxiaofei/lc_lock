369. Plus One Linked List

Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        
        if (head == nullptr) return head;
        
        ListNode* cur = new ListNode(0);
        ListNode *temp = cur;
        
        cur->next = head;
        head = cur;
        
        while (cur->next) {
            if (cur->next->val != 9) {
                temp = cur->next;
            }
            cur = cur->next;
        }
        
        while (temp) {
            temp->val = (temp->val + 1)%10;
            temp = temp->next;
        }
        
        return head->val == 0 ? head->next : head;
    }
};