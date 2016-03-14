/*
    Given a binary search tree and a node in it, find the in-order successor of 
        that node in the BST.

    Note: If the given node has no in-order successor in the tree, return null.
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

//Just inorder traversal, regardless of the fact it's a BST
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        pre = ret = nullptr;
        inorder(root, p);
        return ret;
    }
private:
    void inorder(TreeNode *node, TreeNode *p)
    {
        if (!node) return;
        inorder(node->left, p);
        if (pre == p) 
        {
            if (!ret) ret = node;
            return;
        }
        pre = node;
        inorder(node->right, p);
    }
private:
    TreeNode *pre, *ret;
};

class Solution2
{
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        if (!root || !p) return nullptr;
        
        TreeNode *suc = nullptr;
        while (root)
        {
            if (root->val <= p->val) 
                root = root->right;
            else
            {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
};

