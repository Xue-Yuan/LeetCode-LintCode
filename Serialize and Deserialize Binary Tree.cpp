/*
    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

    For example, you may serialize the following tree

        1
       / \
      2   3
         / \
        4   5
    as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

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
class Codec 
{
private:
    void serialize(TreeNode *root, ostream &out)
    {
        if(!root)
        {
            out << "# ";
            return;
        }
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    }
    TreeNode *deserialize(istream &in)
    {
    	string str;
    	in >> str;
    	if(str == "#")
    		return nullptr;
    	TreeNode *t = new TreeNode(stoi(str));
    	t->left = deserialize(in);
    	t->right = deserialize(in);
    	return t;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream in(data);
        return deserialize(in);
    }

    void print(TreeNode *root)
    {
    	if(!root) return;
    	cout << root->val << ' ';
    	print(root->left);
    	print(root->right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));