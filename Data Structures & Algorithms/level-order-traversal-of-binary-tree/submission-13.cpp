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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> treevals;
        int counter = 0;

        treevals.push(root);

        while(!treevals.empty())
        {
            int size = treevals.size();
            vector<int> forPushing;
            for(int i = 0; i < size; i++)
            {
                forPushing.push_back(treevals.front()->val);

                if(treevals.front()->left)
                {
                    treevals.push(treevals.front()->left);
                }

                if(treevals.front()->right)
                {
                    treevals.push(treevals.front()->right);
                }

                treevals.pop();
            }

            res.push_back(forPushing);

            counter++;
        }

        return res;
    }
};
