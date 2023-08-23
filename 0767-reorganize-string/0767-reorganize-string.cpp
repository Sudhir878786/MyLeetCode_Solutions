class Solution {
public:
    string reorganizeString(string S) {
          std::vector<int> hash(26, 0);
    for (char c : S) {
        hash[c - 'a']++;
    }
    
    int maxFreq = 0, maxIdx = 0;
    for (int i = 0; i < hash.size(); i++) {
        if (hash[i] > maxFreq) {
            maxFreq = hash[i];
            maxIdx = i;
        }
    }
    
    if (maxFreq > (S.length() + 1) / 2) {
        return "";
    }
    
    std::string res(S.length(), ' ');
    int idx = 0;
    while (hash[maxIdx] > 0) {
        res[idx] = maxIdx + 'a';
        idx += 2;
        hash[maxIdx]--;
    }
    
    for (int i = 0; i < hash.size(); i++) {
        while (hash[i] > 0) {
            if (idx >= res.length()) {
                idx = 1;
            }
            res[idx] = i + 'a';
            idx += 2;
            hash[i]--;
        }
    }
    
    return res;
        
    }
};