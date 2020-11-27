#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	LL m, n;
	cin >> m >> n;
	LL x = m / n, y = m % n;
	LL mink, maxk; 
	mink = y * (x + 1) * x / 2 + (n - y) * (x - 1) * x / 2;
	maxk = (m - n + 1) * (m - n) / 2;
	cout << mink << ' ' << maxk << endl;

    return 0;
}