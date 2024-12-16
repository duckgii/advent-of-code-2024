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
	std::istringstream	ss;
	vector<string>	input;
	long long hap = 0;

	filename = "input2.txt";
	readFile.open(filename.c_str());
	while (!readFile.eof())
	{
		std::istringstream	ss2;

		getline(readFile, line);
		input.push_back(line);
	}
	for (int i = 0; i < static_cast<int>(input.size()); i++)
	{
		for (int j = 0; j < static_cast<int>(input[0].length()); j++)
		{
			//if (j <= input[0].length() - 4)
			//{
			//	if (input[i].substr(j, 4) == "XMAS" || input[i].substr(j, 4) == "SAMX")
			//		hap++;
			//}
			//if (i <= static_cast<int>(input.size()) - 4)
			//{
			//	if ((input[i][j] == 'X' && input[i + 1][j] == 'M' && input[i + 2][j] == 'A' && input[i + 3][j] == 'S') || \
			//	 (input[i][j] == 'S' && input[i + 1][j] == 'A' && input[i + 2][j] == 'M' && input[i + 3][j] == 'X'))
			//	 	hap++;
			//}
			if (j <= input[0].length() - 3 && i >= 2)
			{
				if ((input[i][j] == 'M' && input[i - 1][j + 1] == 'A' && input[i - 2][j + 2] == 'S') || \
				 (input[i][j] == 'S' && input[i - 1][j + 1] == 'A' && input[i - 2][j + 2] == 'M'))
				{
					if ((input[i][j + 2] == 'M' && input[i - 1][j + 1] == 'A' && input[i - 2][j] == 'S') || \
					 (input[i][j + 2] == 'S' && input[i - 1][j + 1] == 'A' && input[i - 2][j] == 'M'))
				 		hap++;
				}
			}
			//if (j <= input[0].length() - 4 && i >= 3)
			//{
			//	if ((input[i][j] == 'X' && input[i - 1][j + 1] == 'M' && input[i - 2][j + 2] == 'A' && input[i - 3][j + 3] == 'S') || \
			//	 (input[i][j] == 'S' && input[i - 1][j + 1] == 'A' && input[i - 2][j + 2] == 'M' && input[i - 3][j + 3] == 'X'))
			//	 	hap++;
			//}
		}
	}
	cout<<hap<<endl;
}