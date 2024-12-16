#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	std::ifstream	readFile;
	std::string		filename;
	std::string		line;
	std::ofstream	outfile;
	std::string	words;
	long 	hap = 0;


	filename = "input.txt";
	
	readFile.open(filename.c_str());
	while (!readFile.eof())
	{
		std::istringstream	ss;
		vector<int>	num;

		getline(readFile, line);
		while (getline(ss, line, ' '))
		{
			int n;
			
			n = atoi(words.c_str());
			num.push_back(n);
		}
		if (check())
	}
	
	cout<<hap<<endl;
}