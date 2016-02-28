/*
    Given an integer array nums, return the number of range sums that 
        lie in [lower, upper] inclusive.
    Range sum S(i, j) is defined as the sum of the elements in nums 
        between indices i and j (i ≤ j), inclusive.
    Note:
        A naive algorithm of O(n2) is trivial. You MUST do better than 
            that.
    Example:
        Given nums = [-2, 5, -1], lower = -2, upper = 2,
        Return 3.
        The three ranges are : [0, 0], [2, 2], [0, 2] and their 
            respective sums are: -2, -1, 2.
*/

struct Node
{
    long long val;
    int cnt;
    Node *left, *right;
    Node(long long v, int c): val(v), cnt(c), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    BST(): root(nullptr) {}
    void insert(long long val) { insert(root, val); }
    int smallerThan(long long val) { return smallerThan(root, val); }
    ~BST() { destory(root); }
private:
    void insert(Node *&t, long long val)
    {
        if (!t)
        {
            t = new Node (val, 1);
            return;
        }
        t->cnt++;
        if (t->val == val) return;
        else if (t->val < val) insert(t->right, val);
        else insert(t->left, val);
    }

    int smallerThan(Node *&t, long long val)
    {
        if (!t) return 0;
        if (t->val == val) return t->left ? t->left->cnt : 0;
        else if (t->val > val) return smallerThan(t->left, val);
        else return t->cnt - (t->right ? t->right->cnt : 0) + smallerThan(t->right, val);
    }
    
    void destory(Node *t)
    {
        if (!t) return;
        if (t->left) destory(t->left);
        if (t->right) destory(t->right);
        delete t;
    }
private:
    Node *root;
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        int ret = 0;
        BST bst;
        bst.insert(0);
        for (int &i : nums)
        {
            sum += i;
            int low = bst.smallerThan(sum - lower + 1);
            int high = bst.smallerThan(sum - upper);
            ret += low - high;
            bst.insert(sum);
        }
        return ret;
    }
};
