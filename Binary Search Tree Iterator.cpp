/*
    Implement an iterator over a binary search tree (BST). 
        Your iterator will be initialized with the root 
        node of a BST.

    Calling next() will return the next smallest number 
        in the BST.

    Note: next() and hasNext() should run in average O(1) 
        time and uses O(h) memory, where h is the height 
        of the tree.
*/
        
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator 
{
private:
    stack<TreeNode *> stk;
    TreeNode *t;
public:
    BSTIterator(TreeNode *root): t(root) {}

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        while(t)
        {
            stk.push(t);
            t = t->left;
        }
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        int ret = 0;
        if(!stk.empty())
        {
            t = stk.top();
            stk.pop();
            ret = t->val;
            t = t->right;
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

class BSTIterator2 {
public:
    BSTIterator(TreeNode *root) {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ret = stk.top()->val;
        TreeNode *cur = stk.top()->right;
        stk.pop();
        while(cur)
        {
            stk.push(cur);
            cur = cur->left;
        }
        return ret;
    }
private:
    stack<TreeNode *> stk;
};
