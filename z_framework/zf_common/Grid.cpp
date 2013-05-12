#include "Grid.hpp"

Grid::Grid()
{
    this->row = 0;
    this->col = 0;
}

Grid::Grid(int row, int col)
{
    this->row = row;
    this->col = col;
}

Grid::~Grid()
{
}

bool operator==(const Grid &lhs, const Grid &rhs)
{
    if(lhs.row == rhs.row && lhs.col == rhs.col)
    {
        return true;
    }    
    return false;
}

bool operator!=(const Grid &lhs, const Grid &rhs)
{
    return !(operator==(lhs,rhs));
}


Grid& Grid::operator+=(const Grid& rhs)
{
    this->row += rhs.row;
    this->col += rhs.col;
    return *this;
}

Grid& Grid::operator-=(const Grid& rhs)
{
    this->row -= rhs.row;
    this->col -= rhs.col;
    return *this;
}

Grid operator+(Grid lhs, const Grid &rhs)
{
    return lhs += rhs;
}

Grid operator-(Grid lhs, const Grid &rhs)
{
    return lhs -= rhs;
}

