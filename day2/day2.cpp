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
	int hap = 0;

	filename = "t";
	readFile.open(filename.c_str());
	while (!readFile.eof())
	{
		std::istringstream	ss;
		vector<int> temp;
		int n;
		getline(readFile, line);
		ss.str(line);
		while (getline(ss, words, ' '))
		{
			n = atoi(words.c_str());
			temp.push_back(n);
		}
		num.push_back(temp);
	}

	for (int i = 0; i < static_cast<int>(num.size()); i++)
	{
		bool	flag = true;
		for (int k = 0; k < static_cast<int>(num[i].size()); k++)
		{
			vector<int>	level = num[i];
			bool	check = true;
			bool	up = true;
			flag = true;

			level.erase(level.begin() + k);

			if (level.size() < 2)
				break;
			if (level[0] - level[1] > 0)
				up = false;
			
			for (int j = 1; j < static_cast<int>(level.size()); j++)
			{
				if (up)
				{
					if (level[j] - level[j - 1] >= 1 && level[j] - level[j - 1] <= 3)
						continue;
					flag = false;
					break;
				}
				else
				{
					if (level[j - 1] - level[j] >= 1 && level[j - 1] - level[j] <= 3)
						continue;
					flag = false;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			hap += 1;
	}

	cout<<hap<<endl;
}