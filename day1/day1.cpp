#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num1;
int	 num2[200000];

int main()
{
	int n1, n2;
	int hap = 0;
	for (int i = 0; i < 1000; i++)
	{
		cin>>n1>>n2;
		num1.push_back(n1);
		num2[n2] += 1;
	}
	sort(num1.begin(), num1.end());
	for (int i = 0; i < 1000; i++)
	{
		hap += num1[i] * num2[num1[i]];
	}
	cout<<hap<<endl;
	return (0);
}