#ifndef STUDENT_H
#define STUDENT_H

#include <string> 
using namespace std;

class Student {
private:
    string id;
    string name;
    float midterm;
    float finalScore;
    int attendanceCount;
    int absenceCount;

public:
    Student();
    Student(string id, string name);

    void input();
    void inputMidtermGrade(float score);
    void inputFinalGrade(float score);
    void display();
    void updateAttendance(bool present);
    float calculateGPA();         
    string getId();
    string getName();             
    int getAttendance();          
};

#endif
