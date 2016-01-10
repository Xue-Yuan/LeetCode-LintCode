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

struct Node
{
    int val;
    int cnt;    //data rooted at this node.
    Node *left, *right;
    Node(int v, int c): val(v), cnt(c), left(nullptr), right(nullptr) {}
};

//When duplicates happens, no extra nodes inserted. Simply increment
//  the cnt.
class Solution
{
private:
    int insert(Node *&root, int data, int acc)
    {
        if (!root)
        {
            root = new Node(data, 1);
            return acc;
        }
        root->cnt++;
        if (data == root->val)
            return (root->left ? root->left->cnt : 0) + acc;
        if (data < root->val)
            return insert(root->left, data, acc);
        //data > root->val
        return insert(root->right, data, acc + root->cnt - 1 - (root->right ? root->right->cnt : 0));
    }
    void destory(Node *root)
    {
        if (!root) return;
        destory(root->left);
        destory(root->right);
        delete root;
    }
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> ret(nums.size());
        for (int i = (int)nums.size() - 1; i >= 0; --i)
            ret[i] = insert(root, nums[i], 0);
        destory(root);
        return ret;
    }
private:
    Node *root = nullptr;
};

class Solution2
{
private:
    //We can use the STL lower_bound. I just wanna practice.
    int lower_bound(const vector<int> &vec, const int &target)
    {
        if (vec.empty()) return 0;
        int b = 0, e = (int)vec.size();
        while (b < e)
        {
            int m = b + (e - b) / 2;
            if (vec[m] < target) b = m + 1;
            else e = m;
        }           
        return b;
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

//Merge sort solution. Instead of actually sort the nums array, we
//  only record the position of the indices, by doing so we also do
//  not have to re-locate the results.
class Solution3
{
private:
    void merge_countSmaller(vector<int>& indices, int first, int last, vector<int>& results, vector<int>& nums)
    {
        int count = last - first;
        if (count > 1)
        {
            int step = count / 2;
            int mid = first + step;
            merge_countSmaller(indices, first, mid, results, nums);
            merge_countSmaller(indices, mid, last, results, nums);
            vector<int> tmp;
            tmp.reserve(count);
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            while (idx1 < mid && idx2 < last)
            {
                if (nums[indices[idx1]] <= nums[indices[idx2]])
                {
                    tmp.push_back(indices[idx1]);
                    results[indices[idx1]] += semicount;
                    ++idx1;
                }
                else
                {
                    tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            while (idx1 < mid)
            {
                tmp.push_back(indices[idx1]);
                results[indices[idx1]] += semicount;
                ++idx1;
            }
            while (idx2 < last) tmp.push_back(indices[idx2++]);
            move(tmp.begin(), tmp.end(), indices.begin()+first);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<int> results(n, 0);
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        merge_countSmaller(indices, 0, n, results, nums);
        return results;
    }
};
