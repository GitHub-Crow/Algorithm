#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	string s;
	cin >> s;
	vector<int> c;
	char u = s[0];
	int w = 0;
	for (auto & v : s) {
		if (v == u) ++w;
		else {
			c.push_back(w);
			w = 1;
			u = v;
		}
	}
	c.push_back(w);
	string ans;
	bool isLastCouple = false;
	for (int pos = 0, k = 0; k < c.size(); ++k) {
		if (c[k] > 1) {
			ans.append(string((isLastCouple ? 1 : 2), s[pos]));
			isLastCouple = !isLastCouple;
		}
		else {
			isLastCouple = false;
			ans.push_back(s[pos]);
		}
		pos += c[k];
	}
	cout << ans << endl;

    return 0;
}