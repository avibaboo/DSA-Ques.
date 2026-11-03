class Solution {
public:
    int minMoves(vector<int>& a) {
        int n = a.size();
        int mx = *max_element(a.begin(),a.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (mx - a[i]);
        }
        return ans;
    }
};