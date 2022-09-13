class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<string> v;
        for(int i=0;i<data.size();i++) {
            string s = bitset<8> (data[i]).to_string();
            v.push_back(s ); //binary representation
        }
        int count = 0;
        for(auto s: v) {
            if(count==0) {
                if( s[0]=='1' && s[1]=='1' && s[2]=='0') count =1; // 2 byte encoding
                else if(s[0]=='1' && s[1]=='1' && s[2]=='1' && s[3]=='0') count=2; //3 byte encoding
                else if(s[0]=='1' && s[1]=='1' && s[2]=='1' && s[3]=='1' && s[4]=='0') count=3; // 4 byte encoding
                else if( s[0]!='0') return false; //0 byte encoding
            } else {
                if(s[0]=='1' && s[1]=='0') count--;
                else return false;
            }
        }
        return count==0;
    }
};