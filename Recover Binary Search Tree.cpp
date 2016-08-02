/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //inorder morris traversal
 //If no swap, should be ascending order;
 
class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode *cur = root, *prev;
        TreeNode *s1 = nullptr, *s2 = nullptr, *ans1 = nullptr, *ans2 = nullptr;
        while(cur)
        {
            if(!cur->left)
            {  
               s1 = s2;
               s2 = cur;
               cur = cur->right;
               if(s1 && (s2->val <= s1->val))
               {
                   if(!ans1)
                   {
                       ans1 = s1;
                   }
                   ans2 = s2;
               }
            }
            else
            {
                prev = cur->left;
                while(prev->right && prev->right != cur)
                    prev = prev->right;
                if(!prev->right)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    s1 = s2;
                    s2 = cur;
                    cur = cur->right;
                    if(s1 && (s2->val <= s1->val))
                    {
                        if(!ans1)
                        {
                            ans1 = s1;
                        }
                        ans2 = s2;
                    }
                    prev->right = nullptr;
                }
            }
        }
        // cout << ans1->val << ans2->val << endl;
        if(ans1 && ans2)
            swap(ans1->val, ans2->val);
    }
};
