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

double distance(Point p1, Point p2);


class MatrixProblem : public Searchable<pair<int, int>> {
    using Point = std::pair<int, int>;
private:
    vector<vector<double>> search;
    Point initialPoint;
    Point goalPoint;
    State<Point> initialState;
public:

    double at(Point p) {
        return search[p.first][p.second]; //return the Value at the i,j
    }
    // inserting the matrix the vector of vector of states.
    /**
     *  the constructor.
     *
     * @param search point
     * @param initialState point
     * @param goalState point
     */
    MatrixProblem(const vector<vector<double>> &search, Point initialPoint, Point goalPoint)
            : initialState(initialPoint, search[initialPoint.first][initialPoint.second]) {
        this->goalPoint = goalPoint;
        this->initialPoint = initialPoint;
        this->search = search;
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
        unsigned long max_height = search.size();   //get the row's size.
        unsigned long max_width = search[0].size(); //get the col's size.
//        if(point.first<=max_height && point.second<= max_width)
        return (point.first < max_height && point.second < max_width
                && point.first >= 0 && point.second >= 0);
    }

    // getting the path solutions.
    string getPathSolution(vector<State<Point> *> pathPoints) {
        string thePath = "{";
        State<Point> *state;
        State<Point> *next;
        for (int j = 0; j < pathPoints.size() - 1; j++) {
            state = pathPoints[j];
            next = pathPoints[j + 1];
            int rowNext = next->getNode().first;
            int colNext = next->getNode().second;
            int row = state->getNode().first;
            int col = state->getNode().second;


            if ((colNext == col) && (rowNext == row - 1)) {
                thePath += "Up, ";
            } else if ((colNext == col) && (rowNext == row + 1)) {
                thePath += "Down, ";
            } else if ((rowNext == row) && (colNext == col + 1)) {
                thePath += "Right, ";
            } else if ((rowNext == row) && (colNext == col - 1)) {
                thePath += "Left, ";
            }
        }

        thePath.erase(thePath.size() - 2);
        thePath += "}";
        return thePath;
    }


};

#endif /* MATRIX_PROBLEM_H */