// brute force O(n^3) TLE

//class Solution {
// public:
//     bool ispal(string s)
//     {
//         int i=0;
//         int j=s.size()-1;
//         while(i<j){
//             if(s[i]!=s[j]){
//                 return 0;
//             }
//             i++;j--;
//         }
//         return 1;
        
//     }
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         int n= words.size();
        
//         vector<vector<int>>ans;
        
//         for(int i=0;i<n;i++){
//            for(int j=i+1;j<n;j++){
//                string s1=words[i]+words[j];
//                string s2=words[j]+words[i];
//                if(ispal(s1)){
//                    vector<int>v;
//                    v.push_back(i);
//                    v.push_back(j);
//                    ans.push_back(v);
//                }
//                if(ispal(s2)){
//                    vector<int>v;
//                    v.push_back(j);
//                    v.push_back(i);
//                    ans.push_back(v);
//                }
//            }
//         }
//         return ans;
//     }
// };

#include<bits/stdc++.h>
class Solution {
public:
    
      bool isPalindrome(string& s) {   
          int l=0, r=s.size()-1;
          while(l<r){if(s[l++]!=s[r--]) return false;}
          return true; 
    }


    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        if(n<2) return ans;
        unordered_map<string, int> m;
        for(int i=0;i<n;++i){
            
            auto s= words[i];
            reverse(s.begin(),s.end());
            m[s]=i;
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<=words[i].size(); ++j){
                string st1 = words[i].substr(0,j); // prefix
                string st2 = words[i].substr(j);    //sufix           
                 
                 if(m.count(st1) && isPalindrome(st2) && m[st1] != i) {
                     ans.push_back({i, m[st1]});    
                 }

                 if(!st1.empty() && m.count(st2) && isPalindrome(st1) && m[st2] != i) {
                     ans.push_back({m[st2], i});
                 }
            }            
        }
        return ans;
    }

    
};