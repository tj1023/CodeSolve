#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
	char value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* addNode(int value, unordered_map<int, TreeNode*>& nodes) {
	if (nodes.find(value) == nodes.end())
		nodes[value] = new TreeNode(value);
	return nodes[value];
}

TreeNode* buildTree(int n) {
	unordered_map<int, TreeNode*> nodes;
	TreeNode* root = nullptr;

	for (int i = 0; i < n; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;

		TreeNode* parentNode = addNode(parent, nodes);
		if (root == nullptr) root = parentNode;
		if (left != '.') parentNode->left = addNode(left, nodes);
		if (right != '.') parentNode->right = addNode(right, nodes);
	}
	return root;
}

void preorder(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->value;
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode* root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->value;
	inorder(root->right);
}

void postorder(TreeNode* root) {
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->value;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	TreeNode* root = buildTree(n);
	preorder(root); cout << '\n';
	inorder(root); cout << '\n';
	postorder(root); cout;

	return 0;
}