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
	std::string		check;
	std::ofstream	outfile;
	int flag = true;
	long long hap = 0;

	filename = "input.txt";
	readFile.open(filename.c_str());
	while (!readFile.eof())
	{
		std::istringstream	ss;
		std::istringstream	ss2;

		getline(readFile, line);
		ss.str(line);

		while (getline(ss, words, 'm'))
		{
			int len = 7;
			int a = 0;
			int b = 0;
			int idx = 3;

			ss2.str(words);
			if (words.length() >= len && words[0] == 'u' && words[1] == 'l' && words[2] == '(')
			{
				for (int i = 3; i < words.length(); i++)
				{
					if (words[i] >= '0' && words[i] <= '9')
						a = a * 10 + words[i] - '0';
					else
						break;
					idx++;
					len++;
				}
				len--;
				if (words.length() >= len && words[idx++] == ',')
				{
					for (int i = idx; i < words.length(); i++)
					{
						if (words[i] >= '0' && words[i] <= '9')
							b = b * 10 + words[i] - '0';
						else
							break;
						idx++;
						len++;
					}
					len--;
					if (words.length() >= len && words[idx] == ')' && flag)
					{
						hap += a * b;
					}
				}
			}
			idx = 0;
			while (1)
			{
				if (words[idx] == 'd')
				{
					words = words.substr(idx + 1);
					if (words.length() >= 3 && words[0] == 'o' && words[1] == '(' && words[2] == ')')
					{
						flag = true;
						words = words.substr(3);
					}
					if (words.length() >= 6 && words.substr(0, 6) == "on't()")
					{
						flag = false;
						words = words.substr(6);
					}
				}
				if (words.length() < 3)
					break;
				words = words.substr(1);
			}
		}
	}
	cout<<hap<<endl;
}