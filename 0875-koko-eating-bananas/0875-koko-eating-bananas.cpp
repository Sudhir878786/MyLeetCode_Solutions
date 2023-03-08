//  let say 3,6,7,11 bananas 
// so 1,2,3,4,5,6,7,8,9,10,11    using binary search we finc mid (6) and store the time taken to eat banana[3/6+6/6+7/6+11/6 ] total 6 hrs
// which could be one possible ans but we have to minimise it so we will check the 6<=h if yes mid-1  which is 3 else if(6>h)mid+1
class Solution
{
    public:
        int minEatingSpeed(vector<int> &piles, int H)
        {
            int low = 1, high = 1000000000, k = 0;
            while (low <= high)
            {
                k = (low + high) / 2;
                long long h = 0;
                for (int i = 0; i < piles.size(); i++)
                    h +=(long long) ceil(1.0 *piles[i] / k);
                if (h > H)
                    low = k + 1;
                else
                    high = k - 1;
            }
            return low;
        }
};