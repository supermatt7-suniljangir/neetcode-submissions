class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute-Force method O(N^2) time complexity thanks to innner loop
        // for (int i = 0; i < nums.size(); i++) {
        //     int current = nums[i];
        //     int second;
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (current + nums[j] == target) {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};

        // Optimal Method: using hashmap(unordered_map) to check the compliment of current
        // iteration, requires O(N) time complexity, no nested loops required

        unordered_map<int, int> mp;  // key: element, value: index

        for (int i = 0; i < nums.size(); i++) {
            // get the complement first
            int complement = target - nums[i];
            // check if complement exists ie if target = 9 and nums[i] = 2 then if 7 is present
            if (mp.count(complement)) {
                return {mp[complement], i};
            }
            // we store the current element in the map so we can keep a reference for future
            mp[nums[i]] = i;
        }
        return {};
    }
};
