#include<bits/stdc++.h>
using namespace std;


struct mystruct
{
	string name;
	int height;
	bool operator<(mystruct o)  //ading internal less than operator in struct
	{
		return height<o.height;
	}
	bool operator>(mystruct o) //adding internal greater than operator in struct
        {
                return height>o.height;
        }

};



int main()
{
	cout<<(mystruct{"sandeep",6}>mystruct{"mishra",5})<<endl;
	mystruct arr[2] = {mystruct{"sandeep",6}, mystruct{"mishra",5}};
	sort(arr, arr+2, [](mystruct a, mystruct b)->bool{return a.height<b.height;});    //sorting structs using lambda function
	sort(arr, arr+2, [](mystruct a, mystruct b){return a.height<b.height;});   //because only one return statement return type may not be given.
	for(int i=0;i<2;i++)
	{
		cout<<arr[i].name<<endl;
	}
	return 0;
}

