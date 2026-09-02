//============================================================================
// Name        : CMPE50-Lab-8.1.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

class SeatMgr
{
public:
    SeatMgr(int size);
    void display(ostream& out);
    bool check_seat(const char seat[]);
    bool check_full();
    void assign_seat(const char seat[]);
    ~SeatMgr();
private:
    int rowSize;
    char** seats;
    int digit_to_row(char d);
    int digit_to_column(char d);
};

void exercise_1();
void auto_test();

int main()
{
    auto_test();
    return 0;
}

void auto_test()
{
    cout << "Input from the console or an input file? (1 for console, 2 for file)\n";
    int n;
    cin >> n;
    if (n == 1) {
        exercise_1();
    } else {
        cout << "Please input file name:\n";
        string file_name;
        cin >> file_name;

        ifstream fin(file_name.c_str());
        if (fin.fail()) {
            cout << "File open failed.\n";
            exit(1);
        }

        int rowSize;
        fin >> rowSize;
        fin.ignore(100, '\n');
        SeatMgr seat_mgr(rowSize);

        string line;
        while (true)
        {
            seat_mgr.display(cout);

            if (!getline(fin, line)) {
                cout << "Reached end of file.\n";
                break;
            }

            while (!line.empty() && isspace(line.back())) line.pop_back();
            while (!line.empty() && isspace(line.front())) line.erase(line.begin());
            if (line.empty()) continue;

            if (line[0] == 'e' || line[0] == 'E') {
                cout << "exit\n";
                break;
            }

            char seat[4] = {0};
            seat[0] = line[0];
            seat[1] = line.size() > 1 ? line[1] : '\0';

            if (seat_mgr.check_seat(seat)) {
                seat_mgr.assign_seat(seat);
                cout << line << " Seat assigned\n";
            } else {
                cout << line << " Seat not available\n";
            }

            if (seat_mgr.check_full()) {
                cout << "Seat full exit\n";
                break;
            }
        }

        fin.close();
    }
}

void exercise_1()
{
    int rowSize;
    cout << "How many rows does the plane have?\n";
    cin >> rowSize;
    cin.ignore(100, '\n');
    SeatMgr seat_mgr(rowSize);

    while (true)
    {
        seat_mgr.display(cout);
        cout << "Which seat would you like? (end to exit)\n";
        string line;
        getline(cin, line);

        if (line.empty()) continue;
        if (line[0] == 'e' || line[0] == 'E') {
            cout << "exit\n";
            break;
        }

        char seat[4] = {0};
        seat[0] = line[0];
        seat[1] = line.size() > 1 ? line[1] : '\0';

        if (seat_mgr.check_seat(seat)) {
            seat_mgr.assign_seat(seat);
            cout << "Seat assigned\n";
        } else {
            cout << "Seat not available\n";
        }

        if (seat_mgr.check_full()) {
            cout << "Seat full exit\n";
            break;
        }
    }
}

SeatMgr::SeatMgr(int size)
{
    rowSize = size;
    seats = new char*[rowSize];
    for (int i = 0; i < rowSize; i++)
    {
        seats[i] = new char[4];
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }
}

void SeatMgr::display(ostream& out)
{
    for (int i = 0; i < rowSize; i++)
    {
        out << i + 1;
        for (int j = 0; j < 4; j++)
        {
            out << " " << seats[i][j];
        }
        out << endl;
    }
}

bool SeatMgr::check_seat(const char seat[])
{
    int row = digit_to_row(seat[0]);
    if (row < 1 || row > rowSize)
        return false;

    int column = digit_to_column(seat[1]);
    if (column < 0 || column >= 4)
        return false;

    return seats[row - 1][column] != 'X';
}

bool SeatMgr::check_full()
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (seats[i][j] != 'X')
                return false;
        }
    }
    return true;
}

void SeatMgr::assign_seat(const char seat[])
{
    int row = digit_to_row(seat[0]);
    int column = digit_to_column(seat[1]);
    seats[row - 1][column] = 'X';
}

int SeatMgr::digit_to_row(char d)
{
    return d - '0';
}

int SeatMgr::digit_to_column(char d)
{
    if (d >= 'a' && d <= 'z')
        return d - 'a';
    else
        return d - 'A';
}

SeatMgr::~SeatMgr()
{
    for (int i = 0; i < rowSize; i++)
        delete[] seats[i];
    delete[] seats;
}

/*
 * Input from the console or an input file? (1 for console, 2 for file)
 * 2
 * Please input file name:
 * lab8_1-input.txt
 * 1 A B C D
 * 2 A B C D
 * 3 A B C D
 * 4 A B C D
 * 5 A B C D
 * 1A Seat assigned
 * 1 X B C D
 * 2 A B C D
 * 3 A B C D
 * 4 A B C D
 * 5 A B C D
 * 2A Seat assigned
 * 1 X B C D
 * 2 X B C D
 * 3 A B C D
 * 4 A B C D
 * 5 A B C D
 * 3A Seat assigned
 * 1 X B C D
 * 2 X B C D
 * 3 X B C D
 * 4 A B C D
 * 5 A B C D
 * 1 X B C D
 * 2 X B C D
 * 3 X B C D
 * 4 A B C D
 * 5 A B C D
 * 4b Seat assigned
 * 1 X B C D
 * 2 X B C D
 * 3 X B C D
 * 4 A X C D
 * 5 A B C D
 * 1 X B C D
 * 2 X B C D
 * 3 X B C D
 * 4 A X C D
 * 5 A B C D
 * 1b Seat assigned
 * 1 X X C D
 * 2 X B C D
 * 3 X B C D
 * 4 A X C D
 * 5 A B C D
 * 1 X X C D
 * 2 X B C D
 * 3 X B C D
 * 4 A X C D
 * 5 A B C D
 * 2C Seat assigned
 * 1 X X C D
 * 2 X B X D
 * 3 X B C D
 * 4 A X C D
 * 5 A B C D
 * 2D Seat assigned
 * 1 X X C D
 * 2 X B X X
 * 3 X B C D
 * 4 A X C D
 * 5 A B C D
 * 1 X X C D
 * 2 X B X X
 * 3 X B C D
 * 4 A X C D
 * 5 A B C D
 * 3c Seat assigned
 * 1 X X C D
 * 2 X B X X
 * 3 X B X D
 * 4 A X C D
 * 5 A B C D
 * 3a Seat not available
 * 1 X X C D
 * 2 X B X X
 * 3 X B X D
 * 4 A X C D
 * 5 A B C D
 * 3f Seat not available
 * 1 X X C D
 * 2 X B X X
 * 3 X B X D
 * 4 A X C D
 * 5 A B C D
 * 3b Seat assigned
 * 1 X X C D
 * 2 X B X X
 * 3 X X X D
 * 4 A X C D
 * 5 A B C D
 * 1 X X C D
 * 2 X B X X
 * 3 X X X D
 * 4 A X C D
 * 5 A B C D
 * 2b Seat assigned
 * 1 X X C D
 * 2 X X X X
 * 3 X X X D
 * 4 A X C D
 * 5 A B C D
 * 1c Seat assigned
 * 1 X X X D
 * 2 X X X X
 * 3 X X X D
 * 4 A X C D
 * 5 A B C D
 * 1d Seat assigned
 * 1 X X X X
 * 2 X X X X
 * 3 X X X D
 * 4 A X C D
 * 5 A B C D
 * 3d Seat assigned
 * 1 X X X X
 * 2 X X X X
 * 3 X X X X
 * 4 A X C D
 * 5 A B C D
 * Reached end of file.
 *
 */
