#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

bool accept(int n, int k, LL v) {
	LL tot = 0;
	LL tk = 1;
	while (tot < n) {
		LL d = v / tk;
		tk *= k;
		if (d) tot += d;
		else return false;
	}
	return true;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, k;
	cin >> n >> k;
	LL lv = 0, rv = n * k;
	while (lv < rv) {
		LL mv = (lv + rv) / 2;
		if (accept(n, k, mv)) rv = mv;
		else lv = mv + 1;
	}
	cout << lv << endl;
 

    return 0;
}