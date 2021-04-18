#include <bits/stdc++.h>
using namespace std;

struct dsu{
	int connected;
	vector <int> sze,parent;
	
	dsu(int n)
	{
		for(int i=0;i<n;i++)
		{
			parent.push_back(i);
			sze.push_back(1);
		}
		connected=n;
	}
	
	int find(int u)
	{
		if(parent[u]==u)
		return u;
		
		return parent[u]=find(parent[u]);
	}
	
	void unite(int a, int b)
	{
		int parent_a=find(a);
		int parent_b=find(b);
		if(parent_a!=parent_b)
		{
			int size_a=sze[parent_a];
			int size_b=sze[parent_b];
			if(size_a<size_b)
				swap(size_a,size_b);
			
			parent[parent_b]=parent_a;
			sze[parent_a]+=sze[parent_b];
		}
		
	}
	
	void components()
	{
		int c=0;
		for(int i=0;i<parent.size();i++)
		{
			if(i==parent[i])
			c++;
		}
		connected=c;
	}
};
int main()
{
	//Sample input to test
	 dsu obj(10);
	 cout<<obj.connected<<endl;
	 obj.unite(2,1);
	 obj.unite(1,4);
	 obj.components();
	 cout<<obj.connected;
}
