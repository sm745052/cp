#include<bits/stdc++.h>
using namespace std;


template<class T, class K>		//every declared value must be used in function arguments
T add(T a, K b)
{
	return a+b;
}



int main()
{
	cout<<add(3.1, 4)<<endl;
	cout<<add(string("sandeep"), string(" mishra"))<<endl;
	return 0;
}
