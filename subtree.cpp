//if Tree A is the subtree of Tree B?
#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool ifEqual(TreeNode* p, TreeNode* q) {
	if (!p && !q) return true;
	if (!p || !q) return false;
	//p == q : address compare
	//p->val == q->val : value compare (no duplicate value in this tree)
	if (p->val != q->val) return false;
	return ifEqual(p->left, q->left) && ifEqual(p->right, q->right);
}

bool ifSubtree(TreeNode* A, TreeNode* B) {
	if (!A) return true;
	if (!B) return false;
	if (A->val == B->val) {
		cout << A->val << " " << B->val << endl;
		return ifEqual(A, B);
	}
	return ifSubtree(A, B->left) || ifSubtree(A, B->right);

}















int main() {
	TreeNode* head = new TreeNode(3);
	head->left = new TreeNode(4);
	head->right = new TreeNode(2);
	//TreeNode* head2 = head->right;
	head->right->left = new TreeNode(1);
	head->right->right = new TreeNode(5);

	TreeNode* head2 = new TreeNode(2);
	head2->left = new TreeNode(1);
	head2->right = new TreeNode(5);

	if (ifSubtree(head2, head)) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}