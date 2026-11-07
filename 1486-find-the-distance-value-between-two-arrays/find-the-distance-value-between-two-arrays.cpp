class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;

        for(int i = 0; i < arr1.size(); i++) {
            int x = arr1[i];

            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);

            if(it == arr2.end() || *it > x + d) {
                ans++;
            }
        }

        return ans;
    }
};