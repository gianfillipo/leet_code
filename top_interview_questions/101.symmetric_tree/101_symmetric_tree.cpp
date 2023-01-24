/*
    Problem components:
        Binary tree
        Traverse binary tree
        Check if it's a mirror
        Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Solution Ideas:
        Recursion
            Create a new function helper that returns a bool
            Check if one of them are null, if it's true return if both are null,
            return if both values are equal and call two the function two times 

            bool helper(TreeNode* p1, TreeNode* p2) {
                if (p1 == NULL or p2 == NULL)
                    return p1 == NULL and p2 == NULL;

                return 
                    p1 -> val == p2 -> val
                    and helper(p1 -> left, p2 -> right)
                    and helper(p1 -> right, p2 -> left);
            }

            Time Complexity:
                O(N)
            Space Complexity:
                O(N)

        Iteration:
            Use an algorithm close to BFS and traverse the tree using a queue 
            Each loop two nodes are extracted and compared, if they are both NULL
            , we continue to the next loop, if just one of them are NULL, just 
            return false, if the values are different, just return false.

            If all if statements return false, then we add to the queue
            node1 -> left, node2 -> right, node1 -> right, node2 -> left, 
            Time Complexity:
                O(N)
            Space Complexity:
                O(N)

*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        queue<TreeNode*>q;
        q.push(root -> left);
        q.push(root -> right);

        while(not q.empty()) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();

            if (t1 == NULL and t2 == NULL)
                continue;
            
            if (t1 == NULL or t2 == NULL)
                return false;

            if (t1 -> val != t2 -> val)
                return false;
            
            q.push(t1 -> left);
            q.push(t2 -> right);
            q.push(t1 -> right);
            q.push(t2 -> left);
        }

        return true;
    }
};
