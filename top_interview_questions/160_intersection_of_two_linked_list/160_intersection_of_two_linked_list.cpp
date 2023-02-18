/*
 * Problem components
 *  Two linked List
 *  Intersection
 */


/* Brute Force
 *  Time Complexity
 *      O(N**M)
 *  Space Complexity:
 *      O(1)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr_a = headA;
        ListNode* curr_b = headB;

        while (curr_a != NULL) {
            while (curr_b != NULL) {
                if (curr_a == curr_b) return curr_a;
                curr_b = curr_b -> next;
            }
            curr_a = curr_a -> next;
            curr_b = headB;
        }

        return NULL;
    }
};

/* Hash set
 * Time Complexity:
 *  O(N + M)
 * Space Complexity:
 *  O(N)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes;

        while (headA != NULL) {
            nodes.insert(headA);
            headA = headA -> next;
        }

        while (headB != NULL) {
            if (nodes.find(headB) != nodes.end()) return headB;
            headB = headB -> next;
        }

        return NULL;
    }
};

/* Two Pointers
 *  Time Complexity:
 *  O(N + M)
 * Space Complexity:
 *  O(1)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;

        while (pa != pb) {
            pa = pa == NULL? headB: pa -> next;
            pb = pb == NULL? headA: pb -> next;
        }

        return pa;
    }
};


