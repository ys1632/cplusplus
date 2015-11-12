#include <iostream>

using namespace std;


struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoList(ListNode* p, ListNode* q) {
	if (!p) return q;
	if (!q) return p;
	ListNode* start = new ListNode(99);
	ListNode* cur;
	if (p->val > q->val) {
		cur = q;
		q = q->next;
	}
	else {
		cur = p;
		p = p->next;
	}
	cout << cur->val << endl;
	start->next = cur;

	while (p && q) {
		if (p->val > q->val) {
			cur->next = q;
			q = q->next;
		}
		else {
			cur->next = p;
			p = p->next;
		}
		cur = cur->next;
	}

	if (!q) cur->next = p;
	else cur->next = q;

	cur = start->next;
	delete start;
	return cur;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode * ans = NULL;
        
        if (l1->val < l2->val) {
            ans = l1;
            ans->next = mergeTwoLists(l1->next, l2);
        }
        else {
            ans = l2;
            ans->next = mergeTwoLists(l1, l2->next);
        }
        
        return ans;
}

int main() {
	ListNode* a = new ListNode(1);
	a->next = new ListNode(3);
	a->next->next = new ListNode(5);
	ListNode* b = new ListNode(2);
	b->next = new ListNode(4);
	b->next->next = new ListNode(6);


	ListNode* res = mergeTwoLists(a, b);
	while (res) {
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}