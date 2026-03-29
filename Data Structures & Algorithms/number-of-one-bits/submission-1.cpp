class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        // int count = 0;

        // while(n != 0)
        // {
        //     int temp = n % 2;
        //     if(temp == 1) count++;

        //     n = n >> 1;
        // }

        // return count;

        int count = 0;
        while(n)
        {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};
