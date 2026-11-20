class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int bestEnd=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=bestEnd+nums[i];
            bestEnd=max(v1,v2);
            ans=max(ans,bestEnd);
        }
        return ans;
    }
};