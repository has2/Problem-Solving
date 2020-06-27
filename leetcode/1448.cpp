
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:

	int search(TreeNode* node, int v) {

		if (node == nullptr) return 0;
 
		int ret = 0;
		int cur_max = v;
		if (node->val >= v) {
			cur_max = node->val;
			ret++;
		}
		ret += search(node->left,  cur_max);
		ret += search(node->right, cur_max);

		return ret;
	}

	int goodNodes(TreeNode* root) {
		return search(root, -100000);
	}
};
