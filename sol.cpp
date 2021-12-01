#include <bits/stdc++.h>

using namespace std;

struct Letter {
	char letter;
	int position;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = s.size();
		// if there is only 1 letter, then output 1
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		// count the frequency of every letter in the string
		vector<int> counter(26, 0);
		for (int i = 0; i < n; i++) {
			counter[s[i] - 'a']++;
		}
		// count the number of letter(s) with odd frequency
		int cnt = 0;
		for (int i = 0; i < (int) counter.size(); i++) {
			cnt += (counter[i] & 1);
		}
		// if the no. of letters that has an odd frequency is greater than 1,
		// then it is impossible to create a palindromic string
		if (cnt > 1) {
			cout << -1 << '\n';
			continue;
		}
		// otherwise, for every letter in the string, store the information
		// about its (index + 1) using a vector-struct container
		vector<Letter> vec(n);
		for (int i = 0; i < n; i++) {
			vec[i].letter = s[i];
			vec[i].position = i + 1;
		}
		// to create a palindromic string almost all letters have even frequencies
		// in order to create a mirror image if sliced in the center of the string
		// and if there is a letter with an odd frequency, then place the instances
		// of the letter in the center of the string
		// this loop below is for placing the letters in the first half of the string
		// the frequencies of the letters must be divided by 2, since we will place
		// the remaining half in the second half of the string
		// note: don't forget to save the position (index + 1) for every letter used
		string res = "";
		vector<int> ans;
		vector<bool> visited(n, false);
		for (int i = 0; i < (int) counter.size(); i++) {
			if (counter[i] > 0 && counter[i] % 2 == 0) {
				char ch = 'a' + i;
				int instances = counter[i] / 2;
				for (int j = 0; j < n; j++) {
					if (vec[j].letter == ch && instances > 0) {
						res += string(1, vec[j].letter);
						ans.push_back(vec[j].position);
						visited[j] = true;
						instances--;
					}
				}
			}
		}
		// the loop below places all the instances of the letter with the odd
		// frequency at the end of the string (which will be the center later)
		for (int i = 0; i < (int) counter.size(); i++) {
			if (counter[i] & 1) {
				char ch = 'a' + i;
				for (int j = 0; j < n; j++) {
					if (vec[j].letter == ch) {
						res += string(1, vec[j].letter);
						ans.push_back(vec[j].position);
					}
				}
			}
		}
		// the loop below is the same as the for-loop for handling the first half
		// but we need to start at the end of the alphabet in order to create a mirror image
		// note: don't forget to save the position (index + 1) for every letter used
		for (int i = (int) counter.size() - 1; i >= 0; i--) {
			if (counter[i] > 0 && counter[i] % 2 == 0) {
				char ch = 'a' + i;
				int instances = counter[i] / 2;
				for (int j = 0; j < n; j++) {
					if (vec[j].letter == ch && instances > 0 && !visited[j]) {
						res += string(1, vec[j].letter);
						ans.push_back(vec[j].position);
						visited[j] = true;
						instances--;
					}
				}
			}
		}
		// output the positions (index + 1)
		for (int i = 0; i < (int) ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
