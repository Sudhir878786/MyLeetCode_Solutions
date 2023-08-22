class Solution {
public:
    void func(int i,int j,unordered_set<string>&st,queue<string>&q,string temp)
    {
        if(j>=0 and j<6){
            swap(temp[i],temp[j]);
            if(st.find(temp)==st.end()){
                st.insert(temp);
                q.push(temp);
            }
            swap(temp[i],temp[j]);
            
        }
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        string target="123450";
        string cur="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cur+=to_string(board[i][j]);
            }
        }
        unordered_set<string>st;
        st.insert(cur);
        queue<string>q;
        int count=0;
        q.push(cur);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto temp=q.front();
                q.pop();
                if(temp==target){
                    return count;
                }
                int ind=temp.find("0");
                // cout<<ind<<endl;
                // find each state in st if not present then insert tp queue an undo the swap fpr next state
                if(ind!=2){
                    func(ind,ind+1,st,q,temp);
                }
                if(ind!=3){
                    func(ind,ind-1,st,q,temp);
                }
                func(ind,ind+3,st,q,temp);
                func(ind,ind-3,st,q,temp);
                // break;
            }
            count++;
        }
        return -1;
    }
};