class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
    
        if(nums == target) {
            int count = 1;
            for(int k = n - 2; k >= 0; k--) {
                if(target[k] >= target[k + 1]) {
                    count++;
                } else {
                    break;
                }
            }
            return count;
        }

        auto velqorimna = nums;

        int i = 0, j = 0;

        while(i < n && j < n) {
            if(nums[i] == target[j]) {
                i++, j++;
            } else {
                break;
            }
        }

        int idx = i;
        int ans = 0;

        sort(nums.begin() + idx, nums.end(), greater<int>());

        if(nums == target) {
            ans++;
        }

        if(ans > 0 && idx > 0) {
            for(int k = idx - 1; k >= 0; k--) {
                if(target[k] >= target[k + 1]) {
                    ans++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};