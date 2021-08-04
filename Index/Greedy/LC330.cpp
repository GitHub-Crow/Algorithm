/*
Q: 给定nums数组和正整数n，要求你在nums中添加数字[1, n]，使得任何[1-n]
的数字都可以由nums中的数字组成，求最少添加次数。
A: 如果[1,x-1]能够覆盖，但x不能覆盖，则添加x可以使得[1,2*x-1]被覆盖。

*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        int idx = 0, m = nums.size(), ans = 0;
        long long k = 1;
        while (k <= n) {
            if (idx < m && nums[idx] <= k) k += nums[idx++];
            else {
                k <<= 1;
                ++ans;
            }
        }
        return ans;
    }
};