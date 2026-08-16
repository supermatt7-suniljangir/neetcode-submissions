class Solution {
   public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> freq;

        for (int c : s) {
            freq[c]++;
        }
        for (int c : t) {
            if (--freq[c] < 0) return false;
        }

        return true;
    }
};
