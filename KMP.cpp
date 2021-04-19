#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
vector <int> prefix;
void solve(string s)
{
	int n=s.size();
	prefix.resize(n,0);
	for(int i=1;i<n;i++)
	{
		int j=prefix[i-1];
		while(j>0 && s[i]!=s[j])
		j=prefix[j-1];
		
		prefix[i]=j;
		if(s[i]==s[j])
		prefix[i]++;
	}
}
int32_t main() 
{ 
	string s;
	cin>>s;
	solve(s);
	for(int i=0;i<prefix.size();i++)
	cout<<prefix[i]<<" ";
}
