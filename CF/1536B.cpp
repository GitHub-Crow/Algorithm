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
	int T, n;
	cin >> T;
	string s, t;
	vector<char> e = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	while (T--) {
		cin >> n;
		cin >> s;
		bool f = false;
		for (auto & k : e) {
			t.clear();
			t.push_back(k);
			if (t.empty()) continue ;
			if (s.find(t) == string::npos) {
				f = true;
				break;
			}
		}
		for (auto & j : e) {
			if (f) break ;
			for (auto & k : e) {
				t.clear();
				t.push_back(j);
				t.push_back(k);
				if (t.empty()) continue ;
				if (s.find(t) == string::npos) {
					f = true;
					break;
				}
			}
		}
		for (auto & i : e) {
			if (f) break ;
			for (auto & j : e) {
				if (f) break ;
				for (auto & k : e) {
					t.clear();
					t.push_back(i);
					t.push_back(j);
					t.push_back(k);
					if (t.empty()) continue ;
					if (s.find(t) == string::npos) {
						f = true;
						break;
					}
				}
			} 
		}
		cout << t << endl;
	}
	

    return 0;
}