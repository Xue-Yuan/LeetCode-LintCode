/*
    Given a binary tree, flatten it to a linked list in-place.

    For example,
        Given

                 1
                / \
               2   5
              / \   \
             3   4   6

        The flattened tree should look like:
           1
            \
             2
              \
               3
                \
                 4
                  \
                   5
                    \
                     6
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

//It would be better if we can record the end during the process we
//  traverse the tree instead of finding it again.
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left)
        {
            TreeNode *t = root->left;
            while (t->right) t = t->right;  //find the end
            t->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};

//This is the solution recording the end.
class Solution2 
{
public:
    void flatten(TreeNode* root) 
    {
        TreeNode *end = nullptr;
        flatten(root, end);
    }
private:
    void flatten(TreeNode *root, TreeNode *&end)
    {
        if (!root) return;
        TreeNode *lend = nullptr, *rend = nullptr;
        flatten(root->left, lend);
        flatten(root->right, rend);
        if (root->left)
        {
            lend->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if (rend) end = rend;
        else if (lend) end = lend;
        else end = root;
    }
};

//https://github.com/leetcoders/LeetCode/blob/master/FlattenBinaryTreetoLinkedList.h
class Solution3 
{
public:
    void flatten(TreeNode* root) 
    {
        if (!root) return;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *cur = stk.top(); stk.pop();
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
            cur->right = stk.empty() ? nullptr : stk.top();
            cur->left = nullptr;
        }
    }
};
