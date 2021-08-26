#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
#define LOCAL


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n, m;
	cin >> T;
	while (T--) {
		string tmp;
		cin >> tmp;
		int idx = 0;
		string w;
		while (isdigit(tmp[idx])) w.push_back(tmp[idx++]);
		n = atoi(w.c_str());
		w.clear();
		while (not isdigit(tmp[idx])) ++idx;
		while (idx < tmp.size()) w.push_back(tmp[idx++]);
		m = atoi(w.c_str());
		cout << n << ' ' << m << endl;
		int s = 0;
		for (int k = n; k > 0; k -= 2) s += k;
		if (s >= m) cout << "true\n";
		else cout << "false\n";
	}
	

    return 0;
}	