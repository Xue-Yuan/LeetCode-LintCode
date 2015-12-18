/*
    You are given an integer array nums and you have to return a new 
        counts array. The counts array has the property where counts[i] 
        is the number of smaller elements to the right of nums[i].

    Example:

        Given nums = [5, 2, 6, 1]

        To the right of 5 there are 2 smaller elements (2 and 1).
        To the right of 2 there is only 1 smaller element (1).
        To the right of 6 there is 1 smaller element (1).
        To the right of 1 there is 0 smaller element.

    Return the array [2, 1, 1, 0].
*/

/*
    A common idea is to insert from the right, and thus find the number of smaller value.
 
    A sorted sequence is needed to speed up the searching. Any kind of sorting will work.
*/

struct treeNode
{
    int val;
    int cnt;    //number of subtree nodes + root
    treeNode *left;
    treeNode *right;
    treeNode(int _v, int _c):val(_v), cnt(_c), left(nullptr), right(nullptr){}
};

class Solution
{
private:
    int insert(treeNode *&root, int num, int accumulated_cnt)
    {
        if (!root)
        {
            root = new treeNode(num, 1);
            return 0;
        }
        //If duplicates happens, no extra node will be added. Instead
        //  increment the node->cnt.
        (root->cnt)++;
        if (num == root->val)
            return (root->left ? root->left->cnt : 0) + accumulated_cnt;
        if (num > root->val)
        {
            if (!root->right) root->right = new treeNode(num, 0);
            return insert(root->right, num, accumulated_cnt + root->cnt - root->right->cnt - 1);  //left subtree nodes and the root itself
        }
        
        if (!root->left) root->left = new treeNode(num, 0);
        return insert(root->left, num, accumulated_cnt);
    }
    
    void destoryTree(treeNode *root)
    {
        if (!root) return;
        destoryTree(root->left);
        destoryTree(root->right);
        delete root;
    }
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        if (nums.empty()) return {};
        
        vector<int> ret(nums.size());
        treeNode *root = nullptr;
        
        for (int i = (int)nums.size() - 1; i >= 0; --i)
            ret[i] = insert(root, nums[i], 0);
        
        destoryTree(root);
        return ret;
    }
};

class Solution2
{
private:
    //We can use the STL lower_bound. I just wanna practice.
    int lower_bound(const vector<int> &vec, const int &target)
    {
        if (vec.empty()) return 0;
        int b = 0, e = (int)vec.size() - 1;
        while (b < e)
        {
            int m = b + (e - b) / 2;
            if (vec[m] < target)
                b = m + 1;
            else
                e = m;
        }
        
        return (vec[b] >= target ? b : e + 1);
    }
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        if (nums.empty()) return {};
        
        vector<int> ret(nums.size()), rightNums;
        
        for (int i = (int)nums.size() - 1; i >= 0; --i)
        {
            int idx = lower_bound(rightNums, nums[i]);
            ret[i] = idx;
            rightNums.insert(rightNums.begin() + idx, nums[i]);
        }

        return ret;
    }
};
