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
	cin >> T;
	string s;
	while (T--) {
		cin >> s;
		if (s.size() & 1) cout << "NO\n";
		else {
			if (s[0] == ')' || s.back() == '(') cout << "NO\n";
			else cout << "YES\n";
		}
	}
	

    return 0;
}