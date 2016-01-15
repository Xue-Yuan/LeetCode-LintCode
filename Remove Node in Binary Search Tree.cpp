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
        //This node is a leaf.
        if (!cur->left && !cur->right)  
        {
            if (pre->left == cur) pre->left = nullptr;
            else pre->right = nullptr;
            delete cur;
        }
        //This node only has a right subtree.
        //  Make the right substree of cur be the subtree of pre.
        else if (!cur->left)
        {
            if (pre->left == cur) pre->left = cur->right;
            else pre->right = cur->right;
            delete cur;
        }
        //This node only has a left subtree.
        //  Make the left subtree of cur be the subtree of pre.
        else if (!cur->right)
        {
            if (pre->left == cur) pre->left = cur->left;
            else pre->right = cur->left;
            delete cur;
        }
        //This node has both a left and right subtree.
        //  Make the left subtree of cur be the subtree of pre,
        //  and the right subtree of cur be the right subtree of
        //  the right-most node of left subtree.
        else 
        {
            if (pre->left == cur) pre->left = cur->left;
            else pre->right = cur->left;
            TreeNode *tmp = cur->left;
            while (tmp->right) tmp = tmp->right;
            tmp->right = cur->right;
            delete cur;
        }
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
        //This node is a leaf.
        if (!cur->left && !cur->right)  
        {
            if (pre->left == cur) pre->left = nullptr;
            else pre->right = nullptr;
            delete cur;
        }
        //This node only has a right subtree.
        //  Make the right substree of cur be the subtree of pre.
        else if (!cur->left)
        {
            if (pre->left == cur) pre->left = cur->right;
            else pre->right = cur->right;
            delete cur;
        }
        //This node only has a left subtree.
        //  Make the left subtree of cur be the subtree of pre.
        else if (!cur->right)
        {
            if (pre->left == cur) pre->left = cur->left;
            else pre->right = cur->left;
            delete cur;
        }
        //This node has both a left and right subtree.
        //  We can also replace the cur with the largest from
        //  the left subtree of cur (or the smallest from the
        //  right subtree), then delete the largest (or smallest)
        //  node. That node is guaranteed to have at most one subtree.
        else 
        {
            TreeNode *tmp = cur->left;
            while (tmp->right) tmp = tmp->right;
            cur->val = tmp->val;
            cur->left = removeNode(cur->left, tmp->val);
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
    TreeNode* removeNode(TreeNode* cur, int value) 
    {
        // write your code here
        if (!cur) return cur;
        if (value == cur->val)
        {
            if (cur->left && cur->right)
            {
                TreeNode *tmp = cur->left;
                while (tmp->right) tmp = tmp->right;
                cur->val = tmp->val;
                cur->left = removeNode(cur->left, tmp->val);
                return cur;
            }
            TreeNode *tmp = nullptr;
            //only right subtree
            if (!cur->left && cur->right) tmp = cur->right;
            //only left subtree
            else if (!cur->right && cur->left) tmp = cur->left;
            delete cur; //including just a leaf
            return tmp;
        }
        else if (value < cur->val) cur->left = removeNode(cur->left, value);
        else cur->right = removeNode(cur->right, value);  
        return cur;
    }
};
