class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // get a fucking map first
        unordered_map<int, int> container;

        for (int i = 0; i < nums.size(); i++) {
            container[nums[i]]++;
        }

        // turn the map into a vector of pairs({frequency, item}) to make sorting easier
        vector<pair<int, int>> arr;
        for (auto [key, value] : container) {
            arr.emplace_back(value, key);
        }
        // sort the vector in reverse(descending order)
        sort(arr.rbegin(), arr.rend());
        vector<int> answer;
        // finally return the k items
        for (int i = 0; i < k; i++) {
            answer.emplace_back(arr[i].second);
        }
        return answer;
    }
};
