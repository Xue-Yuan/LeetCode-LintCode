/*
    Given a root of Binary Search Tree with unique value for each node.  
        Remove the node with given value. If there is no such a node with 
        given value in the binary search tree, do nothing. You should 
        keep the tree still a binary search tree after removal.
*/
class Solution 
{
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) 
    {
        // write your code here
        TreeNode *cur = root, ph(0), *pre = &ph;
        ph.right = root;
        //find the node
        while (cur)
        {
            if (cur->val == value) break;
            pre = cur;
            if (value < cur->val) cur = cur->left;
            else if (value > cur->val) cur = cur->right;
        }
        //not exist
        if (!cur) return root;  
        //This node has both a left and right subtree.
        //  Make the left subtree of cur be the subtree of pre,
        //  and the right subtree of cur be the right subtree of
        //  the right-most node of left subtree.
        if (cur->left && cur->right) 
        {
            if (pre->left == cur) pre->left = cur->left;
            else pre->right = cur->left;
            TreeNode *tmp = cur->left;
            while (tmp->right) tmp = tmp->right;
            tmp->right = cur->right;
        }
        else
        {
            TreeNode *tmp = cur->left ? cur->left : cur->right;
            if (pre->left == cur) pre->left = tmp;
            else pre->right = tmp;
        }
        delete cur;
        return ph.right;
    }
};

//This may be the preferred solution.
class Solution2 
{
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) 
    {
        // write your code here
        TreeNode *cur = root, ph(0), *pre = &ph;
        ph.right = root;
        //find the node
        while (cur)
        {
            if (cur->val == value) break;
            pre = cur;
            if (value < cur->val) cur = cur->left;
            else if (value > cur->val) cur = cur->right;
        }
        //not exist
        if (!cur) return root; 
        //This node has both a left and right subtree.
        //  We can also replace the cur with the largest from
        //  the left subtree of cur (or the smallest from the
        //  right subtree), then delete the largest (or smallest)
        //  node. That node is guaranteed to have at most one subtree.
        if (cur->left && cur->right) 
        {
            TreeNode *tmp = cur->left;
            while (tmp->right) tmp = tmp->right;
            cur->val = tmp->val;
            cur->left = removeNode(cur->left, tmp->val);
        }
        else
        { 
            TreeNode *tmp = cur->left ? cur->left : cur->right;
            if (pre->left == cur) pre->left = tmp;
            else pre->right = tmp;
            delete cur;
        }
        return ph.right;
    }
};

//recursion
class Solution3 
{
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) 
    {
        // write your code here
        if (!root) return root;
        if (value == root->val)
        {
            if (root->left && root->right)
            {
                TreeNode *tmp = root->left;
                while (tmp->right) tmp = tmp->right;
                root->val = tmp->val;
                root->left = removeNode(root->left, tmp->val);
                return root;
            }
            TreeNode *tmp = root->left ? root->left : root->right;
            delete root; //including just a leaf
            return tmp;
        }
        else if (value < root->val) root->left = removeNode(root->left, value);
        else root->right = removeNode(root->right, value);  
        return root;
    }
};
