class Solution {
public:
    int countPartitions(vector<int>& nums, long long maxSum) {
        int partitions = 1;
        long long sum = 0;

        for (int num : nums) {
            if (sum + num <= maxSum) {
                sum += num;
            } else {
                partitions++;
                sum = num;
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int num : nums)
            high += num;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countPartitions(nums, mid) > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};