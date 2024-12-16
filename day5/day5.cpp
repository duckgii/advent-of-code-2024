#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<vector<int> > num;

int main()
{
	std::ifstream	readFile;
	std::string		filename;
	std::string		line;
	std::string		words;
	std::ofstream	outfile;
	int flag = true;
	long long hap = 0;

	filename = "input2.txt";
	
	for (int i = 0; i < 101; i++)
	{
		vector<int> temp;
		num.push_back(temp);
	}
	readFile.open(filename.c_str());
	while (!readFile.eof())
	{
		std::istringstream	ss;
		vector<int>	check;
		getline(readFile, line);

		if (line.length() < 2)
			continue;
		if (line[2] != '|')
		{
			vector<int>	a;
			check = a;
		}

		ss.str(line);

		if (line[2] == '|')
		{
			int n1, n2;

			n1 = atoi(line.substr(0, 2).c_str());
			n2 = atoi(line.substr(3, 2).c_str());
			num[n1].push_back(n2);
		}
		while (line[2] != '|' && getline(ss, words, ','))
		{
			check.push_back(atoi(words.c_str()));
		}
		if (line[2] != '|')
		{
			int idx = 1;
			int flag = true;
			while (idx < static_cast<int>(check.size()))
			{
				vector<int>	my = num[check[idx]];
				for (int i = 0; i < static_cast<int>(my.size()); i++)
				{
					int n = my[i];
					for (int j = 0; j < idx; j++)
					{
						if (check[j] == n)
						{
							check[j] = check[idx];
							check[idx] = n;
							flag = false;
							idx = 0;
						}
					}
				}
				idx++;
			}
			if (!flag)
				hap += check[check.size() / 2];
		}
	}
	cout<<hap<<endl;
}