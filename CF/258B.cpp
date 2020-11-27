#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
int a[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	int i = 0, j = n - 1;
	while (i < n - 1 && a[i] < a[i + 1]) ++i;
	while (j > 1 && a[j] > a[j - 1]) --j;
	bool f = true;
	for (int k = i; k < j; ++k)
		if (a[k] < a[k + 1]) f = false;

	if (i >= j) cout << "yes\n" << "1 1\n" << endl;
	else 
		if (!f || (i > 0 && a[i - 1] > a[j]) || (j < n - 1 && a[j + 1] < a[i])) 
			cout << "no\n";
		else 
			cout << "yes\n" << i + 1 << ' ' << j + 1 << endl;
    return 0;
}