class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for(int i = 0; i < s.size(); i++)
        {
            mapS[s[i]]++;
            mapT[t[i]]++;
        }

        if(mapS == mapT) return true;
        else return false;
    }
};
