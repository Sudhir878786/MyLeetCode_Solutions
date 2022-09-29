class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int i=0;
        int j=arr.size()-1;   // take two pointer i and j
        
        while(j-i>=k){           // take upto k elements
            
            if((x-arr[i])>((arr[j])-x)){  // chck the condition 
                
                i++;                           // increase the pointer
                // cout<<'a';
            }
            else{
                j--;                           // decrease the pointer
            }
        }
        for(int x=i;x<=j;x++){                  // loop from i->j  and push the elements in ans
            ans.push_back(arr[x]);
        }
        
        return ans;
    }
};