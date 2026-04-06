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
    int kthSmallest(TreeNode* root, int k) 
    {
        if(!root) return 0;
        vector<TreeNode*> arr;
        counter(root, arr);
        return arr[k - 1]->val;
    }

    void counter(TreeNode* root, vector<TreeNode*>& arr)
    {
        if(!root) return;
        counter(root->left, arr);
        arr.push_back(root);
        counter(root->right, arr);
    }
};
