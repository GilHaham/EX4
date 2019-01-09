#include <iostream>
#include "State.h"
//#include "SearcherAlgo"

using namespace std;
//template <class T>
int main() {
    std::cout << "Hello, World!" << std::endl;
    State<string> *a = new State<string>("A");
    State<string> *b = new State<string>("B");
    State<string> *goal = new State<string>("B");

    bool result = goal->Equals(b);
    cout<<result<<endl;

    result = goal->Equals(a);
    cout<<result<<endl;




    return 0;
}