/*
Q: 给定一个数n，返回下x,y满足x,y,n能够构成直角三角形。
*/
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
	LL n;
	cin >> n;
	if (n & 1) cout << (n * n + 1) / 2 << ' ' << (n * n - 1) / 2 << endl;
	else cout << n * n / 4 + 1 << ' ' << n * n / 4 - 1 << endl;
	

    return 0;
}