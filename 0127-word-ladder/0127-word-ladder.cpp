class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>&List) {
        int n=List.size();
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>st(List.begin(),List.end());
        st.erase(beginWord);
        while(!q.empty()){
            auto cur=q.front();
            string temp=cur.first;
            q.pop();
            if(temp==endWord){
                return cur.second;
            }
            
            for(int i=0;i<cur.first.size();i++){
                char org= temp[i];
                for(char j='a';j<='z';j++){
                    temp[i]=j;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp,cur.second+1});
                    }
                }
                temp[i]=org;
            }
        }
        return 0;
    }
};