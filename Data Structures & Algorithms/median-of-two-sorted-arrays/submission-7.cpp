class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double median = 0;
        int lenS = min(nums1.size(), nums2.size());
        int lenL = max(nums1.size(), nums2.size());

        vector<int> smaller;
        vector<int> bigger;

        if(lenS == nums1.size()) { smaller = nums1; bigger = nums2; }
        else { smaller = nums2; bigger = nums1; }

        int half = (lenS + lenL + 1) / 2;

        int l = 0, r = lenS;

        while(1)
        {
            int m = l + (r - l) / 2;
            int j = (lenS + lenL + 1) / 2 - m;

            int aLeft = (m == 0) ? INT_MIN : smaller[m - 1];
            int aRight = (m == lenS) ? INT_MAX : smaller[m];
            int bLeft = (j == 0) ? INT_MIN : bigger[j - 1];
            int bRight = (j == lenL) ? INT_MAX : bigger[j];

            if(aLeft <= bRight && bLeft <= aRight)
            {
                if ((lenS + lenL) % 2 == 0)
                {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
                }

                return max(aLeft, bLeft);
            }
            else if(aLeft > bRight)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        
        return median;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
//     {
//         double median = 0;
//         int lenS = min(nums1.size(), nums2.size());
//         int lenL = max(nums1.size(), nums2.size());

//         vector<int> smaller;
//         vector<int> bigger;

//         if(lenS == nums1.size()) { smaller = nums1; bigger = nums2; }
//         else { smaller = nums2; bigger = nums1; }

//         double half = (lenS + lenL) / 2;

//         int l = 0, r = lenS - 1;

//         while(1)
//         {
//             int m = l + (r - l) / 2;
//             int j = half - m - 2;

//             int aLeft = m <= 0 ? INT_MIN : smaller[m]; 
//             int aRight = m + 1 < lenS ? smaller[m + 1] : INT_MAX;
//             int bLeft = j >= 0 ? bigger[j] : INT_MIN;
//             int bRight = j + 1 < lenL ? bigger[j + 1] : INT_MAX;

//             if(aLeft <= bRight && bLeft <= aRight)
//             {
//                 if ((lenS + lenL) % 2 == 0)
//                 {
//                     return min(aRight, bRight);
//                 }

//                 return max(aLeft, bLeft) + min(aRight, bRight) / 2;
//             }
//             else if(aLeft > bRight)
//             {
//                 r = m - 1;
//             }
//             else
//             {
//                 l = m + 1;
//             }
//         }
        
//         return median;
//     }
// };
