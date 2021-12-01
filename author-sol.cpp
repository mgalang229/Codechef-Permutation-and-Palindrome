#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = s.size();
		int pal[n];
		int count[26] = {0};
		vector<vector<int>> position(26);
		// count the frequency of every letter
		// save the indices of the occurrences of every letter
		for (int i = 0; i < n; i++) {
			count[s[i] - 'a']++;
			position[s[i] - 'a'].push_back(i);
		}
		// count the no. of letters with odd frequency
		// save the index of letter of with odd frequency
		int odd_count = 0;
		int odd_character = -1;
		for (int i = 0; i < 26; i++) {
			if (count[i] % 2 == 1) {
				odd_count++;
				odd_character = i;
			}
		}
		// if the no. of letters with odd frequency is greater than
		// or equal to 2, then it is impossible to create a palindrome
		if (odd_count >= 2) {
			cout << -1 << '\n';
			continue;
		}
		// otherwise, form a palindrome by dividing the occurrences of
		// every letter and putting it in both ends of the string (i, n - i + 1)
		int start_index = 0;
		for (int i = 0; i < 26; i++) {
			int current_count = count[i];
			if (current_count % 2 == 0) {
				int current_length = position[i].size();
				for (int j = 0; j < current_length; j += 2) {
					pal[start_index] = position[i][j];
					pal[n - start_index - 1] = position[i][j + 1];
					start_index++;
				}
			}
		}
		// store the occurrences of the letter with odd frequency in the center
		if (odd_count == 1) {
			for (int i = 0; i < (int) position[odd_character].size(); i++) {
				pal[start_index++] = position[odd_character][i];
			}
		}
		// output the indices
		for (int i = 0; i < n; i++) {
			cout << (pal[i] + 1) << " ";
		}
		cout << '\n';
	}
	return 0;
}
