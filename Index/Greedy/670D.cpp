/*
向上取整的方法：ceil(dounle(x + y) / 2.0), ceil()定义在<cmath>
*/
#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL
#define max(lhs, rhs) (lhs > rhs ? lhs : rhs)

const int N = 1e5 + 5;
int a[N];
LL b[N];

LL s = 0, a1 = 0;
int n;
void gen() {
	LL r = a1 + s;
	if (r < 0) cout << r / 2 << endl;
	else cout << (r + 1) / 2 << endl;
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 2; i <= n; ++i) {
		b[i] = 1ll * a[i] - 1ll * a[i - 1];
		s += max(0, b[i]);
	}
	int q, l, r, x;
	cin >> q;
	a1 = a[1];
	gen();
	while (q--) {
		cin >> l >> r >> x;
		if (l > 1) {
			/*
			这里直接将原来的差值减掉，然后再对差值处理，最后再加上
			显然这种简化大大提高了代码的可读性以及可维护性
			*/
			if (b[l] > 0) s -= b[l];
			b[l] += x;
			if (b[l] > 0) s += b[l];
		} else a1 += x;
		if (r < n) {
			x = -x; ++r;
			if (b[r] > 0) s -= b[r];
			b[r] += x;
			if (b[r] > 0) s += b[r];
		}
		gen();
	}
	
    return 0;
}