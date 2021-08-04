#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

vector<string> gen(int k) {
	if (k == 1) return {"X"};
	auto child = gen(k - 1);
	vector<string> res;
	for (auto & v : child) {
		auto r = v;
		r.append(string(v.size(), ' '));
		r.append(v);
		res.push_back(r);
	}
	for (auto & v : child) {
		auto r = string(v.size(), ' ');
		r.append(v);
		r.append(string(v.size(), ' '));
		res.push_back(r);
	}
	for (auto & v : child) {
		auto r = v;
		r.append(string(v.size(), ' '));
		r.append(v);
		res.push_back(r);
	}
	return res;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	while (cin >> n and n != -1) {
		auto res = gen(n);
		for (auto & v : res) cout << v << endl;
		cout << '-' << endl;
	}

    return 0;
}