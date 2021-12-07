#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int task1 () {
    vector <int> marks;
    vector < vector < vector<int> > > boards;

    ifstream input;
    input.open("../d2_input");

    list<char>bytes;

    if (input.is_open()) {
        string number;
        while(getline(input, number, ',')) {
            marks.emplace_back(stoi(number));
        }
        input.close();
        input.open("../d2_input");
        char byte;
        //char prev_byte = '\n';
        while (input.get(byte)) {
            bytes.emplace_back(byte);
        }

    }
    else cerr << "UNABLE TO OPEN\n";
    input.close();

    int nn_ctr = 0;
    char byte;
    char next_byte = '\0';
    string value = "";

    for (auto it = bytes.begin(); it != bytes.end();) {
        if (*it == '\r') {
            it = bytes.erase(it);
        }
        else it++;
    }

    while (byte != '\n' and next_byte != '\n') {
        byte = bytes.front();
        next_byte = *next(bytes.begin());
        bytes.pop_front();
        bytes.pop_front();
        bytes.pop_front();
    }

    for (auto it = bytes.begin(); it != bytes.end();) {
        if (*it == ' ' and *next(it) == ' ') {
            *next(it) = '0';
        }
        else if (*it == '\n' and *next(it) == ' ') {
            *next(it) = '0';
        }
        else it++;
    }

    for (auto it = bytes.begin(); it != bytes.end();) {
        if (*it == ' ' or *it == '\n') {
            it = bytes.erase(it);
        }
        else it++;
    }

    int i = 0, j = 0, valCtr = 1;
    vector < vector<int> > board;
    vector <int> line;
    string value_on_board = "";
    for (auto &byte : bytes) {
        value_on_board += byte;
        if (valCtr == 2) {
            //add VALUE TO BOARD
            line.emplace_back(stoi(value_on_board));
            j++;
            if (j == 5) {
                j = 0;
                board.emplace_back(line);
                line.clear();
                i++;
                if (i == 5) {
                    i = 0;
                    boards.emplace_back(board);
                    board.clear();
                }
            }
            value_on_board = "";
            valCtr = 0;
        }
        valCtr++;

    }
    ///THE_GAME

    int answer;
    return answer;
}




int main() {
    cout << task1() << endl;
    return 0;
}