class Solution {
public:

    string encode(vector<string>& strs) 
    {
        if(strs.empty()) return "";
        string res = "";

        for(int i = 0; i < strs.size(); i++)
        {
            res += to_string(strs[i].length()) + '#' + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) 
    {
       if(s.size() < 1) return {};

       vector<string> result;
       int i = 0;

       while(i < s.size())
       {
            int j = i;

            while(s[j] != '#')
            {
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            i = j + 1;
            j = i + length;

            string storage = s.substr(i, length);
            result.push_back(storage);

            i = j;
       }

       return result;
    }
};












// class Solution {
// public:
//     string encode(vector<string>& strs) {
//         string res;
//         for (const string& s : strs) {
//             res += to_string(s.size()) + "#" + s;
//         }
//         return res;
//     }

//     vector<string> decode(string s) {
//         vector<string> res;
//         int i = 0;
//         while (i < s.size()) {
//             int j = i;
//             while (s[j] != '#') {
//                 j++;
//             }
//             int length = stoi(s.substr(i, j - i));
//             i = j + 1;
//             j = i + length;
//             res.push_back(s.substr(i, length));
//             i = j;
//         }
//         return res;
//     }
// };