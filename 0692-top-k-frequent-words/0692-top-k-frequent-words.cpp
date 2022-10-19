class Solution
{
    public:
        static bool comp(pair<string, int> &a,
            pair<string, int> &b)
        {    
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second > b.second;
        }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (auto it: words)
        {
            mp[it]++;
        }
        vector<pair<string, int>> ans;
        vector<string> res;
        for (auto it: mp)
        {
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end(), comp);
        // for (auto i: ans)
        // {
        //     cout << i.first << " " << i.second << endl;
        // }
        for (int i = 0; i < k; i++)
        {
            res.push_back(ans[i].first);
        }

        return res;
    }
};