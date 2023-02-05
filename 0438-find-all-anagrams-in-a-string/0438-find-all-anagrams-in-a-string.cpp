class Solution {
public:
    vector<int> findAnagrams(string str, string ptn) {
        

    int n= str.size();
        int m = ptn.size();
	vector<int> ans;
    map<char,int> strFreq;
    map<char,int> ptnFreq;
    for(int i = 0 ;i < m;i++)
    {
        ptnFreq[ptn[i]]++;
    }
    for(int i = 0 ; i< m ;i++)
    {
        strFreq[str[i]]++;
    }
    if(ptnFreq == strFreq)
    {
        ans.push_back(0);
    }
    for(int i =m ;i < n; i++)
    {
        strFreq[str[i]]++;
        if(strFreq[str[i-m]] == 1)
        {
            strFreq.erase(str[i-m]); 
        }
        else
        {
            strFreq[str[i-m]]--;
        }
        if( strFreq == ptnFreq)
        {
            ans.push_back(i-m+1);
        }
    }
    return ans;
}
        
    
};