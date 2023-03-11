//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& List) {
        // Code here
        if(List.size()==0)return 0;
        queue<pair<string,int>>q;
        q.push({startWord,1});
        set<string>st(List.begin(),List.end());
        st.erase(startWord);
        while(!q.empty()){
            auto cur=q.front();
            string t=cur.first;
            int ans=cur.second;
            q.pop();
            if(t==targetWord){
                return ans;
            }
            // cout<<t<<" "<<ans<<endl;
            for(int i=0;i<t.size();i++){
                char org= t[i];
                for(int j='a';j<='z';j++){
                    t[i]=j;
                    if(st.find(t)!=st.end()){
                        q.push({t,ans+1});
                        st.erase(t);
                    }
                }
                t[i]=org;
                
            }
            
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends