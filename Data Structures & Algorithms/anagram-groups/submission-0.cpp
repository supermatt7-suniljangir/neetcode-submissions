class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> container;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++) {
            string sorted_s = strs[i];
            sort(sorted_s.begin(), sorted_s.end());
            container[sorted_s].push_back(strs[i]);
        }
        for (auto& [key, value] : container) {
            ans.push_back(value);
        }
        return ans;
    }
};
