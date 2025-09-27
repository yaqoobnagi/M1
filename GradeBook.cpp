#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 50;
const int TESTS = 5;

// Functions
int loadData(string names[], int scores[][TESTS]);
void calcAverages(int scores[][TESTS], double avgs[], int count);
char getGrade(double avg);
void showReport(string names[], double avgs[], int count);

int main() {
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS][TESTS];
    double avgs[MAX_STUDENTS];
    int count;

    ifstream file("StudentGrades.txt");
    if (!file) {
        cout << "File not found.\n";
        return 1;
    }

    count = loadData(names, scores);
    file.close();

    calcAverages(scores, avgs, count);
    showReport(names, avgs, count);

    return 0;
}

int loadData(string names[], int scores[][TESTS]) {
    ifstream file("StudentGrades.txt");
    int n = 0;
    while (file >> names[n]) {
        for (int i = 0; i < TESTS; i++) {
            file >> scores[n][i];
        }
        n++;
    }
    return n;
}

void calcAverages(int scores[][TESTS], double avgs[], int count) {
    for (int i = 0; i < count; i++) {
        int sum = 0;
        for (int j = 0; j < TESTS; j++) {
            sum += scores[i][j];
        }
        avgs[i] = sum / (double)TESTS;
    }
}

char getGrade(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

void showReport(string names[], double avgs[], int count) {
    cout << left << setw(12) << "Name" 
         << setw(10) << "Average" 
         << setw(6) << "Grade" << endl;
    cout << "--------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << left << setw(12) << names[i]
             << setw(10) << fixed << setprecision(1) << avgs[i]
             << setw(6) << getGrade(avgs[i]) << endl;
    }
}
