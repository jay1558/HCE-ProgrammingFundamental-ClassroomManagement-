#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Student.h"
#include <vector>
#include <string>
using namespace std;

class Classroom {
private:
    vector<Student*> students;

public:
    ~Classroom();

    void addStudent(Student* s);
    void removeStudent(string id);  
    void inputMidtermGrade();
    void inputFinalGrade();             
    void displayAll();
    void markAttendance(vector<string> presentIds);                         
    void saveToFile(string filename);
    void loadFromFile(string filename);
};

#endif
