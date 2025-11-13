#include "Student.h"
#include <iostream>
using namespace std;


Student::Student() : id(""), name(""), midterm(0), finalScore(0), attendanceCount(0), absenceCount(0) {}

Student::Student(string id, string name) : id(id), name(name), midterm(0), finalScore(0), attendanceCount(0), absenceCount(0) {}


void Student::input() {
    cout << "Enter ID: "; cin >> id;
    cin.ignore(); // bỏ newline
    cout << "Enter name: "; getline(cin, name);
    cout << "Enter midterm score: "; cin >> midterm;
    cout << "Enter final score: "; cin >> finalScore;
}

void Student::inputMidtermGrade(float score) {
    midterm = score;
}
 
void Student::inputFinalGrade(float score) {
    finalScore = score;
}

void Student::display() {
    cout << id << " | " << name << " | GPA: " << calculateGPA() 
         << " | Attendance: " << attendanceCount << "/" << (attendanceCount+absenceCount) << endl;
}

void Student::updateAttendance(bool present) {
    if (present) attendanceCount++;
    else absenceCount++;
}

float Student::calculateGPA() {
    return midterm * 0.4 + finalScore * 0.6;
}

string Student::getId() { return id; }

string Student::getName() { return name; }

int Student::getAttendance() { return attendanceCount; }
