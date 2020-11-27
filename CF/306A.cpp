#include <iostream>
#include <string>
#include <vector>

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
	vector<int> a, b;
	int n = s.size();
	for (int i = 1; i < n; ++i) {
		if (s[i] == 'A' && s[i - 1] == 'B') b.push_back(i);
		if (s[i] == 'B' && s[i - 1] == 'A') a.push_back(i);
	}
	int i = 0, j = 0;
	bool f = false;
	if (a.empty() || b.empty()) f = false ;
	else if (a.size() + b.size() > 3) f = true;
	else {
		if (abs(a[0] - b[0]) > 1) f = true;
		else {
			if (a.size() > 1) {
				f = (abs(a[1] - b[0]) > 1);
			}
			if (b.size() > 1) {
				f = (abs(b[1] - a[0]) > 1);
			}
		}
	}  
	if (f) cout << "YES\n";
	else cout << "NO\n";

    return 0;
}