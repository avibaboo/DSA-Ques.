class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;
        while(b > 0) {
            if(b % 2) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long l = n / 2;
        long long r = n - l;

        long long lans = power(4, l);
        long long rans = power(5, r);

        return (lans * rans) % MOD;
    }
};