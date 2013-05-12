#ifndef _ZF_FRAMEWORK_GRID_H_
#define _ZF_FRAMEWORK_GRID_H_
struct Grid
{
    int row;
    int col;
    Grid();
    Grid(int row, int col);
    ~Grid();


    static Grid toGrid(int x, int y, int gridSize, int gridSpacing)
    {
        Grid g;
        g.col = x / (gridSize + gridSpacing);
        g.row = y / (gridSize + gridSpacing);
        return g;
    }

    Grid& operator+=(const Grid &rhs);
    Grid& operator-=(const Grid &rhs);
    
};

bool operator==(const Grid &lhs, const Grid &rhs);
bool operator!=(const Grid &lhs, const Grid &rhs);
Grid operator-(Grid lhs, const Grid& rhs);
Grid operator+(Grid lhs, const Grid& rhs);

#endif
