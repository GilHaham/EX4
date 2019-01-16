//
// Created by meir on 07/01/19.
//

#ifndef MATRIX_PROBLEM_H
#define MATRIX_PROBLEM_H

#include "Searchable.h"
#include <algorithm>
#include "State.h"

typedef pair<int, int> Point;

Point add(Point p1, Point p2);

//double distance(Point currentNode, Point nextNode);


class MatrixProblem : public Searchable<pair<int, int>> {
    using Point = std::pair<int, int>;
private:
    vector<vector<double>> matrix;
    Point initialPoint;
    Point goalPoint;
    State<Point> initialState;
public:

    double at(Point p) {
        return matrix[p.first][p.second]; //return the Value at the i,j
    }
    // inserting the matrix the vector of vector of states.


    /**
     *  the constructor.
     *
     * @param search point
     * @param initialState point
     * @param goalState point
     */
    MatrixProblem( vector<vector<double>> &search, Point initialPoint, Point goalPoint)
            : initialState(initialPoint, search[initialPoint.first][initialPoint.second]) {
        this->goalPoint = goalPoint; //ignore warnings
        this->initialPoint = initialPoint; //ignore warnings
        this->matrix = search;
    }





    Point getGoalNode() override {
        return this->goalPoint;
    }

    State<Point> getInitialState() override {
        return this->initialState;
    }

    Point getInitialNode() override {
        return initialPoint;
    }

    // getting all possible states.
    vector<State<Point>> getPossibleStates(State<Point> state) override {
        vector<State<Point>> output;
        list<pair<int, int>> neighbors = {{0,  1},
                                          {1,  0},
                                          {-1, 0},
                                          {0,  -1}};
        for (const auto &offset : neighbors) {
            Point possible_point = add(state.getNode(), offset);
            if (isIndexInMatrixBounds(possible_point)) {
                output.emplace_back(possible_point, at(possible_point) + state.getCost(), new State<Point>(state));
            }
        }

        return output;
    }

    bool isIndexInMatrixBounds(pair<int, int> point) const override {
        unsigned long max_height = matrix.size();   //get the row's size.
        unsigned long max_width = matrix[0].size(); //get the col's size.
//        if(point.first<=max_height && point.second<= max_width)
        return (point.first < max_height && point.second < max_width
                && point.first >= 0 && point.second >= 0);
    }

    // getting the path solutions.
    string getPathSolution(vector<Point> pathPoints) override {
        string thePath = "{";
        Point state;
        Point next;
        for (int j = 0; j < pathPoints.size() - 1; j++) {
            state = pathPoints[j];
            next = pathPoints[j + 1];
            int rowNext = next.first;
            int colNext = next.second;
            int row = state.first;
            int col = state.second;



            if ((colNext == col) && (rowNext == row - 1)) {
                thePath = "Down, " + thePath;
            } else if ((colNext == col) && (rowNext == row + 1)) {
                thePath = "Up, " + thePath;
            } else if ((rowNext == row) && (colNext == col + 1)) {
                thePath = "Left, " + thePath;
            } else if ((rowNext == row) && (colNext == col - 1)) {
                thePath = "Right, " + thePath;
            }
        }

        thePath.erase(thePath.size() - 3);
        thePath += "}";
        return thePath;
    }


};

#endif /* MATRIX_PROBLEM_H */