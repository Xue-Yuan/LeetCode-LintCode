/*
    Given a binary tree, return all root-to-leaf paths.

    For example, given the following binary tree:

       1
     /   \
    2     3
     \
      5
    All root-to-leaf paths are:

    ["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if (!root) return {};
        vector<string> ret;
        dfs(root, "", ret);
        return ret;
    }
private:
    void dfs(TreeNode *t, string path, vector<string> &ret)
    {
        path += to_string(t->val);
        if (!t->left && !t->right)
        {
            ret.push_back(path);
            return;
        }
        if (t->left)
            dfs(t->left, path+"->", ret);
        if (t->right)
            dfs(t->right, path+"->", ret);
    }
};

class Solution2 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        TreeNode *curNode;
        string curPath;
        stack<pair<TreeNode*, string>> liveNodes;
        if(root) liveNodes.push(make_pair(root, ""));
        while(!liveNodes.empty())
        {
            curNode = liveNodes.top().first;
            curPath = liveNodes.top().second;
            liveNodes.pop();
            if(!curNode->left && !curNode->right)
            {
                res.push_back(curPath + std::to_string(curNode->val));
            }
            else
            {
                if(curNode->left)  liveNodes.push(make_pair(curNode->left, curPath + std::to_string(curNode->val)+ "->"));
                if(curNode->right) liveNodes.push(make_pair(curNode->right, curPath + std::to_string(curNode->val)+ "->"));
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<pair<TreeNode*, string>> liveNodes[2];
        int cur=0, next=1;
        TreeNode* curNode;
        string curPath;
        vector<string> res;

        if(root) liveNodes[cur].push(make_pair(root, ""));
        while(!liveNodes[cur].empty())
        {
            curNode = liveNodes[cur].front().first;
            curPath = liveNodes[cur].front().second;
            liveNodes[cur].pop();
            if(!curNode->left && !curNode->right) res.push_back(curPath + std::to_string(curNode->val));
            else{
                if(curNode->left)  liveNodes[next].push(make_pair(curNode->left,  curPath + std::to_string(curNode->val) + "->"));
                if(curNode->right) liveNodes[next].push(make_pair(curNode->right, curPath + std::to_string(curNode->val) + "->"));
            }
            if(liveNodes[cur].empty()) swap(cur, next);
        }
        return res;
    }
};
