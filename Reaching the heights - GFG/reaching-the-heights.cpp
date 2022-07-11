// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
   sort(a,a+n,greater<int>());
   vector<int> v;
   int k=n-1;
   int i=0,res=0;;
   while(i<=k){
       v.push_back(a[i++]);
       v.push_back(a[k--]);
   }
   for(int i=0;i<n;i++){
       if(i%2==0) res+=v[i];
       else res-=v[i];
       if(res==0)return {-1};
   }
   if(res>0){
       if(n%2==1)v.pop_back();
   }
   return v;
}