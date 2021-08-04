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
	if (n & 1) cout << 2 * (n/2 + 1) * (n/2 + 2) << endl;
	else cout << (n/2 + 1) * (n/2 + 1) << endl;
	

    return 0;
}