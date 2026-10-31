
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1) return 0;

        int left = 0;
        int right = 0;
        int n = nums.size();

        long long product = 1;
        int count = 0;

        while(right < n) {

            product *= nums[right];

            while(product >= k) {
                product /= nums[left];
                left++;
            }

            count += (right - left + 1);

            right++;
        }

        return count;
    }
};
