#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 2e5 + 5;
int b[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	LL n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> b[i];
	sort(b, b + n);
	LL iL = 1, iR = 1;
	for (int i = 1; i < n; ++i) {
		if (b[i] != b[i - 1]) break;
		++iL;
	}
	for (int i = n - 2; i >= 0; --i) {
		if (b[i] != b[i + 1]) break;
		++iR;
	}

	if (b[0] == b[n - 1]) {
		cout << b[n - 1] - b[0] << ' ' << (n - 1) * n / 2 << endl;
	}
	else {
		cout << b[n - 1] - b[0] << ' ' << iL * iR << endl;	
	}
	

    return 0;
}