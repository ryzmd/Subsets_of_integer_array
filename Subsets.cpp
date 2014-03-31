#include<iostream>
#include<stdlib.h>
#include <vector>

using namespace std;
int number=0;

vector< vector< int > > subset(vector< int > a, int n);
vector< vector< int > > union_subset(vector< vector< int > >, vector< vector< int > >);
vector< vector< int > > append(vector< vector< int > >, int n);

int main()
{
	vector< int > a;
	cout<<"Enter the number of numbers you are going to enter:\n";
	cin>>number;
 	int i=0;
	cout<<"Enter "<<number<<" numbers :\n";
	int value;
	for(i=0;i<number;i++)
	{
		cin>>value;
		a.push_back(value);
	}
	vector< vector< int > > subsets;
	subsets=subset(a,number);
	int x = subsets.size();
	int y=0,j=0,k=0;
	for(i=0;i<x;i++)
	{
		if(subsets[i][0]==-2000000)
		{
			subsets[i][0]=subsets[i].back();
			subsets[i].pop_back();
		}
	}
	cout<<"THE SUBSETS ARE:\n\n";
	for(k=0;k<=number;k++)
	{
		for(i=0;i<x;i++)
		{
			y=subsets[i].size();
			if(k==y)
			{
				if(y==0)
				{
					cout<<"NULL"<<endl;
					continue;
				}
				cout<<"{";
				for(j=0;j<y-1;j++)
				{
					cout<<subsets[i][j]<<", ";
				}
				cout<<subsets[i][y-1]<<"}";
				cout<<endl;
			}
		}
	}
	return 0;
}

vector< vector< int > > subset(vector< int > a, int n)
{
	vector< vector< int > > temp;
	if(n!=1)
	{
		int i=0;
		temp=subset(a,n-1);
		vector< vector< int > > temp2=temp;
		for(i=0;i< temp2.size();i++)
		{
			temp2[i].push_back(a[n-1]);
		}
		temp=union_subset(temp,temp2);
	}
	else
	{
		vector< int > x;
		x.push_back(-2000000);
		temp.push_back(x);
		x=vector< int > ();
		x.push_back(a[0]);
		temp.push_back(x);
	}
	return temp;
}
vector< vector< int > > union_subset(vector< vector< int > > a, vector< vector< int > > b)
{
	int a_size=a.size();
	int b_size=b.size();

	int i=0,j=0;
	for(i=0;i<b_size;i++)
	{
		a.push_back(b[i]);
	}
	return a;
}
