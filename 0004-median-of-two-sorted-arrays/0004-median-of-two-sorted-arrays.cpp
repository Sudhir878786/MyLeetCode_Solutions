class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {
            int m = nums1.size();
            for (int i = 0; i < nums2.size(); i++)
            {
                nums1.push_back(nums2[i]);
            }
            sort(nums1.begin(), nums1.end());

            if (nums1.size() % 2 == 0)
            {
                double a = nums1[(nums1.size() / 2) - 1];
                double b = nums1[(nums1.size() / 2)];
                return (a + b) / 2;
            }
            else
            {
                return (double) nums1[(nums1.size() / 2)];
            }
        }
};