class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;

        // count letters in s1
        for(char c : s1) need[c]++;

        int left = 0;
        for(int right = 0; right < s2.size(); right++) {
            char c = s2[right];
            if(need.count(c)) window[c]++;

            // shrink window if it's bigger than s1
            if(right - left + 1 > s1.size()) {
                char leftChar = s2[left];
                if(need.count(leftChar)) window[leftChar]--;
                left++;
            }

            if(window == need) return true; // exact match
        }

        return false;
    }
};