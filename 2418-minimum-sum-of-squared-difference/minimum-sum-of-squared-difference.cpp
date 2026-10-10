class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        int n = a.size();
        vector<int> diff(n);
        int mx = 0;

        for(int i = 0; i < n; i++){
            diff[i] = abs(a[i] - b[i]);
            mx = max(mx, diff[i]);
        }

        vector<int> cnt(mx + 1, 0);

        for(int x : diff){
            cnt[x]++;
        }

        long long k = 1LL * k1 + k2;

        for(int i = mx; i > 0 && k > 0; i--){
            long long move = min((long long)cnt[i], k);

            cnt[i] -= move;
            cnt[i - 1] += move;
            k -= move;
        }

        long long ans = 0;

        for(int i = 1; i <= mx; i++){
            ans += 1LL * i * i * cnt[i];
        }

        return ans;
    }
};