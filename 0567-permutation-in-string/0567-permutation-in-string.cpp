class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp,orig;
        for(int i = 0;i< s1.size();i++)
            mp[s1[i]]++;
        orig = mp;
        int l =0 , r =s1.size()-1;
        while(r< s2.size())
        {
            int count =0 ;
            for(int i = l; i <= r ;i++)
                if(mp[s2[i]]--)
                    count++;
            if(count == s1.size())
                return true;
            l++;
            r++;
            mp=orig;
        }
        return false;
    }
};