#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, x, k = 1;
	cin >> n;
	vector<int> odds, evens;
	while (n--) {
		cin >> x;
		if (x & 1) odds.push_back(k);
		else evens.push_back(k);
		++k;
	}
	if (odds.size() < evens.size()) cout << odds[0] << endl;
	else cout << evens[0] << endl;

    return 0;
}