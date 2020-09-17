# The Maze
The objective of this project is to implement BFS (Breadth Frist Search) and DFS (Depth First Search) algorithms to solve the Maze.

### Rules for building The Maze :
Program will read a .txt file, which is named maze.txt.

maze.txt file contains the blueprint/format of the maze as follows:

- Numbers of cells
- Starting cell
- Target Cell
- Cell walls...

The Maze is developed by reading from a text file. 
The cells in the maze are developed on the follwoing rules:
- 8 - Left
- 4- Up
- 2- Right
- 1 - Down
//image from ipad for cell blueprint and input file reading


###  Code Functions
The Two main function for Breath First Search and Depth First search are mentioned below. 
Where start is the beging of the maze and end is the end or target cell in the maze.
```
void DFS(vector<cell>& maze, int n, int start, int end);
void BFS(vector<cell>& maze, int n, int start, int end);
```

### Final Output
Below are the output of each approach. As we can see, both algorithm gives different output for same maze.
![BFS Image](https://github.com/bhattidhruv/The_Maze/blob/master/BFS_Image.png)
Above image is output for Breadth First Search (BFS). We can see the path followed with "@" for solving maze.

![DFS Image](https://github.com/bhattidhruv/The_Maze/blob/master/Maze%20DFS%20Path.JPG)
Above image is output for Depth First Search (DFS). We can see the path followed with "@" for solving maze.
