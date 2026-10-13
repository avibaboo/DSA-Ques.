class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i] < 0){
                a[i] = abs(a[i]);
            }
        }

        sort(a.rbegin(),a.rend());
        int mid = (n+1)/2;
        
        long long ans = 0;
        for(int i=0;i<mid;i++){
            ans += (a[i] * a[i]);
        }
        for(int i=mid;i<n;i++){
            ans -= (a[i] * a[i]);
        }
        return ans;
    }
};