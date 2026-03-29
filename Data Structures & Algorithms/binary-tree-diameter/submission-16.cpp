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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        recursiveHelper(root, maxDiameter);
        return maxDiameter;
    }

    int recursiveHelper(TreeNode* root, int& maxDiameter)
    {
        if(!root) return 0;
        int left = recursiveHelper(root->left, maxDiameter);
        int right = recursiveHelper(root->right, maxDiameter);
        maxDiameter = maxDiameter > (left + right) ? maxDiameter : (left + right);
        return 1 + max(left, right);
    }
};
