/*
    Problem components:
       Given the root of a binary tree, return the inorder traversal 
       of its nodes' values.                

       An inorder traversal means we first will print the deepest left node 
       than its parent and then we go for the parent's right child.

       Recursive approach:
            We could create a new void function and print the values with recursion
                void helper(TreeNode* root, vector<int> &res) {
                    while(root != NULL) {
                        helper(root -> left, res);
                        res.push_back(root -> val)
                        helper(root -> right, res);
                    }
                }
            Time Complexity:
                O(N)
            Space Complexity:
                O(N)

        Stack approach:
            We could create a stack and add and pop elements as we iterate through the 
            tree.
                void inorderTraversal(TreeNode* root) {
                    vector<int> res;
                    stack<TreeNode*> nodes;
                    TreeNode* curr = root;

                    while (curr != NULL || !nodes.empty()) {
                        while (curr != NULL) {
                           nodes.push(curr);
                           curr = curr -> left;
                        }
                        curr = nodes.top();
                        res.push_back(curr);
                        nodes.pop();
                        curr = curr -> right;
                    }
                }
            Time Complexity:
                O(N)
            Space Complexity:
                O(N)

        Morris Traversal:
            While curr != Null
            We test if the curr node has a left child, if it has we get this left child righest child 
            and add the curr node, modifying the tree.

            If it doesn't have a left child, we could simply add the current value to the list and move to the rigth 

            Time Complexity:
                O(2N) or simply O(N)
            Space Complexity:
                O(1)
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
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev;
        vector<int> res;

        while (curr != NULL) {
            if (curr -> left == NULL) {
                res.push_back(curr -> val);
                curr = curr -> right;
            }
            else {
                prev = curr -> left;
                while (prev -> right != NULL) {
                    prev = prev -> right;
                }
                prev -> right = curr;
                curr = curr -> left;
                prev -> right -> left = NULL;
            }
        }

        return res;
    }
};
