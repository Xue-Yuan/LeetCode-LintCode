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
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        vector<int> ret;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                ret.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                cur = stk.top()->right; 
                stk.pop();
            }
        }
        return ret;
    }
};

//morris
class Solution2 
{
public:
    vector<int> preorderTraversal(TreeNode* cur) 
    {
        vector<int> ret;
        while(cur)
        {
            if(!cur->left)
            {
                ret.push_back(cur->val);
                cur = cur->right;       //we get back from here
            }
            else
            {
                TreeNode *prev = cur->left;
                while(prev->right && prev->right != cur)
                    prev = prev->right;
                if(!prev->right)
                {
                    ret.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
                else    //now it's back to mid node, we can print it
                {
                    cur = cur->right;
                    prev->right = nullptr;
                }
            }
        }
        return ret;
    }
};
