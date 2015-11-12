#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

void quickSelect(vector<pair<int, int> > & vec, int left, int right, int k) {
	int pivot = vec[right].second;
	int p = left - 1;
	int q = left;
	while (q < right) {
		if (vec[q].second > pivot) {
			p++;
			swap(vec[p], vec[q]);
		}
		q++;
	}

	swap(vec[p+1], vec[right]);

	if (p+1 == k-1) return;
	else if (p+1 > k-1) quickSelect(vec, left, p, k);
	else quickSelect(vec, p+2, right, k);

}

vector<int> kFreqElement(int arr[], int len, int k) {
	vector<pair<int, int> > vec;
	vector<int> res;
	map<int, int> mp;
	for (int i = 0; i < len; i++) {
		if (mp.find(arr[i]) != mp.end()) {
			mp[arr[i]]++;
		}
		else {
			mp[arr[i]] = 1;
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair <int, int> > > q;

	map<int, int> :: iterator it = mp.begin();
	int index = 0;
	for (; it != mp.end(); it++) {
		//vec.push_back(make_pair(it->first, it->second));
		//using priority queue

		q.push(make_pair(it->second, it->first));
		if (index > k) {
			q.pop();
		}
		index++;
	}
	q.pop();

	//nlog(n)
	//sort(vec.begin(), vec.end(), compare);


	//can be O(n)
	//quickSelect(vec, 0, vec.size() - 1, k);

	//using priority queue

	for (int i = 0; i < k; i++) {
		//res.push_back(vec[i].first);
		res.push_back(q.top().second);
		q.pop();
	}

	return res;
}

int main() {
	int arr[] = {1,1,1,1,2,2,4,4,4,3};
	vector<int> ans = kFreqElement(arr, 10, 2);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}