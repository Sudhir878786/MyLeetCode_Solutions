class Solution {
	const static int n = 1e6;
    bool prime[1000001];
	void SieveOfEratosthenes()
	{
		memset(prime, true, sizeof(prime));
        prime[1] = prime[0] = false;
		for (int p = 2; p * p <= n; p++) {
			if (prime[p] == true) {
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}
	}
public:
	vector<int> closestPrimes(int left, int right) {
        vector<int> res(2, -1), ans;
        SieveOfEratosthenes();
        int k = 0;
        
        for (int i = left; i <= right; ++i) {
            if (prime[i]) ans.push_back(i);
        }
        
        if (ans.size() == 1) return {-1, -1};
        int n = ans.size(), mn = INT_MAX;
        for (int i = 1; i < n; ++i) {
            int mm = ans[i] - ans[i - 1];
            if (mn > mm) {
                res[0] = ans[i - 1];
                res[1] = ans[i];
                mn = mm;
            }
        }
        return res;
	}
};