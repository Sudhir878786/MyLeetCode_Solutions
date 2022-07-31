class NumArray {
public:
    vector<int>arr;
    int tot=0;
    NumArray(vector<int>& nums) {
        arr=nums;
        for(auto it:nums){
            tot+=it;   // total sum of unupdated arr
        }
        
    }
    
    void update(int index, int val) {
        tot-=arr[index];     // substract the updated val from total sum
        arr[index]=val;   //update
        tot+=val;    // add the current updated value in total sum;
    }
    
    int sumRange(int left, int right) {
        int ans=tot;
        for (int i = 0; i < left; i++) {
			ans -= arr[i];
		}
		// subtract values after right
		for (int i = right + 1; i < arr.size(); i++) {
			ans -= arr[i];
		}
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */