#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define LOCAL

int lhb, rhb;
string lhs, rhs;
int ctoi(char c) {
	if (isdigit(c)) return c - '0';
	else {
		if (c >= 'a' and c <= 'z') return c - 'a' + 36;
		else return c - 'A' + 10;
	}
}

char itoc(int i) {
	if (i <= 9) return i + '0';
	else if (i >= 10 and i <= 35) return 'A' + i - 10;
	else return 'a' + i - 36;
}

void solve() {
	int n = lhs.size();
	vector<int> b(n);
	rhs.clear();
	for (int k = 0; k < n; ++k) b[k] = ctoi(lhs[k]);
	while (n > 0) {
		int o = 0;
		for (int i = 0; i < n; ++i) {
			int r = (o * lhb + b[i]) / rhb;
			o = (o * lhb + b[i]) % rhb;
			b[i] = r;
		}
		while (n > 0 and !b[n - 1]) --n;
		rhs.push_back(itoc(o));
	}
	reverse(rhs.begin(), rhs.end());
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lhb >> rhb >> lhs;
		solve();
		cout << lhb << ' ' << lhs << endl << rhb << ' ' << rhs << endl << endl;
	}
	

    return 0;
}