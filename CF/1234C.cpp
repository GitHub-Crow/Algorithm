#include<iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

#define LOCAL

bool cmp(const string& lhs, const string& rhs) {
	if (lhs.size() < rhs.size()) return true;
	else if (lhs.size() > rhs.size()) return false;
	else {
		int k = 0, n = lhs.size();
		while (k < n - 1 && lhs[k] == rhs[k]) ++k;
		return lhs[k] < rhs[k];
	}
}

string gen(string & s) {
	int k = 0, n = s.size();
	while (k < n - 1 && s[k] == '0') ++k;
	return s.substr(k, n - k);
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	string s;
	cin >> s;
	string c;
	vector<string> re;
	for (auto & v : s) {
		if (isdigit(v)) c.push_back(v);
		else {
			if (!c.empty()) re.push_back(gen(c));
			c.clear();
		}
	}
	sort(re.begin(), re.end(), cmp);
	for (auto & v : re) cout << v << endl;

    return 0;
}