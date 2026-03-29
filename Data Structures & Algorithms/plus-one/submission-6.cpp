class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size() - 1] != 9)
        {
            digits[digits.size() - 1]++;
            return digits;
        }
        else
        {
            for(int i = digits.size() - 1; i >= 0; i--)
            {
                if(digits[i] != 9 && i != 0)
                {
                    digits[i]++;
                    break;
                }
                else if(digits[i] != 9 && i == 0)
                {
                    digits[i]++;
                    break;
                }
                else if(digits[i] == 9 && i == 0 )
                {
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                    break;
                }
                else 
                {
                    digits[i] = 0;
                    continue;
                }
            }
        }

        return digits;
    }
};
