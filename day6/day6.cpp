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
	std::string		words;
	std::ofstream	outfile;
	vector<string>	input;
	int	len;
	int size_all = 2;
	int	p_x, p_y;
	int	n_x, n_y;
	long long hap = 0;
	string	q;

	filename = "input.txt";
	
	readFile.open(filename.c_str());
	while (!readFile.eof())
	{
		std::istringstream	ss;

		getline(readFile, line);
		if (input.size() == 0)
		{
			q = line;
			for (int i = 0; i < q.length(); i++)
			{
				q[i] = 'K';
			}
			q = 'K' + q + 'K';
			input.push_back(q);
		}
		line = 'K' + line + 'K';
		input.push_back(line);
		size_all++;
	}
	input.push_back(q);
	len = input[0].length();
	for (int i = 0; i < size_all; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (input[i][j] == '^')
			{
				p_y = i;
				p_x = j;
				break;
			}
		}
	}
	for (int i = 0; i < size_all; i++)
	{
		for (int j = 0; j < len; j++)
		{
			vector<string>	temp = input;
			if (input[i][j] != '.')
				continue;
			n_x = 0;
			n_y = -1;
			int x = p_x;
			int y = p_y;
			int flag = true;
			temp[i][j] = '#';

			for (int u = 0; u < 10000; u++)
			{
				if (temp[y + n_y][x + n_x] == 'K')
				{
					flag = false;
					break;
				}
				if (temp[y + n_y][x + n_x] != '#')
				{
					//temp[y][x] = 'X';
					y += n_y;
					x += n_x;
				}
				else
				{
					if (n_y == -1 && n_x == 0)
					{
						n_y = 0;
						n_x = 1;
					}
					else if (n_y == 0 && n_x == 1)
					{
						n_y = 1;
						n_x = 0;
					}
					else if (n_y == 1 && n_x == 0)
					{
						n_y = 0;
						n_x = -1;
					}
					else if (n_y == 0 && n_x == -1)
					{
						n_y = -1;
						n_x = 0;
					}
				}
			}
			if (flag)
				hap++;
		}
	}
	
	cout<<hap<<endl;
}