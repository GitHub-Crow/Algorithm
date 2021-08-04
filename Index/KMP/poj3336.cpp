#include <iostream>
#include <cstring>
#include <string>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 2e5 + 5;
const int MOD = 1e4 + 7;
int nxt[N];
int n;
string s;

void getNext() {
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
	freopen("data.txt", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> s;
		memset(nxt, 0, sizeof(nxt));
		getNext();
		int ans = n;
		for (int i = 1; i <= n; ++i) {
			int tmp = nxt[i];
			// ex：s=ababab
			// 最长匹配后缀s1为 abab，++ans;
			// s1中能够匹配的后缀 s2 = ab，因为s1在s中有匹配的前缀，所以s2在s中也有匹配的前缀，++ans;
			while (tmp) {
				++ans;
				if (ans >= MOD) ans -= MOD;
				tmp = nxt[tmp];
			}
		}
		cout << ans << endl;
	}
	

    return 0;
}