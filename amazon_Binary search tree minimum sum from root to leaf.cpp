int solution(TreeNode *root) {
	if (!root) {
		return 0;
	}
	return min(solution(root->left), solution(root->right)) + root->val;
}
