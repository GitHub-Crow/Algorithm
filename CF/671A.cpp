#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
typedef long long LL;

#define LOCAL

typedef long long LL;
class Solution {
public:
    /**
     * @param musics: the musics
     * @return: calc the number of pair of music
     */
    long long musicPairs(vector<int> &musics) {
        vector<LL> cnt(61);
        for (auto & v : musics) ++cnt[v];
        LL ans = cnt[60] * (cnt[60] - 1) / 2 + cnt[30] * (cnt[30] - 1) / 2;
        for (int i = 1, j = 59; i < j; ++i, --j) ans += cnt[i] * cnt[j];
        return ans;
    }
};

int main(int argc, char * argv[]) 
{
	Solution sol;
	vector<int> a = {1, 2, 59, 60};
	cout << sol.musicPairs(a);

    return 0;
}