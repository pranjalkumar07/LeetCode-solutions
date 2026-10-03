class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto &it : freq){
            int num=it.first;
            int count=it.second;
            bucket[count].push_back(num);
        }

        for(int i=nums.size();i>=0;i--){
            for(int num: bucket[i]){
                ans.push_back(num);

                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
        
    }
};