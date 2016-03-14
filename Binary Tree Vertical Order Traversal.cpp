/*
    Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

    If two nodes are in the same row and column, the order should be from left to right.

    Examples:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its vertical order traversal as:
    [
      [9],
      [3,15],
      [20],
      [7]
    ]
    Given binary tree [3,9,20,4,5,2,7],
        _3_
       /   \
      9    20
     / \   / \
    4   5 2   7
    return its vertical order traversal as:
    [
      [4],
      [9],
      [3,5,2],
      [20],
      [7]
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
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        if (!root) return {};
        
        unordered_map<int, vector<int>> m;
        int minidx = 0, maxidx = 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty())
        {
            auto p = q.front(); q.pop();
            int idx = p.second;
            TreeNode *node = p.first;
            m[idx].push_back(node->val);
            minidx = min(minidx, idx);
            maxidx = max(maxidx, idx);
            if (node->left) q.push({node->left, idx-1});
            if (node->right) q.push({node->right, idx+1});
        }
        
        vector<vector<int>> ret;
        for (int i = minidx; i <= maxidx; ++i)
            ret.push_back(m[i]);
            
        return ret;
    }
};
