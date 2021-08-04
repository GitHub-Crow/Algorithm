#include <iostream>
#include <set>

using namespace std;
typedef long long LL;
#define LOCAL

int gcd(int m, int n) {
	if (n) return gcd(n, m % n);
	else return m;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n;
	int ele;
	cin >> T;
	while (T--) {
		cin >> n;
		multiset<int, greater<int>> cache;
		for (int i = 0; i < n; ++i) {
			cin >> ele;
			cache.insert(ele);
		}

		int g = *cache.begin();
		while (n--) {
			int mg = 0;
			auto ele = cache.begin();
			for (auto it = cache.begin(); it != cache.end(); ++it) {
				int cg = gcd(max(*it, g), min(*it, g));
				// printf("(%d, %d) = %d\n", *it, g, cg);
				if (*it < mg) break;
				if (cg  > mg) {
					mg = cg;
					ele = it;
				}
			}
			cout << *ele;
			cache.erase(ele);
			g = mg;
			if (n) cout << ' ';
			else cout << endl;
		}
	}
	

    return 0;
}