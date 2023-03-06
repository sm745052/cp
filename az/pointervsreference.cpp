#include<bits/stdc++.h>
using namespace std;
struct mystruct
{
	string name;
	int height;
};
struct mynewstruct
{
	string name;
	vector<int> heights;
};
void edit(int arr[])
{
	arr[1]=3;
}
void edit(mystruct& a)
{
	a.height++;
}
void edit(mystruct* a)
{
	a->height++;
}
void edit(mynewstruct& b)
{
	b.heights[0]++;
}
int main()
{
	int arr[3] = {1, 2, 3};
	mystruct a = mystruct({"sandeep", 6});
	mynewstruct b;
	b.name="sandeep";
	b.heights=vector<int>{1, 2, 3, 4};
	edit(arr);
	edit(a);
	edit(&a);
	edit(b);
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<"mystruct\n";
	cout<<"name: "<<a.name<<endl<<"height: "<<a.height<<endl;
	cout<<"mynewstruct\n";
	cout<<"name: "<<b.name<<endl<<"heights: ";
	for(auto i:b.heights)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}
