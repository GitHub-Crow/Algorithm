#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL

string gen(int m, int as) {
	string a;
	for (int i = 0; i < m; ++i) {
		if (as >= 9) {
			a.push_back('9');
			as -= 9;
		}
		else {
			a.push_back('0' + as);
			as = 0;
		}
	}
	return a;
}


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int m, s;
	cin >> m >> s;
	if ((s == 0 && m > 1) || s > 9 * m) {
		cout << "-1 -1\n";
		return 0;
	}
	string a, b;
	string as = gen(m, s), bs;
	if (s && s <= 9 * (m - 1)) {
		bs.push_back('1');
		string t = gen(m - 1, s - 1);
		reverse(t.begin(), t.end());
		bs = bs + t;
	}
	else {
		bs.push_back('0' + s - 9 * (m - 1));
		string t(m - 1, '9');
		bs = bs + t;
	}
	cout << bs << ' ' << as << endl;
    return 0;
}