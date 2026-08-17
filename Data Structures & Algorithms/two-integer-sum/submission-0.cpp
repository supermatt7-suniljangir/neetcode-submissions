class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int second;
            for (int j = i + 1; j < nums.size(); j++) {
                if (current + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
