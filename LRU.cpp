#include <iostream>
#include <map>
#include <vector>
using namespace std;

int miss(int input[], int size, int len) {
	vector<int> lru;
	int cnt = 0;
	map<int, int> mp;
	for (int i = 0; i < len; i++) {
		if (mp.count(input[i])) {
			lru.erase(lru.begin() + mp[input[i]]);
			lru.push_back(input[i]);
			for (int j = 0 ; j < lru.size(); j++) {
				mp[lru[j]] = j;
			}
		}
		else {
			cnt++;
			if (lru.size() == size) {
				mp.erase(lru[0]);
				lru.erase(lru.begin());
				
			}
			lru.push_back(input[i]);
			for (int j = 0 ; j < lru.size(); j++) {
					mp[lru[j]] = j;
				}

		}
	}

	for (int i = 0; i < lru.size(); i++) {
		cout << lru[i] << " ";
	}
	cout << endl;
	return cnt;
}

int miss2(int input[], int size, int len) {
	vector<int> lru;
	int cnt = 0;
	int index;
	for (int i = 0; i < len; i++) {
		bool found = false;
		for (int j = 0; j < lru.size(); j++) {
			if (input[i] == lru[j]) {
				found = true;
				index = j;
				break;
			}
		}
		if (found) {
			lru.erase(lru.begin() + index);
			lru.push_back(input[i]);
		}
		else {
			cnt++;
			if (lru.size() == size) {
				lru.erase(lru.begin());
			}
			lru.push_back(input[i]);
		}
		found = false;
	}
	for (int i = 0; i < lru.size(); i++) {
		cout << lru[i] << " ";
	}
	cout << endl;
	return cnt;
}

int main() {
	//int arr[] = {1,2,3,4,4,3,2,1};
	int arr[] = {5,6,1,2,4,2,6,5,1,2};
	cout << miss2(arr, 4, 10) << endl;
	return 0;
}