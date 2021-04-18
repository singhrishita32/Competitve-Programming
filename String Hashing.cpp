#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//Strig Hashing : idea is to assign an integer to a string
//The hashing used id called polynomial rolling hash function
// probability of collision depends on m
int compute_hash(string s)
{
	int p=31;
	int m=1e9+9;
	int ans=0;
	int f=1;
	for(auto c:s)
	{
		ans=(ans+(c-'a')*f)%m;
		f=f*p;
	}
	return ans;
}
//Search for duplicate strings from an array of strings
vector <vector <int> > grouping_identical (vector <string> s)
{
	int n=s.size();
	vector <pair <int,int> > hash(n);
	int i=0;
	for(auto x:s)
	{
		hash.push_back({compute_hash(x),i});
		i++;
	}
	sort(hash.begin(),hash.end());
	
	vector<vector<int>> group;
	for(int i=0;i<n;i++)
	{
		if(i!=0 && hash[i].first!=hash[i-1].first)
		group.emplace_back();// to add one column
		
		group.back().push_back(hash[i].second);
	}
	return group;
}
int32_t main() 
{ 
	vector <string> s={"hello","abcd","hello","pink","pink","rish","abcd"};
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<" "<<compute_hash(s[i])<<" "<<endl;
	}

}
