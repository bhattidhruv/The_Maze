//#include<iostream>
//#include<vector>
//#include<fstream>
//#include<stack>
//#include<queue>
//using namespace std;
//class cell {
//public:
//
//	int id;
//	int wall;
//	bool visited;
//	bool in_structure;
//	int from;
//
//};
//
//void display(std::vector<int> vec, int n, int start, int end)
//{
//	sort(vec.begin(), vec.end());
//	int c = sqrt(n);
//	std::cout << "\n";
//	int k = 0;
//	int countLine = 0;
//	for (int i = 0; i < n; i++)
//	{
//		countLine++;
//		if (countLine % c == 1)
//		{
//			std::cout << "\n";
//			for (int i = 0; i < c * 7; i++)
//				std::cout << "=";
//			std::cout << "\n";
//		}
//
//
//		if (k < vec.size() && vec[k] == i)
//		{
//			if (i == end)
//			{
//				std::cout << "(end)" << "||";
//				k++;
//			}
//			else if (i == start)
//			{
//				std::cout << "(sta)" << "||";
//				k++;
//			}
//			else
//			{
//				std::cout << "  @  " << "||";
//				k++;
//			}
//		}
//		else
//			std::cout << "  -  " << "||";
//
//	}
//	std::cout << "\n\n";
//}
//
//
//
//
//void DFS(std::vector<cell>& maze, int n, int start, int end)
//{
//	cell& obj = maze[start];
//	obj.in_structure = true;
//	obj.from = start;
//	std::stack <cell> st;
//	st.push(maze[start]);
//
//	while (!st.empty())
//	{
//		int root = std::sqrt(n);
//		cell& obj1 = st.top();
//		st.pop();
//		obj1.visited = true;
//		maze[obj1.id].visited = true;
//		obj1.in_structure = false;
//		maze[obj1.id].in_structure = false;
//		if (obj1.id == end)
//		{
//			break;
//		}
//
//		int wall = obj1.wall;
//		bool top = false, bottom = false, right = false, left = false;
//		std::vector<int> path{ 8,4,2,1 };
//		std::vector<bool> abc{ false,false,false,false };
//		int kk = -1;
//		for (int a : path)
//		{
//			kk++;
//			if (wall - a >= 0)
//			{
//				wall = wall - a;
//				abc[kk] = true;
//			}
//		}
//		left = abc[0];
//		top = abc[1];
//		right = abc[2];
//		bottom = abc[3];
//
//
//		int k = obj1.id;
//
//		if (right == false)
//		{
//			if (maze[k + 1].visited == false)
//			{
//				maze[k + 1].from = k;
//				maze[k + 1].in_structure = true;
//				st.push(maze[k + 1]);
//
//			}
//		}
//		if (left == false)
//		{
//			if (k - 1 >= 0)
//			{
//				if (maze[k - 1].visited == false)
//				{
//					maze[k - 1].in_structure = true;
//					maze[k - 1].from = k;
//					st.push(maze[k - 1]);
//				}
//			}
//
//		}
//		if (top == false)
//		{
//			if (k - root >= 0 && maze[k - root].visited == false)
//			{
//				maze[k - root].from = k;
//				maze[k - root].in_structure = true;
//				st.push(maze[k - root]);
//			}
//		}
//		if (bottom == false)
//		{
//			if (k + root < n && maze[k + root].visited == false)
//			{
//				maze[k + root].from = k;
//				maze[k + root].in_structure = true;
//				st.push(maze[k + root]);
//			}
//		}
//
//	}
//	std::vector<int>cc;
//	int a = end;
//	cc.push_back(a);
//	while (maze[a].id != maze[a].from)
//	{
//		cc.push_back(maze[a].from);
//		a = maze[a].from;
//	}
//	std::reverse(cc.begin(), cc.end());
//	for (int i = 0; i < cc.size(); i++)
//	{
//		if (i == cc.size() - 1)
//			std::cout << cc[i];
//		else
//			std::cout << cc[i] << "-> ";
//	}
//	display(cc, n, start, end);
//}
//
//void BFS(std::vector<cell>& maze, int n, int start, int end)
//{
//	cell& obj = maze[start];
//	obj.in_structure = true;
//	obj.from = start;
//	std::queue <cell> st;
//	st.push(maze[start]);
//
//	while (!st.empty())
//	{
//		int root = std::sqrt(n);
//		cell& obj1 = st.front();
//		st.pop();
//		obj1.visited = true;
//		maze[obj1.id].visited = true;
//		obj1.in_structure = false;
//		maze[obj1.id].in_structure = false;
//		if (obj1.id == end)
//		{
//			break;
//		}
//
//		int wall = obj1.wall;
//		bool top = false, bottom = false, right = false, left = false;
//		std::vector<int> path{ 8,4,2,1 };
//		std::vector<bool> abc{ false,false,false,false };
//		int kk = -1;
//		for (int a : path)
//		{
//			kk++;
//			if (wall - a >= 0)
//			{
//				wall = wall - a;
//				abc[kk] = true;
//			}
//		}
//		left = abc[0];
//		top = abc[1];
//		right = abc[2];
//		bottom = abc[3];
//
//
//		int k = obj1.id;
//
//		if (right == false)
//		{
//			if (maze[k + 1].visited == false)
//			{
//				maze[k + 1].from = k;
//				maze[k + 1].in_structure = true;
//				st.push(maze[k + 1]);
//
//			}
//		}
//		if (left == false)
//		{
//			if (k - 1 >= 0)
//			{
//				if (maze[k - 1].visited == false)
//				{
//					maze[k - 1].in_structure = true;
//					maze[k - 1].from = k;
//					st.push(maze[k - 1]);
//				}
//			}
//
//		}
//
//		if (top == false)
//		{
//			if (k - root >= 0 && maze[k - root].visited == false)
//			{
//				maze[k - root].from = k;
//				maze[k - root].in_structure = true;
//				st.push(maze[k - root]);
//			}
//		}
//		if (bottom == false)
//		{
//			if (k + root < n && maze[k + root].visited == false)
//			{
//				maze[k + root].from = k;
//				maze[k + root].in_structure = true;
//				st.push(maze[k + root]);
//			}
//		}
//
//
//
//
//
//
//
//	}
//	std::cout << "\n";
//	std::vector<int>cc;
//	int a = end;
//	cc.push_back(a);
//	while (maze[a].id != maze[a].from)
//	{
//		cc.push_back(maze[a].from);
//		a = maze[a].from;
//	}
//	std::reverse(cc.begin(), cc.end());
//	for (int i = 0; i < cc.size(); i++)
//	{
//		if (i == cc.size() - 1)
//			std::cout << cc[i];
//		else
//			std::cout << cc[i] << "-> ";
//	}
//	display(cc, n, start, end);
//}
//
//int main()
//{
//	int numCells;
//	int start;
//	int target;
//
//	std::ifstream in("maze.txt");
//	in >> numCells >> start >> target;
//	int i = 0;
//	std::vector<cell> vec, vec1;;
//
//	while (in)
//	{
//
//		cell obj;
//		obj.id = i++;
//		in >> obj.wall;
//		obj.from = -1;
//		obj.in_structure = false;
//		obj.visited = false;
//		vec.push_back(obj);
//	}
//	vec.erase(vec.begin() + numCells, vec.end());
//	if (vec.size() == 0)
//		return 0;
//	vec1 = vec;
//	DFS(vec, numCells, start, target);
//	BFS(vec1, numCells, start, target);
//	getchar();
//	return 0;
//}