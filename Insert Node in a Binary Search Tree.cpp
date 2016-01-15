/*
    Given a binary search tree and a new tree node, insert the node 
        into the tree. You should keep the tree still be a valid 
        binary search tree.

    Example
        Given binary search tree as follow, after Insert node 6, the 
            tree should be:

          2             2
         / \           / \
        1   4   -->   1   4
           /             / \ 
          3             3   6
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution 
{
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) 
    {
        // write your code here
        if (!root) return node;
        if (node->val < root->val) 
            root->left = insertNode(root->left, node);
        else if (node->val > root->val) 
            root->right = insertNode(root->right, node);
        return root;
    }
};
