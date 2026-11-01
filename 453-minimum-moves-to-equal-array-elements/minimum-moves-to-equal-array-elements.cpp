class Solution {
public:
    int minMoves(vector<int>& a) {
        int n = a.size();
        int sum = accumulate(a.begin(),a.end(),0);

        int mn = *min_element(a.begin(),a.end());

        return (sum - n*mn);
    }
};