/*
    Problem Components:
        Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
        Return the linked list sorted as well. 

        Sorted linked list
        Remove Elements
        
    Solution ideas:
        Use a curr variable to iterate in the linked list while curr != null and curr -> next != null
        As the current value is equal to the next, we will point its next to the next of the next node
        1 - 1 - 2 - 2 - 4
        1 - 2 - 4
*/


/**
 * definition for singly-linked list.
 * struct listnode {
 *     int val;
 *     listnode *next;
 *     listnode() : val(0), next(nullptr) {}
 *     listnode(int x) : val(x), next(nullptr) {}
 *     listnode(int x, listnode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != NULL and  curr -> next != NULL) {
            if (curr -> val == curr -> next -> val)
                curr -> next = curr -> next -> next;
            else 
                curr = curr -> next; 
        }

        return head;
    }
};
