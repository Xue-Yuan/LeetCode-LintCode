/*
    Given an integer array nums, find the sum of the elements between 
        indices i and j (i ≤ j), inclusive.

    The update(i, val) function modifies nums by updating the element 
        at index i to val.

    Example:
        Given nums = [1, 3, 5]

        sumRange(0, 2) -> 9
        update(1, 2)
        sumRange(0, 2) -> 8

    Note:
        The array is only modifiable by the update function.
        You may assume the number of calls to update and sumRange 
            function is distributed evenly.
*/

class NumArray 
{
private:
    struct Node
    {
        int val;
        int beg, end;
        Node *left, *right;
        Node(int v, int b, int e): val(v), beg(b), end(e), left(nullptr), right(nullptr){} 
    };
    vector<int> arr;
    Node *root;
public:
    NumArray(vector<int> &nums): arr(nums), root(nullptr) 
    {
        buildTree(root, 0, (int)arr.size() - 1);
    }
    ~NumArray() {destory(root);}
    void update(int i, int val) 
    {
        if (i < 0 || i >= (int)arr.size()) return;
        int dif = val - arr[i];
        arr[i] = val;
        update(root, i, dif);
    }

    int sumRange(int i, int j) 
    {
        return sumRange(root, i, j);
    }
private:
    int buildTree(Node *&t, int b, int e)
    {
        if (b > e) return 0;
        if (b == e)
        {
            t = new Node(arr[b], b, e);
            return arr[b];
        }
        int m = b + (e - b) / 2;
        t = new Node(0, b, e);
        return t->val = buildTree(t->left, b, m) + buildTree(t->right, m + 1, e);
    }
    
    int sumRange(Node *t, int i, int j)
    {
        if (!t || t->end < i || t->beg > j) return 0;
        if (i <= t->beg && t->end <= j) return t->val;
        return sumRange(t->left, i, j) + sumRange(t->right, i, j);
    }
    
    void update(Node *t, int i, int dif)
    {
        if (!t || t->end < i || t->beg > i) return;
        t->val += dif;
        update(t->left, i, dif);
        update(t->right, i, dif);
    }
    
    void destory(Node *t)
    {
        if (!t) return;
        if (t->left) destory(t->left);
        if (t->right) destory(t->right);
        delete t;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);