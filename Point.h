//
// Created by meir on 09/01/19.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H


class Point {

private:
    int row;
    int col;

public:
    Point(int newRow, int newCol) : row(newRow), col(newCol) {}

    int getRow(){
        return this->row;
    }
    int getCol(){
        return this->col;
    }
    void setRow(int currentRow){
        row = currentRow;
    }
    void setCol(int currentCol){
        col = currentCol;
    }

    bool operator==(Point point) {
        return ((this->row == point.getRow()) && (this->col == point.getCol()));
    }

    void setPoint(int col, int row) {
        this->col = col;
        this->row = row;
    }

};


#endif //EX4_POINT_H
