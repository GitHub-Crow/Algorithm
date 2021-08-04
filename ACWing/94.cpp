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
	int n;
	cin >> n;
	for (int s = 1; s < (1 << n); ++s) {
		for (int k = 0; k < n; ++k) {
			if (s >> k & 1) cout << k + 1 << ' ';
		}
		cout << endl;
	}

	

    return 0;
}