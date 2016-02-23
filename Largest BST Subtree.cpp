/*
    Given a binary tree, find the largest subtree which is a Binary Search 
        Tree (BST), where largest means subtree with largest number of nodes in it.

    Note:
        A subtree must include all of its descendants.
    
    Here's an example:
            10
            / \
           5  15
          / \   \ 
         1   8   7

    The Largest BST Subtree in this case is the highlighted one. 
    The return value is the subtree's size, which is 3.
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

//O(nlogn)
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (isValidBST(root, nullptr, nullptr))
            return count(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
private:
    bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (!root) return true;
        
        if (minNode && root->val <= minNode->val || 
            maxNode && root->val >= maxNode->val) return false;
            
        return isValidBST(root->left, minNode, root) && 
            isValidBST(root->right, root, maxNode);
    }
    int count(TreeNode *root)
    {
        if (!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }
};


//O(n)
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) 
    {
        largest = 0;
        helper(root);
        return largest;
    }
private:
    struct triplet
    {
        int cnt;
        TreeNode *minNode = nullptr;
        TreeNode *maxNode = nullptr;
        triplet(int c): cnt(c){};
    };
    triplet helper(TreeNode *root)
    {
        if (!root) return triplet(0);
        
        triplet left = helper(root->left);
        triplet right = helper(root->right);
        
        largest = max(max(largest, left.cnt), right.cnt);
        if (left.cnt < 0 || right.cnt < 0)
            return triplet(-1);
        if (left.maxNode && left.maxNode->val >= root->val) 
            return triplet(-1);
        if (right.minNode && right.minNode->val <= root->val)
            return triplet(-1);
            
        triplet ret(0);
        ret.minNode = left.minNode ? left.minNode : root;
        ret.maxNode = right.maxNode ? right.maxNode : root;
        ret.cnt = left.cnt+right.cnt+1;
        largest = max(largest, ret.cnt);
        return ret;
    }
private:
    int largest;
};
