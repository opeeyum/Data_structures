#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> pascals_triangle(int n)
{
	vector <vector<int>> result(n);
	for(int i=0; i<n; i++)
	{
		result[i].resize(i+1);
		result[i][0] = result[i][i] = 1;
		for(int j=1; j<i; j++)
			result[i][j] = result[i-1][j-1] + result[i-1][j];
	}

	return result;
}

int main()
{
	for(int i=1; i<10; i++)
	{
		vector <vector<int>> result(i);
		result = pascals_triangle(i);
		for(int j=0; j<result.size(); j++)
		{
			for(int k=0; k<result[j].size(); k++)
				cout<<result[j][k]<<" ";
			cout<<endl;
		}
		cout<<"-------------------------------------"<<endl;
	}
	
}