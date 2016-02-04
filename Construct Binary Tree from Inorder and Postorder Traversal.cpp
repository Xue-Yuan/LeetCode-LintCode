/*
    Given inorder and postorder traversal of a tree, construct 
        the binary tree.

    Example
        Given inorder [1,2,3] and postorder [1,3,2], return a tree:

          2
         / \
        1   3
*/
class Solution 
{
    using vitr = vector<int>::iterator;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        vitr idx = postorder.end() - 1;
        return buildTree(inorder.begin(), inorder.end(), idx);
    }
private:
    TreeNode *buildTree(vitr b, vitr e, vitr &idx)
    {
        if (b >= e) return nullptr;
        TreeNode *root = new TreeNode(*idx--);
        vitr i = find(b, e, root->val);
        root->right = buildTree(i + 1, e, idx);
        root->left = buildTree(b, i, idx);
        return root;
    }
};
