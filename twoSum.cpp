#include <iostream>
#include <set>

using namespace std;

int twoSum(int nums[], int len, int target) {
	int cnt = 0;
	set<int> st;
	for (int i = 0; i < len; i++) {
		st.insert(nums[i]);
	}

	for (int i = 0; i < len; i++) {
		if (st.count(nums[i])) {
			st.erase(nums[i]);
			if (st.count(target - nums[i])) {
				cnt++;
				st.erase(target - nums[i]);
			}
		}
	}
	return cnt;

}

int main() {
	int nums[] = {2,3,1,7,5,8,9,0,4,6};
	int len = 10;
	cout << twoSum(nums, len, 8);
	return 0;
}