////
//// Created by meir on 09/01/19.
////
//
//#ifndef EX4_MATRIX_H
//#define EX4_MATRIX_H
//
//
//#include <queue>
//#include "ISearchable.h"
//#include "Point.h"
//
//using namespace std;
//
//
//template <class T>
//class MatrixProblem: public ISearchable<T> {
//
//private:
//    vector<vector<int>> matrix;
//    int matrixSize;
//    State<T> initState;
//    State<T> goalState;
//
//public:
//
///*
//
//template<class T>
//State<vector<int>> MatrixProblem<T>::getInitialState() {
//    return this->initState;
//}
//
//template<class T>
//State<vector<int>> MatrixProblem<T>::getGoalState() {
//    return this->goalState;
//
//}
//
//template<class T>
//std::vector<State<Point>> MatrixProblem<T>::getAllPossibleStates(State<Point> state) {
//
//    //#>~?>@?~!>$>@#$>#%?$^%>$&>&^>%
////    return std::vector<State<T>>();
//}
//
//template<class T>
//bool MatrixProblem<T>::isGoal(State<T> state) {
//    return false;
//}
// * */
//
//    MatrixProblem( vector<vector<int>> &matrix, int matrixSize, State<T> &initState,
//                   State<T> &goalState) : matrix(matrix), matrixSize(matrixSize), initState(initState),
//                                               goalState(goalState) {}
//
//    State<Point> getInitialState() override{
//        return this->initState;
//    }
//
//    State<Point> getGoalState() override{
//        return this->goalState;
//    }
//
//    std::vector<State<Point*>> getAllPossibleStates(State<Point*> state) override{
//        vector<State<Point*>> statesQueue;
//        int row = state.getState()->getRow();
//        int col = state.getState()->getCol();
//        int n =this->matrixSize;
//        int upRow=0, downRow=n-1, leftCol=0, rightCol=n-1;
//
//        if(row<downRow ){ //we can move down
//            if (col <= rightCol){//can move left
//                if (col!=leftCol){
////                    Point* point = new Point(row,col-1);
//                    Point *p = new Point(row, col-1);
//
//                    State<Point> point2 = new State<Point>(p);
//                    statesQueue.push_back(point); //insert left state
//                }
//            }
//
//        }
//    }
//
//    bool isGoal(State<T> state) override;
//
//};
//
//
//#endif //EX4_MATRIX_H
