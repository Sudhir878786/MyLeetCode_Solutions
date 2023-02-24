class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
//         int ans=0;
//         unordered_set<int>s;
//         for(int i=0;i<arr.size();i++){
//             int cur=arr[i];
//             s.insert(cur);
//             for(int j=i+1;j<arr.size();j++){
//                 cur|=arr[j];
//                 s.insert(cur);
               
//             }
//         }
//         return s.size();
        
        // as it give TLE  
        
        
        unordered_set<int>s;
        for(int i=0;i<arr.size();i++){
            int prevor=0;
            int curor=arr[i];
            int j=i-1;
            s.insert(arr[i]);
            while(j>=0 and curor!=prevor){
                curor|=arr[j];
                prevor|=arr[j];
                s.insert(curor);
                j--;
            }
        }
        return s.size();
    }
};