/*
    Given a binary tree, return the preorder traversal of its nodes' values.

    For example:
        Given binary tree {1,#,2,3},
           1
            \
             2
            /
           3
        return [1,2,3].
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> ans;
        while (!stk.empty() or root) {
            while (root) {
                stk.push(root);
                ans.push_back(root->val);
                root = root->left;
            }
            root = stk.top()->right;
            stk.pop();
        }
        return ans;
    }
};

//morris traversal
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while (root) {
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            } else {
                auto tmp = root->left;
                while (tmp->right and tmp->right != root) {
                    tmp = tmp->right;
                }
                if (!tmp->right) {
                    // It's our first time being here.
                    ans.push_back(root->val);
                    tmp->right = root;
                    root = root->left;
                } else {
                    // We are back from the bottom. Reset the changed pointer.
                    root = root->right;
                    tmp->right = nullptr;
                }
            }
        }
        return ans;
    }
};
