#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int f[30][30];
bool r = true;
void gen(string& a, string& b) {
	auto n = min(a.size(), b.size());
	for (int k = 0; k < n; ++k) {
		if (a[k] != b[k]) {
			f[a[k] - 'a'][b[k] - 'a'] = 1;
			return ;
		}
	}
	if (a.size() > b.size()) r = false;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	vector<string> names;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		names.push_back(s);
	}
	memset(f, 0, sizeof(f));
	r = true;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) gen(names[i], names[j]);

	vector<int> deg(26);
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			if (f[i][j]) deg[j]++;

	queue<int> que;
	for (int i = 0; i < 26; ++i) if (deg[i] == 0) que.push(i);
	string ans;
	while (!que.empty()) {
		auto i = que.front(); que.pop();
		ans.push_back(i + 'a');
		for (int j = 0; j < 26; ++j) {
			if (f[i][j]) {
				--deg[j];
				if (deg[j] == 0) que.push(j);
			}
		}
	}
	if (ans.size() < 26 || !r) cout << "Impossible\n";
	else cout << ans << endl;
    return 0;
}