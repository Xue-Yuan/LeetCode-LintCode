// Seems like I got a stack overflow problem.
/*
Test case:
[3,4,6,5]
[9,1,2,5,8,3]
5
[6, 7]
[6, 0, 4]
5
[3, 9]
[8, 9]
3
[2,5,6,4,4,0]
[7,3,8,0,6,5,7,6,2]
10
[3,3,1,8,2,4,2,9,2,4,7,1,9,2,3,4,0,7,5,4]
[9,7,7,1,3,6,8,6,9,6,0,4,3,6,6,1,0,4,6,2,2,6,4,6,0,4,9,7,4,9,8,4,9,8,4,6,6,5,8,2,8,6,6,6,1,0,9,0,8,0,4,0,4,4,1,7,9,8,4,2,2,0,3,2,3,9,1,8,9,5,2,7,9,2,7,7,8,5,4,4,8,6,5,5,9,6,1,4,6,0,8,5,3,4,2,0,0,9,5,2]
100
[6,9,2,3,6,7,9,9,0,9,6,2,3,3,3,4,7,4,5,6,8,5,0,4,9,9,0,7,8,5,0,0,3,7,9,3]
[1,6,5,7,6,0,6,5,1,0,1,0,8,2,7,4,5,4,2,6,2,4,0,1,3,9,6,0,1,3,0,1,5,3,5,1,7,2,8,3,1,9,0,3,4,5,1,7,6,1,5,9,8,5,9,9,8,7,6,0,3,9,0,2,8,7,5,4,0,5,1,8,3,2,2,7,8,9,8,5,7,4,8,1,1,1,6,5,7,1,1,4,0,4,2,3,3,3,6,2,0,2,1,3,7,9,7,2,8,0,6,9,0,2,1,8,4,6,7,9,2,5,9,4,6,1,9,5,7,9,4,1,0,6,8,0,1,3,9,4,2,9,8,0,6,9,0,7,3,4,6,2,4,8,3,2,4,1,8,3,8,1,3,9,0,9,3,5,8,2,7,5,3,7,3,1,3,5,9,8]
180
*/
class segmentTree
{
private:
    struct segmentTreeNode
    {
        int val;
        int start, end, max_idx;
        segmentTreeNode *left;
        segmentTreeNode *right;
        segmentTreeNode(int s, int e):val(0), start(s), end(e), left(nullptr), right(nullptr){}
    };
    vector<int> nums;
    segmentTreeNode *tree;
public:
    segmentTree(vector<int> &nums): nums(nums)
    {
        tree = buildTree(0, (int)this->nums.size() - 1, this->nums);
    }
    pair<int, int> rangeMax(int i, int j) {return getMax(tree, i, j);}
    ~segmentTree() {destoryTree(tree);}
private:
    segmentTreeNode* buildTree(int start, int end, vector<int> &nums)
    {
        if(start > end) return nullptr;
        segmentTreeNode *root = new segmentTreeNode(start, end);
        
        if(start == end)
        {
            root->val = nums[start];
            root->max_idx = start;
        }
        else
        {
            int mid = start + (end - start) / 2;
            root->left = buildTree(start, mid, nums);
            root->right = buildTree(mid + 1, end, nums);
            if (root->left->val >= root->right->val)
            {
                root->val = root->left->val;
                root->max_idx = root->left->max_idx;
            }
            else
            {
                root->val = root->right->val;
                root->max_idx = root->right->max_idx;
            }
        }
        return root;
    }
    pair<int, int> getMax(segmentTreeNode *root, int i, int j)
    {
        if(!root || j < root->start || i > root->end) return {INT_MIN, -1};
        if(i <= root->start && j >= root->end) return {root->val, root->max_idx};
        
        auto left = getMax(root->left, i, j), right = getMax(root->right, i, j);
        return left.first >= right.first ? left : right;
    }
    void destoryTree(segmentTreeNode *root)
    {
        if (!root) return;
        destoryTree(root->left);
        destoryTree(root->right);
        delete root;
    }
};

class Solution
{
    using PII = pair<int, int>;
    using ITR = vector<int>::iterator;
private:
    int range(segmentTree &t1, PII r1, PII &p1, segmentTree &t2, PII r2, PII &p2, int k)
    {
        bool r1_invalid = r1.first > r1.second;
        bool r2_invalid = r2.first > r2.second;
        p1 = t1.rangeMax(r1.first, r1.second);
        p2 = t2.rangeMax(r2.first, r2.second);
        
        if (r2_invalid || p1.first > p2.first)
        {
            if (N1 - p1.second + (r2_invalid ? 0 : N2 - r2.first) < k)
                return range(t1, {r1.first, p1.second - 1}, p1, t2, r2, p2, k);
            return 1;
        }
        else if (r1_invalid || p1.first < p2.first)
        {
            if ((r1_invalid ? 0 : N1 - r1.first) + N2 - p2.second < k)
                return range(t1, r1, p1, t2, {r2.first, p2.second - 1}, p2, k);
            return 2;
        }
        else
        {
			if (N1 - p1.second + N2 - p2.second >= k) return 1;
            PII tmp1, tmp2;
            int ret = range(t1, {r1.first, p1.second - 1}, tmp1, t2, {r2.first, p2.second - 1}, tmp2, k);
            return ret == 1 ? 2 : 1;

        }
    }
    void merge(ITR b1, ITR e1, ITR b2, ITR e2, ITR b3)
    {
        while (b1 != e1 && b2 != e2)
        {
            if (*b1 > *b2) *b3++ = *b1++;
            else if (*b1 < *b2) *b3++ = *b2++;
            else
            {
                auto pos1 = b1, pos2 = b2;
                while (true)
                {
                    int f1 = (++pos1 != e1) ? *(pos1) : INT_MIN;
                    int f2 = (++pos2 != e2) ? *(pos2) : INT_MIN;
                    if (f1 > f2) { *b3++ = *b1++; break;}
                    else if (f1 < f2) {*b3++ = *b2++; break;}
                    else if (f1 == INT_MIN && f2 == INT_MIN) {*b3++ = *b2++; break;}
                }
            }
        }
        while (b1 != e1) *b3++ = *b1++;
        while (b2 != e2) *b3++ = *b2++;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<int> res(k);
        N1 = (int)nums1.size(), N2 = (int)nums2.size();
        PII r1(0, N1 - 1), r2(0, N2 - 1);
        segmentTree t1(nums1), t2(nums2);
        int idx = 0;
   
        while (k)
        {
            if (N1 - r1.first + N2 - r2.first == k)
            {
                merge(nums1.begin() + r1.first, nums1.end(), nums2.begin() + r2.first, nums2.end(), res.begin() + idx);
                return res;
            }
            PII p1, p2;
            int ret = range(t1, r1, p1, t2, r2, p2, k);
            if (ret == 1)
            {
                r1.first = p1.second + 1;
                res[idx++] = p1.first;
                k--;
            }
            else
            {
                r2.first = p2.second + 1;
                res[idx++] = p2.first;
                k--;
            }
        }
        return res;
    }
private:
    int N1, N2;
};