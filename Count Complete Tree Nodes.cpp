/*
	Given a complete binary tree, count the number of nodes.

	Definition of a complete binary tree from Wikipedia:
		In a complete binary tree every level, except possibly 
			the last, is completely filled, and all nodes in 
			the last level are as far left as possible. It can 
			have between 1 and 2h nodes inclusive at the last 
			level h.
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

 //log(n) * log(n)
class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        if (!root) return 0;
        int l = 0, r = 0;
        for (TreeNode *t = root->left; t; t = t->left) ++l;
        for (TreeNode *t = root->right; t; t = t->right) ++r;
        if (l == r) return (1 << (l + 1)) - 1;
        
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
};
