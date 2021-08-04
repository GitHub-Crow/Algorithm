#include <iostream>
#include <unordered_set>
using namespace std;
typedef long long LL;
#define LOCAL

const int N = 1e3 + 5;
int a[N];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	int ret = 0;
	unordered_set<int> color;
	for (int i = 0; i < n; ++i) {
		color.clear();
		for (int j = i; j < n; ++j) {
			color.insert(a[j]);
			ret += color.size();
		}
	}
	cout << ret << endl;
    return 0;
}