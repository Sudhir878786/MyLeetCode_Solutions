//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
      // Code here
      int n=stations.size();
      double l=0;
      double r=stations[n-1]-stations[0];
      while(r-l>1e-6){
          double mid=(l+r)/2.0;
          int cur=0;
          for(int i=0;i<n-1;i++){
              cur+=(int)((stations[i+1]-stations[i])/mid);
          }
          if(cur>K){
              l=mid;
          }
          else{
              r=mid;
          }
      }
      return r;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends