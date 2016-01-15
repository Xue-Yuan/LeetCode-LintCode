/*
    Given preorder and inorder traversal of a tree, construct the 
        binary tree.
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
    using vecitr = vector<int>::iterator;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // write your code here
        if (preorder.empty() || preorder.size() != inorder.size()) return nullptr;
        auto pitr = preorder.begin();
        return buildTree(pitr, inorder.begin(), inorder.end());
    }
private:
    TreeNode *buildTree(vecitr &pitr, vecitr b, vecitr e)
    {
        if(b >= e) return nullptr;
        TreeNode *root = new TreeNode(*pitr);
        auto tmp = find(b, e, *pitr);
        pitr++;
        root->left = buildTree(pitr, b, tmp);
        root->right = buildTree(pitr, tmp + 1, e);
        return root;
    }
};
