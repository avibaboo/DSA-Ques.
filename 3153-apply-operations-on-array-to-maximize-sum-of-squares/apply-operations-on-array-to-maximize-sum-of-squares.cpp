class Solution {
public:
const int MOD = 1e9 + 7;
    int maxSum(vector<int>& a, int k) {
        int n = a.size();

        vector<int>cnt(32 , 0);
        for(int num : a){
            for(int b=0;b<32;b++){
            if(num & (1<<b)){
                cnt[b]++;
            }
            }
        }

        int res = 0;

        while(k--){
            long long curr = 0;
            for(int b=0;b<32;b++){
                if(cnt[b] > 0){
                    cnt[b]--;
                    curr = (curr | (1<<b));
                }
            }
            res = (res + (curr * curr)) % MOD;
        }
        return res;
    }
};