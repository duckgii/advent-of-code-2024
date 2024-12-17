#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <utility>

using namespace std;

//       1,0
//   0,-1  0  0,1
//      -1,0

long bfs[150][150];

int main()
{
	std::ifstream			readFile;
	std::string				filename;
	std::string				line;
	std::string				words;
	vector<string>			data;
	pair<long, long>			goal;
	queue<pair<pair<long, long>, pair<long, long> > >	next;
	long arr[4];
	long 	ret = 1000000000000000;


	filename = "input.txt";
	for (long i = 0; i < 150; i++)
	{
		for (long j = 0; j < 150; j++)
		{
			bfs[i][j] = 30000;
		}
	}
	readFile.open(filename.c_str());
	while (!readFile.eof())
	{
		getline(readFile, line);
		data.push_back(line);
	}
	for (long i = 0; i < static_cast<long>(data.size()); i++)
	{
		for (long j = 0; j < data[0].length(); j++)
		{
			if (data[i][j] == 'S')
			{
				next.push(make_pair(make_pair(i, j), make_pair(0, 1)));
				bfs[i][j] = 0;
			}
			if (data[i][j] == 'E')
			{
				goal = make_pair(i, j);
			}
		}
	}

	while (next.size())
	{
		long x = next.front().first.first;
		long y = next.front().first.second;
		long dir_y = next.front().second.first;
		long dir_x = next.front().second.second;
		long arr[4];

		next.pop();
		data[x][y] = 'o';
		if (dir_y != -1 && data[x + 1][y] != '#')
		{
			if (data[x + 1][y] == 'E')
				bfs[x + 1][y] = min(bfs[x][y] + 1 + 1000 * (abs(dir_x) + (dir_y == -1 ? 1 : 0)), bfs[x + 1][y]);
			else
			{
				if (data[x + 2][y] == '#')

				if (bfs[x + 1][y] != min(bfs[x][y] + 1 + 1000 * (abs(dir_x) + (dir_y == -1 ? 1 : 0)), bfs[x + 1][y]))
				{
					bfs[x + 1][y] = min(bfs[x][y] + 1 + 1000 * (abs(dir_x) + (dir_y == -1 ? 1 : 0)), bfs[x + 1][y]);
					next.push(make_pair(make_pair(x + 1, y), make_pair(1, 0)));
				}
			}
		}
		if (dir_x != -1 && data[x][y + 1] != '#')
		{
			if (data[x][y + 1] == 'E')
				bfs[x][y + 1] = min(bfs[x][y] + 1 + 1000 * (abs(dir_y) + (dir_x == -1 ? 1 : 0)), bfs[x][y + 1]);
			else
			{
				if (bfs[x][y + 1] != min(bfs[x][y] + 1 + 1000 * (abs(dir_y) + (dir_x == -1 ? 1 : 0)), bfs[x][y + 1]))
				{
					bfs[x][y + 1] = min(bfs[x][y] + 1 + 1000 * (abs(dir_y) + (dir_x == -1 ? 1 : 0)), bfs[x][y + 1]);
					next.push(make_pair(make_pair(x, y + 1), make_pair(0, 1)));
				}
			}
		}
		if (dir_y != 1 && data[x - 1][y] != '#')
		{
			if (data[x - 1][y] == 'E')
				bfs[x - 1][y] = min(bfs[x][y] + 1 + 1000 * (abs(dir_x) + (dir_y == 1 ? 1 : 0)), bfs[x - 1][y]);

			else
			{
				if (bfs[x - 1][y] != min(bfs[x][y] + 1 + 1000 * (abs(dir_x) + (dir_y == 1 ? 1 : 0)), bfs[x - 1][y]))
				{
					bfs[x - 1][y] = min(bfs[x][y] + 1 + 1000 * (abs(dir_x) + (dir_y == 1 ? 1 : 0)), bfs[x - 1][y]);
					next.push(make_pair(make_pair(x - 1, y), make_pair(-1, 0)));
				}
			}
		}
		if (dir_x != 1 && data[x][y - 1] != '#')
		{
			if (data[x][y - 1] == 'E')
				bfs[x][y - 1] = min(bfs[x][y] + 1 + 1000 * (abs(dir_y) + (dir_x == 1 ? 1 : 0)), bfs[x][y - 1]);
			else
			{
				if (bfs[x][y - 1] != min(bfs[x][y] + 1 + 1000 * (abs(dir_y) + (dir_x == 1 ? 1 : 0)), bfs[x][y - 1]))
				{
					bfs[x][y - 1] = min(bfs[x][y] + 1 + 1000 * (abs(dir_y) + (dir_x == 1 ? 1 : 0)), bfs[x][y - 1]);
					next.push(make_pair(make_pair(x, y - 1), make_pair(0, -1)));
				}
			}
		}
	}
	//for (long i = 0; i < static_cast<long>(data.size()); i++)
	//{
	//	for (long j = 0; j < data[0].length(); j++)
	//	{
	//		cout<<data[i][j];
	//	}
	//	cout<<endl;
	//}
	for (long i = 0; i < static_cast<long>(data.size()); i++)
	{
		for (long j = 0; j < data[0].length(); j++)
		{
			cout.width(5);
			cout<<bfs[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<bfs[goal.first][goal.second]<<endl;
}

//queue는 queue<long[4]>와 같은 형태로 선언은 불가능하다.
//-> 다시 풀어야 한다.
// 이 방향으로 갈 때 다다음 블록이 벽이면 방향을 바꿔야 하니까 1000 더하고 방향 정해서 돌려야함
