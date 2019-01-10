//
// Created by meir on 10/01/19.
//

#include <bits/stdc++.h>
#include <algorithm>
#include "StringReverser.h"

/**
 * return a reversed string.
 * @param input .
 * @return input reversed
 */
string StringReverser::solve(string input) {
    string temp;
    for (string::iterator it = input.begin(); it != input.end(); ++it) {
        if (*it == '\n' || *it == '\r' || *it == '\0') {
            continue;
        }
        temp += *it;
    }
    string answer = temp;
    reverse(answer.begin(), answer.end());
    return answer;
}