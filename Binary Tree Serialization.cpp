/*
    Design an algorithm and write code to serialize and deserialize a 
        binary tree. Writing the tree to a file is called 'serialization' 
        and reading back from the file to reconstruct the exact same 
        binary tree is 'deserialization'.

    There is no limit of how you deserialize or serialize a binary tree, 
        you only need to make sure you can serialize a binary tree to a 
        string and deserialize this string to the original structure.

    Example
        An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote 
            the following structure:

          3
         / \
        9  20
          /  \
         15   7
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution 
{
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) 
    {
        // write your code here
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) 
    {
        // write your code here
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (!root)
        {
            out << "# ";
            return;
        }
        out << root->val << " ";
        serialize(root->left, out);
        serialize(root->right, out);
    }
    TreeNode *deserialize(istringstream &in)
    {
        string str;
        in >> str;
        if (str == "#") return nullptr;

        TreeNode *cur = new TreeNode(stoi(str));
        cur->left = deserialize(in);
        cur->right = deserialize(in);
        return cur;
    }
};
