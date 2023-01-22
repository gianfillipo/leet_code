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
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return helper(root -> left, root -> right);
    }
    bool helper(TreeNode* p1, TreeNode* p2) {
        if (p1 == NULL or p2 == NULL)
            return p1 == NULL and p2 == NULL;

        return 
            p1 -> val == p2 -> val
            and helper(p1 -> left, p2 -> right)
            and helper(p1 -> right, p2 -> left);
    }

};
