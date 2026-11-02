class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        int mid = a[n/2];

        int cost = 0;
        for(int i=0;i<n;i++){
            cost += abs(a[i] - mid);
        }
        return cost;
    }
};