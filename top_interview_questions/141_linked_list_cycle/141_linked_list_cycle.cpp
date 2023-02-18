/*
 *  Problem components:
 *      Linked list
 *      Cycle
 *
 *  Solution ideas:
 *     HashSet Solution
 *      Time Complexity:
 *          O(N)
 *      Space Complexity:
 *          O(N)
 *
 *     Floyd's Cycle Finding Algorithm (Fast and Slow)
 *      Time Complexity:
 *          O(N)
 *      Space Complexity:
 *          O(1)
 *
 */


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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while (slow != fast) {
            if (fast == NULL || fast -> next == NULL) return false;

            slow = slow -> next;
            fast = fast -> next -> next;
        }
    }
};
