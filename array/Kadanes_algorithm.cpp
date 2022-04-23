#include <iostream>
using namespace std;

int maximum_sum_subarray(int *arr, int n)
{
	int local_max, global_max;
	local_max = global_max = arr[0];

	for(int i=1; i<n; i++)
	{
		local_max = arr[i] > arr[i]+local_max ? arr[i] : arr[i]+local_max;
		global_max = global_max > local_max ? global_max : local_max;
	}

	return global_max;
}

int main()
{
	int n_one = 9;
	int n_two = 4;
	int n_three = 1;

	int arr_one[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int arr_two[] = {4, -1, 2, 1};
	int arr_three[] = {1};

	cout<<maximum_sum_subarray(arr_one, n_one)<<endl;
	cout<<maximum_sum_subarray(arr_two, n_two)<<endl;
	cout<<maximum_sum_subarray(arr_three, n_three)<<endl;

}