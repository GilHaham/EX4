//
// Created by meir on 10/01/19.
//

#include "DataBase.h"


vector<string> DataBase:: fileToVector(string str, char delimiter){
    string temp = "";
    vector<string> result;
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it != delimiter) {
            temp += *it;
        } else {
            result.push_back(temp);
            temp = "";
        }
    }
    result.push_back(temp);
    return result;
}