class Solution {
public:
	int countVowelPermutation(int n) {
		long a=1,e=1,i=1,o=1,u=1;
		int mod=1e9+7;
		for(int j=2;j<=n;j++){
			long A=(e)%mod;
			long E=(a+i)%mod;
			long I=(a+e+o+u)%mod;
			long O=(i+u)%mod;
			long U=(a)%mod;
			a=A;
			e=E;
			i=I;
			o=O;
			u=U;
		}
		return (a+e+i+o+u)%mod;


	}
};