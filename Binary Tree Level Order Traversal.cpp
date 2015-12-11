/*
    Given a binary tree, return the level order traversal of its 
        nodes' values. (ie, from left to right, level by level).

    For example:
        Given binary tree {3,9,20,#,#,15,7},
            3
           / \
          9  20
            /  \
           15   7
        
        return its level order traversal as:
        [
          [3],
          [9,20],
          [15,7]
        ]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> q;
        if(root) q.push({root, 0});
        while(!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            if(ret.size() == tmp.second)
                ret.push_back({});
            ret[tmp.second].push_back(tmp.first->val);
            if(tmp.first->left)
                q.push({tmp.first->left, tmp.second + 1});
            if(tmp.first->right)
                q.push({tmp.first->right, tmp.second + 1});
        }
        return ret;
    }
};