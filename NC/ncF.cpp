#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL
const int N = 1e5 + 5;
int k, L, R;
int a[N];
int iL[N], iR[N];

bool check(LL c) {
	LL tot = 0, rel = 0;
	for (int i = 0; i < k; ++i) {
		LL x = 1ll * a[i] / c;
		if (x < iL[i]) return false;
		else if (x > iR[i]) tot += iR[i];
		else {
			tot += x;
			rel += a[i] - x * c;
		}
		
	}
	LL r = tot + rel / c;
	return r >= L;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> k >> L >> R;
	LL sL = 0, sR = 0;
	for (int i = 0; i < k; ++i) cin >> a[i];
	for (int i = 0; i < k; ++i) {
		cin >> iL[i] >> iR[i];
		sL += iL[i];
		sR += iR[i];
	}
	if (sL > R || sR < L) {
		cout << 0 << endl;
		return 0;
	}
	LL cL = 0, cR = 1e14;

	while (cL < cR) {
		LL cM = (cL + cR + 1) / 2;
		if (check(cM)) cL = cM;
		else cR = cM - 1;
	}
	cout << cL << endl;
	
	

    return 0;
}