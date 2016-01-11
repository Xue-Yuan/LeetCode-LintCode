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

class Tree
{
private:
    struct Node 
    {
        long long val;
        int cnt;
        Node* left, *right;
        Node(long long v): val(v), cnt(1), left(nullptr), right(nullptr){}
    };

    void insert(Node *&root, long long val)
    {
        if (!root) 
        {
            root = new Node(val);
            return;
        }
        root->cnt++;
        if (root->val == val) return;
        else if (root->val < val) insert(root->right, val);
        else insert(root->left, val);
    }

    int greaterThan(Node *root, long long val, int res)
    {
        if (!root) return res;
        if (root->val > val)
        {
            int tmp = root->cnt - (root->left ? root->left->cnt : 0);
            return greaterThan(root->left, val, res + tmp);
        }
        else if (root->val == val) return res + (root->right ? root->right->cnt : 0);
        else return greaterThan(root->right, val, res);
    }

    void destoryTree(Node *root)
    {
        if (!root) return;
        destoryTree(root->left);
        destoryTree(root->right);
        delete root;
    }
public:
    Tree(): root(nullptr) {}
    ~Tree() {destoryTree(root);}
    void insert(long long val) {insert(root, val);}    
    int greaterThan(long long val) {return greaterThan(root, val, 0);}
private:
    Node* root;
};

class Solution 
{
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        Tree tree;
        tree.insert(0);
        long long sum = 0;
        int res = 0;
        for(int &i : nums)
        {
            sum += i;
            int lo = tree.greaterThan(sum - lower);
            int hi = tree.greaterThan(sum - upper - 1);
            res += hi - lo;
            tree.insert(sum);
        }
        return res;
    }
};