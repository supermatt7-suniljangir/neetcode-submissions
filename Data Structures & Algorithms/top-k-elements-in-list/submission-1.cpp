#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
   public:
    /**
     * Problem: Top K Frequent Elements
     *
     * Time Complexity:
     *   - O(N + U log U), where:
     *       N = total size of input array `nums`.
     *       U = number of distinct/unique values (equivalent to set(nums).size()).
     *   - Worst Case: O(N log N) if every number in `nums` is distinct (U = N).
     *   - Best/Average Case: Much faster than O(N log N) when there are heavy duplicates (U << N).
     *
     * Space Complexity:
     *   - O(U) auxiliary space to store distinct keys in the map and pair vector.
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Tally counts for every item in the original list.
        // Takes O(N) time because we scan all N items.
        unordered_map<int, int> container;
        for (int i = 0; i < nums.size(); i++) {
            container[nums[i]]++;
        }

        // 2. Transfer the distinct tallies into a vector.
        // Size of `arr` is U (the number of distinct keys, i.e., set size).
        vector<pair<int, int>> arr;
        for (auto [key, value] : container) {
            arr.emplace_back(value, key);  // {frequency, original_number}
        }

        // 3. Sort ONLY the distinct tallies, not the original array.
        // Sorting U items takes O(U log U) time.
        sort(arr.rbegin(), arr.rend());

        // 4. Collect the top k distinct winners.
        // Takes O(k) time.
        vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.emplace_back(arr[i].second);
        }

        return answer;
    }
};