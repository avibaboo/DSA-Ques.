class Solution {
public:
    int minimizeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin() , a.end());

        int l = abs(a[n-1] - a[2]);
        int r = abs(a[n-3] - a[0]);
        int z = abs(a[n-2] - a[1]);

        return min({l , r , z});

    }
};