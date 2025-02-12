#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_TESTS = 10;

void readData(ifstream& file, string names[], double scores[][MAX_TESTS], int& numStudents, int& numTests);
void calculateAverages(double scores[][MAX_TESTS], double averages[], int numStudents, int numTests);
char getLetterGrade(double average);
void printReport(const string names[], const double averages[], int numStudents);

int main() {
    string names[MAX_STUDENTS];
    double scores[MAX_STUDENTS][MAX_TESTS];
    double averages[MAX_STUDENTS];
    int numStudents = 0, numTests = 0;

    ifstream inputFile("grades.txt");
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    readData(inputFile, names, scores, numStudents, numTests);
    inputFile.close();

    calculateAverages(scores, averages, numStudents, numTests);
    printReport(names, averages, numStudents);

    return 0;
}

void readData(ifstream& file, string names[], double scores[][MAX_TESTS], int& numStudents, int& numTests) {
    numStudents = 0;
    while (file >> names[numStudents]) {
        for (numTests = 0; file.peek() != '\n' && file >> scores[numStudents][numTests]; numTests++);
        numStudents++;
    }
}

void calculateAverages(double scores[][MAX_TESTS], double averages[], int numStudents, int numTests) {
    for (int i = 0; i < numStudents; i++) {
        double sum = 0;
        for (int j = 0; j < numTests; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / numTests;
    }
}

char getLetterGrade(double average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    return 'F';
}

void printReport(const string names[], const double averages[], int numStudents) {
    cout << left << setw(15) << "Student Name" << setw(10) << "Average" << "Grade" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(15) << names[i]
            << setw(10) << fixed << setprecision(2) << averages[i]
            << getLetterGrade(averages[i]) << endl;
    }
}
