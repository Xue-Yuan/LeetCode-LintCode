/*
    Given a binary search tree, write a function kthSmallest to find the 
        kth smallest element in it.

    Note: 
        You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

    Follow up:
        What if the BST is modified (insert/delete operations) often and you 
            need to find the kth smallest frequently? How would you optimize 
            the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        return preorder(root, k)->val;
    }
private:
    TreeNode* preorder(TreeNode *root, int &k)
    {
        if (!root) return nullptr;
        TreeNode *tmp;
        if (tmp = preorder(root->left, k))
            return tmp;
        if (--k == 0) return root;
        if (tmp = preorder(root->right, k))
            return tmp;
        return nullptr;
    }
};

//For follow up, save addtional information of how many nodes are rooted in
//  the current node;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     int cnt;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root) return -1;
        int left = root->left ? root->left->cnt : 0;
        int right = root->right ? root->right->cnt : 0;
        if (k == root->cnt - right)
            return root->val;
        else if (k < root->cnt - right)
            return kthSmallest(root->left, k);
        else return kthSmallest(root->right, k - left - 1);
    }
};
