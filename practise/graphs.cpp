#include<bits/stdc++.h>
using namespace std;

struct
{
};



void add_node(vector<vector<pair<int, int> > > &g, int n)
{
	g.push_back(vector<pair<int, int> >());
}

void add_edge(vector<vector<pair<int, int> > > &g, int na, int nb, int w)
{
	g[na].push_back(make_pair(nb, w));
	g[nb].push_back(make_pair(na, w));
}

int main()
{
	vector<vector<pair<int, int> > > g;
	for(int i=0;i<5;i++)
	{
		add_node(g, i);
	}
	cout<<"Nodes set"<<endl;
	add_edge(g, 0, 1, 100);
	add_edge(g, 0, 2, 120);
	add_edge(g, 0, 3, 200);
	add_edge(g, 0, 4, 190);
	add_edge(g, 1, 2, 75);
	add_edge(g, 1, 3, 75);
	add_edge(g, 1, 4, 80);
	add_edge(g, 2, 3, 110);
	add_edge(g, 2, 4, 90);
	add_edge(g, 3, 4, 50);
	cout<<"Edges Added"<<endl;





	return 0;
}
