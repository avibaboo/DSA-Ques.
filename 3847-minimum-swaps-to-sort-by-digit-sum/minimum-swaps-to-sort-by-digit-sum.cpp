class Solution {
    // Helper function to calculate the sum of digits of a number
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSorted = nums;

        // Custom comparator to sort by digit sum, then by value
        // Note the [&] capture list to allow access to getDigitSum inside the lambda
        auto lambda = [&](int num1, int num2) {
            int digitSum1 = getDigitSum(num1);
            int digitSum2 = getDigitSum(num2);
            
            if (digitSum1 != digitSum2) {
                return digitSum1 < digitSum2;
            }
            return num1 < num2;
        };

        sort(afterSorted.begin(), afterSorted.end(), lambda);

        // Map to store the current indices of each value
        unordered_map<int, int> valToIndex;
        for (int i = 0; i < n; i++) {
            valToIndex[nums[i]] = i;
        }

        int swapsCount = 0;
        for (int i = 0; i < n; i++) {
            int expectedVal = afterSorted[i];
            int currVal = nums[i];

            // If the element is already in the correct position, skip
            if (expectedVal == currVal) {
                continue;
            }

            // Find where the expected value is currently located
            int idx = valToIndex[expectedVal];

            // Swap values in the array
            nums[i] = expectedVal;
            nums[idx] = currVal;

            // Update the map with new indices after the swap
            valToIndex[expectedVal] = i;
            valToIndex[currVal] = idx;

            swapsCount++;
        }

        return swapsCount;
    }
};