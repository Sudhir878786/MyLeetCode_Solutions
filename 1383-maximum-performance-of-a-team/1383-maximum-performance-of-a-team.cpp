class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        int MOD = 1e9 + 7;
        vector<pair<int, int>> candidates(n);
        // we build the pair { efficiency, speed } so that we can sort it later
        for (int i = 0; i < n; i++) 
            candidates[i] = { efficiency[i], speed[i] };
        // sort candidates in descending order
        sort(candidates.rbegin(), candidates.rend());
        long speedSum = 0, ans = 0;
        // we use priority queue here with greater<int> to store the sum
        // i.e min heap (the smallest element goes on the top)
        priority_queue <int, vector<int>, greater<int>> pq;
        // iterate each pair
        for (auto& [e, s] : candidates) {
            // put the speed to priority queue
            pq.push(s);
            speedSum += s;
            // we only need to choose at most k engineers
            // hence if the queue size is greater than k
            // we need to remove a candidate
            if (pq.size() > k) 
            {
                speedSum -= pq.top();
                pq.pop();
            }
            // calculate the performance
            ans = max(ans, speedSum * e);
        }
        return ans % MOD;
    }
};