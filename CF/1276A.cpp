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
	int T;
	string s;
	cin >> T;
	while (T--) {
		cin >> s;
		int n = s.size();
		vector<int> one, two;
		for (int i = 3; i <= n; ++i) {
			auto sub = s.substr(i - 3, 3);
			if (sub == "one") one.push_back(i - 3);
			if (sub == "two") two.push_back(i - 3);
		}
		int p1 = 0, p2 = 0, n1 = one.size(), n2 = two.size();
		vector<int> r;
		// printf("size : %d, %d\n", n1, n2);
		while (p1 < n1 or p2 < n2) {
			if (p1 < n1 and p2 < n2) {
				if (two[p2] < one[p1]) {
					if (two[p2] + 2 == one[p1]) {
						r.push_back(one[p1]);
						++p1; ++p2;
					} else r.push_back(two[p2++] + 1);
				}
				else r.push_back(one[p1++] + 1);
			}
			else if (p1 < n1) r.push_back(one[p1++] + 1);
			else if (p2 < n2) r.push_back(two[p2++] + 1);
		}
		cout << r.size() << endl;
		for (auto & v : r) cout << v << ' ';
		cout << endl;
	}
	

    return 0;
}