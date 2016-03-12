/*
    The thief has found himself a new place for his thievery again. There is only 
        one entrance to this area, called the "root." Besides the root, each house 
        has one and only one parent house. After a tour, the smart thief realized 
        that "all houses in this place forms a binary tree". It will automatically 
        contact the police if two directly-linked houses were broken into on the 
        same night.

    Determine the maximum amount of money the thief can rob tonight without alerting 
        the police.

        Example 1:
             3
            / \
           2   3
            \   \ 
             3   1
        Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
        
        Example 2:
             3
            / \
           4   5
          / \   \ 
         1   3   1
        Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

class Solution {
public:
    int rob(TreeNode* root) 
    {
        auto ret = postOrder(root);
        return max(ret.first, ret.second);
    }
private:
    pair<int, int> postOrder(TreeNode *node)
    {
        if (!node) return {0,0};
        
        auto left = postOrder(node->left);
        auto right = postOrder(node->right);

        pair<int, int> ret;
        ret.first = max(left.first, left.second) + max(right.first, right.second);
        ret.second = node->val + left.first + right.first;

        return ret;
    }
};
