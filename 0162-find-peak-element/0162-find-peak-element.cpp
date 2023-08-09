class Solution {
public:
   int findPeakElement(vector<int>& v) {
        int n = v.size();
        int ans = -1;
        int s = 0, e = n - 1; 
        if(n==1)
            return 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (mid > 0 && mid < n - 1) { // Leaving corner elements
                if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
                    return mid;
                else if (v[mid + 1] > v[mid])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
            else if(mid==0){  // checking left corner
                if (v[0] > v[1])
                    return 0;
                else
                    return 1;
            }
            else if(mid==n-1){  // checking right corner
                if (v[n - 1] > v[n - 2])
                    return n - 1;
                else
                    return n - 2;
            }
        }
        return ans;
    }
};