#include <cstdio>
#include <vector>
using namespace std;
 //struct TreeNode {
 //     int val;
 //     TreeNode *left;
 //     TreeNode *right;
 //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 //};
 vector<int> num;
 void inorder(TreeNode* node) {
	 
	 if (node == nullptr) return;

	 inorder(node->left);
	 num.push_back(node->val);
	 inorder(node->right);

 }
class Solution {
public:
	TreeNode* increasingBST(TreeNode* root) {
		inorder(root);

		TreeNode* ret = new TreeNode(num[0]);
		TreeNode* tmp = ret;
		for (int i = 1; i < num.size(); i++) {
			TreeNode* node = new TreeNode(num[i]);
			tmp->right = node;
			tmp = tmp->right;
		}
        num.clear();
		return ret;
	}
};
