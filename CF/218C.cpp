#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL

int nb, ns, nc, pb, ps, pc;
int mb, ms, mc;
LL r;

bool gen(LL& k) {
	LL c = max(0ll, k * mb - nb) * pb + max(0ll, k * ms - ns) * ps + max(0ll, k * mc - nc) * pc;
	return c <= r;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	string s;
	cin >> s;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	mb = 0; ms = 0; mc = 0;
	for (auto & v : s) {
		if (v == 'B') ++mb;
		else if (v == 'S') ++ms;
		else if (v == 'C') ++mc;
	}
	LL iL = 0, iR = 1e13;
	while (iL < iR) {
		LL iM = (iL + iR + 1) / 2;
		if (gen(iM)) iL = iM;
		else iR = iM - 1;
	}
	cout << iL << endl;

    return 0;
}