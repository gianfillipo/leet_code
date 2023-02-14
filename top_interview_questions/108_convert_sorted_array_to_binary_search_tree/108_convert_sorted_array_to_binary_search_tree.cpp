/*
    Problem components:
        Binary Search tree
        Convert Sorted Array to Binary Search Tree
 

    Solution Ideas:
        Type of binary search
        Always use left middle child       

    
    Time Complexity:
        O(N)
    Space Commplexity:
        O(log N)

    Another solution
        Alaways use right middle child    

        class Solution {
            public:

                vector<int> nums;

                TreeNode* sortedArrayToBST(vector<int>& nums) {
                    this -> nums = nums;
                    return helper(0, nums.size() - 1);
                }   

                TreeNode* helper(int left, int right) {
                    if (left > right) return NULL;

                    int middle = (left + right) / 2;
                    if ((left + right) % 2 == 1) middle++; We could use a rand int here, to get a different solution.

                    TreeNode* n = new TreeNode(nums[middle]);
                    n -> left = helper(left, middle - 1);
                    n -> right = helper(middle + 1, right);

                    return n;
                }
            };



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
class Solution {
public:

    vector<int> nums;

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this -> nums = nums;
        return helper(0, nums.size() - 1);
    }   

    TreeNode* helper(int left, int right) {
        if (left > right) return NULL;

        int middle = (left + right) / 2;
        if (middle % 2 == 1) middle++;

        TreeNode* n = new TreeNode(nums[middle]);
        n -> left = helper(left, middle - 1);
        n -> right = helper(middle + 1, right);

        return n;
    }
};
