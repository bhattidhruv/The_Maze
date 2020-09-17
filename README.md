# The Maze
The objective of this project is to implement BFS (Breadth Frist Search) and DFS (Depth First Search) algorithms to solve the Maze.

### Rules for building The Maze :
The program will read a .txt file, which is named maze.txt <br/>
maze.txt file contains the blueprint/format of the maze as follows:

- Numbers of cells
- Starting cell
- Target Cell
- Cell walls...

The Maze is developed by reading from a text file. 
The cells in the maze are developed on the following rules:
- 8 - Left
- 4- Up
- 2- Right
- 1 - Down
//image from ipad for cell blueprint and input file reading


###  Code Functions
The Two main functions for Breadth-First Search and Depth First search are mentioned below. Where the start is the beginning of the maze and the end is the end or target cell in the maze.
```
void DFS(vector<cell>& maze, int n, int start, int end);
void BFS(vector<cell>& maze, int n, int start, int end);
```

### Final Output
Below is the output of each approach. As we can see, both algorithm gives a different output for the same maze.

![BFS Image](https://github.com/bhattidhruv/The_Maze/blob/master/BFS_Image.png)
The above image is output for Breadth-First Search (BFS). We can see the path followed by "@" for solving the maze.

![DFS Image](https://github.com/bhattidhruv/The_Maze/blob/master/Maze%20DFS%20Path.JPG)
The above image is output for Depth First Search (DFS). We can see the path followed by "@" for solving the maze.
