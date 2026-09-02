//============================================================================
// Name        : CMPE50-Lab-6.1.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class StudentRecord {
private:
    int quiz[3];
    int mid;
    int final;
    double average;
public:
    StudentRecord() {
        quiz[0] = quiz[1] = quiz[2] = 0;
        mid = 0;
        final = 0;
        average = 0;
    };
    void setQuize(int a, int b, int c) {
        if (a >= b && a >= c) {
            quiz[0] = a;
            if (b > c) {
                quiz[1] = b;
                quiz[2] = c;
            }
            else {
                quiz[1] = c;
                quiz[2] = b;
            }
        }
        else if (b >= a && b >= c) {
            quiz[0] = b;
            if (a > c) {
                quiz[1] = a;
                quiz[2] = c;
            }
            else {
                quiz[1] = c;
                quiz[2] = a;
            }
        }
        else if (c >= a && c >= b) {
            quiz[0] = c;
            if (b > a) {
                quiz[1] = b;
                quiz[2] = a;
            }
            else {
                quiz[1] = a;
                quiz[2] = b;
            }
        }
    }

    void setmid(int score) {
        mid = score;
    }
    void setFinal(int score) {
        final = score;
    }

    int getQuize1() {
        return quiz[0];
    }

    int getQuize2() {
        return quiz[1];
    }

    int getQuize3() {
        return quiz[2];
    }

    int getmid() {
        return mid;
    }

    int getFinal() {
        return final;
    }

    double getAverage() {
        return average;
    }

    void calculate() {
        average = ((((quiz[0] + quiz[1]) / 20.00) * 0.25) + ((mid / 100.00) * 0.25) + ((final / 100.00) * 0.5)) * 100.00;
    }
};


int main() {
    cout << "Enter 3 quizzes score: ";
    int quize1, quize2, quize3;
    cin >> quize1 >> quize2 >> quize3;
    cout << "Enter mid score: ";
    int mid;
    cin >> mid;
    cout << "Enter final score: ";
    int final;
    cin >> final;

    StudentRecord SR = StudentRecord();

    SR.setQuize(quize1, quize2, quize3);
    SR.setmid(mid);
    SR.setFinal(final);
    SR.calculate();

    cout << "Best 2 quizzes scores: " << SR.getQuize1() << ", " << SR.getQuize2() << endl;
    cout << "Midterm scores: " << SR.getmid() << endl;
    cout << "Final scores: " << SR.getFinal() << endl;
    cout << "Average score: " << SR.getAverage() << endl;
}

/*
 * Enter 3 quizzes score: 90 89 99
 * Enter mid score: 90
 * Enter final score: 99
 * Best 2 quizzes scores: 99 90
 * Midterm scores: 90
 * Final scores: 99
 * Average score: 308.25
 */
