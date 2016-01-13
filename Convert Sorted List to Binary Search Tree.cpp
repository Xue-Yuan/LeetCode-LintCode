/*
    Given a singly linked list where elements are sorted in ascending 
        order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
private:
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
        if (head == tail) return nullptr;
        ListNode *fast = head, *slow = head;
        while (fast != tail && fast->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, tail);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        return sortedListToBST(head, nullptr);
    }
};
