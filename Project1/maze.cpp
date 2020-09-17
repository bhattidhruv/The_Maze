// Automation Maze Solver, DFS and BFS
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class cell {
public:
	int id;
	int wall;
	bool visited;
	bool in_structure;
	int from;

	cell() { id = -1; wall = 0; visited = false; in_structure = false; from = -1; }
};

void setUp(int Start, int NoC, int D, ifstream& in, vector<cell>& RoutingTable);
void DFS(vector<cell>& maze, int n, int start, int end);//end is target cell 
void BFS(vector<cell>& maze, int n, int start, int end);
void selectNeighbour(vector<cell>& maze, stack < cell >& s, cell cellobj, int NoC);
void bfsSelectNeighbour(vector<cell>& maze, queue < cell >& q, cell cellobj, int NoC);
void pritnOutput(vector<cell>& maze, int NoC, int start, int end);
void display(std::vector<int> vec, int NoC, int start, int end);

void setUp(int Start, int NoC, int D, ifstream& in, vector<cell>& RoutingTable) {

	int z = 0;
	int n;
	RoutingTable[Start].from = Start;

	for (int i = 0; i < NoC; i++) {
		RoutingTable[i].id = i;
	}
	while (in && z < NoC) {
		in >> n;
		RoutingTable[z].wall = n;
		z = z + 1;
	}
}

void selectNeighbour(vector<cell>& maze, stack < cell >& s, cell cellobj, int NoC) {

	vector<int> wallDefination{ 8 ,4,2,1 }; // left, up , right, down
	vector<bool> wallPresence{ false,false,false,false };

	int shift = std::sqrt(NoC);

	bool up = false, down = false, left = false, right = false;

	int fromCell = cellobj.id;
	int wallVal = cellobj.wall;

	int south = cellobj.id + shift;
	int east = cellobj.id + 1;
	int north = cellobj.id - shift;
	int west = cellobj.id - 1;

	int k = -1;

	for (int a = 0; a < wallDefination.size(); a++) {
		k++;
		if (wallVal - wallDefination[a] >= 0) {
			wallVal = wallVal - wallDefination[a];
			wallPresence[k] = true;
		}
	}

	if (wallPresence[0] == false) {
		left = true;
	}
	if (wallPresence[1] == false) {
		up = true;
	}
	if (wallPresence[2] == false) {
		right = true;
	}
	if (wallPresence[3] == false) {
		down = true;
	}

	/*	if (cellobj.wall == 8 && cellobj.in_structure == true)*/
		/*while(cellobj.in_structure == true) {*/

	maze[cellobj.id].in_structure = false;
	cellobj.in_structure = maze[cellobj.id].in_structure;

	if (down == true) {
		if (south >= 0 && south < NoC) {
			cellobj = maze[south];
			if (cellobj.visited == false) {
				cellobj.from = fromCell;
				cellobj.in_structure = true;
				maze[cellobj.id] = cellobj;
				s.push(cellobj);
			}
		}
	}
	if (right == true) {
		if (east >= 0 && east < NoC) {
			cellobj = maze[east];
			if (cellobj.visited != true) {
				cellobj.from = fromCell;
				cellobj.in_structure = true;
				maze[cellobj.id] = cellobj;
				s.push(cellobj);
			}
		}
	}
	if (up == true) {
		if (north >= 0 && north < NoC) {
			cellobj = maze[north];
			if (cellobj.visited != true) {
				cellobj.from = fromCell;
				cellobj.in_structure = true;
				maze[cellobj.id] = cellobj;
				s.push(cellobj);
			}
		}
	}
	if (left == true) {
		if (west >= 0 && west < NoC) {
			cellobj = maze[west];
			if (cellobj.visited != true) {
				cellobj.from = fromCell;
				cellobj.in_structure = true;
				maze[cellobj.id] = cellobj;
				s.push(cellobj);
			}
		}
	}	
}

void DFS(vector<cell>& maze, int n, int start, int end) {


	cell  cellObj;
	stack < cell > s;

	cellObj = maze[start];
	cellObj.in_structure = true;
	s.push(cellObj);

	while (!s.empty()) {

		cellObj = s.top();
		cellObj.visited = true;
		s.pop();
		maze[cellObj.id] = cellObj;

		selectNeighbour(maze, s, cellObj, n);
	}
}

void bfsSelectNeighbour(vector<cell>& maze, queue < cell >& q, cell cellobj, int NoC) {

	vector<int> wallDefination{ 8 ,4,2,1 }; // left, up , right, down
	vector<bool> wallPresence{ false,false,false,false };

	int shift = std::sqrt(NoC);

	bool up = false, down = false, left = false, right = false;

	int fromCell = cellobj.id;
	int wallVal = cellobj.wall;

	int south = cellobj.id + shift;
	int east = cellobj.id + 1;
	int north = cellobj.id - shift;
	int west = cellobj.id - 1;

	int k = -1;

	for (int a = 0; a < wallDefination.size(); a++) {
		k++;
		if (wallVal - wallDefination[a] >= 0) {
			wallVal = wallVal - wallDefination[a];
			wallPresence[k] = true;
		}
	}

	if (wallPresence[0] == false) {
		left = true;
	}
	if (wallPresence[1] == false) {
		up = true;
	}
	if (wallPresence[2] == false) {
		right = true;
	}
	if (wallPresence[3] == false) {
		down = true;
	}

	maze[cellobj.id].in_structure = false;
	cellobj.in_structure = maze[cellobj.id].in_structure;

	if (down == true) {
		if (south >= 0 && south < NoC) {
			cellobj = maze[south];
			if (cellobj.visited == false) {
				cellobj.from = fromCell;
				cellobj.in_structure = true;
				maze[cellobj.id] = cellobj;
				q.push(cellobj);
			}
		}
	}
	if (right == true) {
		if (east >= 0 && east < NoC) {
			cellobj = maze[east];
			if (cellobj.visited != true) {
				cellobj.from = fromCell;
				cellobj.in_structure = true;
				maze[cellobj.id] = cellobj;
				q.push(cellobj);
			}
		}
	}
	if (up == true) {
		if (north >= 0 && north < NoC) {
			cellobj = maze[north];
			if (cellobj.visited != true) {
				cellobj.from = fromCell;
				cellobj.in_structure = true;
				maze[cellobj.id] = cellobj;
				q.push(cellobj);
			}
		}
	}
	if (left == true) {
		if (west >= 0 && west < NoC) {
			cellobj = maze[west];
			if (cellobj.visited != true) {
				cellobj.from = fromCell;
				cellobj.in_structure = true;
				maze[cellobj.id] = cellobj;
				q.push(cellobj);
			}
		}
	}
}

void BFS(vector<cell>& maze, int n, int start, int end) {

	cell  cellObj;
	queue < cell > q;

	cellObj = maze[start];
	cellObj.in_structure = true;
	q.push(cellObj);

	while (!q.empty()) {

		cellObj = q.front();
		cellObj.visited = true;
		q.pop();
		maze[cellObj.id] = cellObj;
		bfsSelectNeighbour(maze, q, cellObj, n);
	}
	
}

void pritnOutput(vector<cell>& maze, int NoC, int start, int end) {
	
	int x = end;
	vector<int> path;
	path.push_back(maze[end].id);
	while (maze[x].from != maze[start].from  ) { 
		x = maze[x].from;
		path.push_back(x);
	}
	path.push_back(maze[start].from);
	std::reverse(path.begin(), path.end());
	
	for (auto a : path) {
		if (a == path.back()) {
			cout << a;
			break;
		}
		cout << a << " " << "-->" << " ";
	}

	display(path, NoC, start, end);
}

void display(std::vector<int> vec, int NoC, int start, int end)
{
	sort(vec.begin(), vec.end());
	int c = sqrt(NoC);
	std::cout << "\n";
	int k = 0;
	int countLine = 0;
	for (int i = 0; i < NoC; i++)
	{
		countLine++;
		if (countLine % c == 1)
		{
			std::cout << "\n";
			for (int i = 0; i < c * 7; i++)
				std::cout << "=";
			std::cout << "\n";
		}


		if (k < vec.size() && vec[k] == i)
		{
			if (i == end)
			{
				std::cout << "(end)" << "||";
				k++;
			}
			else if (i == start)
			{
				std::cout << "(sta)" << "||";
				k++;
			}
			else
			{
				std::cout << "  @  " << "||";
				k++;
			}
		}
		else
			std::cout << "  -  " << "||";

	}
	std::cout << "\n\n";
}

int main() {

	std::ifstream in("maze.txt");
	int NoC;
	in >> NoC;
	int start, end;
	in >> start >> end;

	int D;
	D = std::sqrt(NoC);

	std::vector<cell> RoutingTable(NoC);
	std::vector<cell> bfsRoutingTable(NoC);

	setUp(start, NoC, D, in, RoutingTable);
	bfsRoutingTable = RoutingTable;
	DFS(RoutingTable, NoC, start, end);
	BFS(bfsRoutingTable, NoC, start, end);
	cout << "Below is the output of Depth Firts Search approach in maze:" << endl;
	pritnOutput(RoutingTable, NoC, start, end);
	cout << endl;
	cout << "Below is the output of Breath Firts Search approach in maze:" << endl;
	pritnOutput(bfsRoutingTable, NoC, start, end);

	char chh;
	chh = getchar();
	chh = getchar();
	return 0;
}