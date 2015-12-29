/*
    Given a binary tree, determine if it is a valid binary search 
        tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less 
        than the node's key.

    The right subtree of a node contains only nodes with keys greater 
        than the node's key.

    Both the left and right subtrees must also be binary search trees.
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
private:
    bool isValidBST(TreeNode*root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (!root) return true;
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val) return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
        
    }
public:
    bool isValidBST(TreeNode* root)
    {
        return isValidBST(root, nullptr, nullptr);
    }
};

//The inorder traversal
class Solution2
{
public:
    bool isValidBST(TreeNode* root)
    {
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }
    bool inorder(TreeNode* node, TreeNode* &prev)
    {
        if (!node) return true;
        if (!inorder(node->left, prev)) return false;
        if (prev && prev->val >= node->val) return false;
        prev = node;
        return inorder(node->right, prev);
    }
};

