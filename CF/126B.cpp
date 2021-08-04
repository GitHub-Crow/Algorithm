#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e6 + 5;
string s;
int nxt[N];
int n;
void genNext() {
	int i = 0, j = -1;
	nxt[0] = -1;
	while (i < n) {
		if (j == -1 || s[i] == s[j]) 
			nxt[++i] = ++j;
		else
			j = nxt[j];
	}
}


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> s;
	n = s.size();
	genNext();
	int ans = 0, pos = 0;
	unordered_set<int> re;
	for (int k = 0; k < n; ++k) {
		if (nxt[k] > 0) re.insert(nxt[k]);
	}
	int o = nxt[n];
	while (o > 0) {
		if (re.count(o)) break ;
		o = nxt[o];
	} 
	if (o > 0) cout << s.substr(0, o) << endl;
	else cout << "Just a legend\n";

    return 0;
}