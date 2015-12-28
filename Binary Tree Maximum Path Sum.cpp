/*
    Given a binary tree, find the maximum path sum.

    For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

    For example:
    Given the below binary tree,

           1
          / \
         2   3
    Return 6.
*/

/*
    My first trial was a naive graph DFS, starting from every node 
        and reaching out, which gave me a O(N^2) time complexity.
*/

/*
    The idea is also DFS. From bottom to up, at every node, we have 
        four choices:

    the left sub-path ==> node ==> the right sub-path

    the left sub-path ==> node ==> upper. The left sub-path may 
        yield a negative sum, in which case we set node->left sub-path 
        to zero.

    the right sub-path ==> node ==>upper. The right sub-path may yield 
        a negative sum, in which case we set node->right sub-path to zero.

    0 ==> upper, which means we abandon the entire tree rooted at this 
        node because of a negative sum.

    Noted: Negative node values are possible.
*/
class Solution
{
private:
    int maxPathSum(TreeNode *root, int &ma)
    {
        if (!root) return 0;

        int left =  maxPathSum(root->left, ma);
        int right = maxPathSum(root->right, ma);
        ma = max(ma, root->val + left + right);

        return max(max(0, max(left, right)) + root->val, 0);
    }

public:
    int maxPathSum(TreeNode* root)
    {
        if (!root) return INT_MIN;
        
        int ma = root->val;        
        maxPathSum(root, ma);
        
        return ma;
    }    
};