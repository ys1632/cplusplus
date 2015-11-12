#include <iostream>
#include <vector>

using namespace std;

string findLongestPalindrome(string s) {
	int len = s.length();
	if (len < 2) return s;
	int start = 0;
	int maxLen = 1;

	vector< vector<bool> > check(len, vector<bool>(len, false));

	for (int j = 0; j < len; j++) {
		for (int i = 0; i <= j; i++) {
			if (s[i] == s[j]) {
				if (j - i < 2) {
					check[i][j] = true;
				}
				else {
					check[i][j] = check[i+1][j-1];
				}
			}
			if (check[i][j] && j - i + 1> maxLen) {
				start = 0;
				maxLen = j - i + 1;
			}
		}
	}

	return s.substr(start, maxLen);
}

int main() {
	cout << findLongestPalindrome("abccbadddabccbaer") << endl;
	return 0;
}