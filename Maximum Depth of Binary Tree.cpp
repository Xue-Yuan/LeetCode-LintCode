/*
	Given a binary tree, find its maximum depth.

	The maximum depth is the number of nodes along the longest path 
		from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }
    int maxDepth(TreeNode* root, int n) {
        if(!root) return n;
        return max(maxDepth(root->left, n+1), maxDepth(root->right, n+1));
    }
};
