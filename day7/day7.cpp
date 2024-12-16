#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool check(long firstNum, long retNum, queue<long> numArr)
{
	long	ret1 = retNum * numArr.front();
	long	ret2 = retNum + numArr.front();
	long	ret3 = retNum;
	long	frontNum = numArr.front();

	while (frontNum > 0)
	{
		ret3 *= 10;
		frontNum /= 10;
	}
	ret3 += numArr.front();
	if (numArr.size() == 1)
	{
		if (firstNum == ret1 || firstNum == ret2 || firstNum == ret3)
			return (true);
		return (false);
	}
	numArr.pop();
	if (check(firstNum, ret1, numArr) || check(firstNum, ret2, numArr) || check(firstNum, ret3, numArr))
		return (true);
	return (false);
}

int main()
{
	std::ifstream	readFile;
	std::string		filename;
	std::string		line;
	std::ofstream	outfile;
	std::string		words;
	long 			ret = 0;
	long 			hap = 0;


	filename = "input.txt";
	
	readFile.open(filename.c_str());
	while (!readFile.eof())
	{
		std::istringstream	ss;
		long firstNum;
		long retNum = 0;
		bool flag = false;
		queue<long>	numArr;

		getline(readFile, line);
		ss.str(line);
		getline(ss, words, ' ');
		firstNum = atol(words.c_str());
		getline(ss, words, ' ');
		retNum = atoi(words.c_str());
		while (getline(ss, words, ' '))
		{
			long n;
			
			n = atoi(words.c_str());
			numArr.push(n);
		}
		if (check(firstNum, retNum, numArr))
		{
			ret += firstNum;
		}
	}
	
	cout<<ret<<endl;
}
