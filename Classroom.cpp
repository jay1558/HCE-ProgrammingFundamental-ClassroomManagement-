#include "Classroom.h"
#include <iostream>
#include <fstream>
using namespace std;

// Destructor: giải phóng memory
Classroom::~Classroom() {
    for(auto s : students) delete s;
}

void Classroom::addStudent(Student* s) {
    students.push_back(s);
}

void Classroom::removeStudent(string id) {
    for(int i=0; i<students.size(); i++){
        if(students[i]->getId() == id){
            delete students[i];
            students.erase(students.begin()+i);
            break;
        }
    }
}

void Classroom::displayAll() {
    cout << "ID | Name | GPA | Attendance" << endl;
    for(auto s : students) s->display();
}

void Classroom::markAttendance(vector<string> presentIds) {
    for(auto s : students) {
        bool present = false;
        for(auto id : presentIds){
            if(s->getId() == id) { present = true; break; }
        }
        s->updateAttendance(present);
    }
}

void Classroom::inputMidtermGrade() {
    for(Student* s : students) {
        float score;
        cout << "Enter grades for " << s->getName() << endl;
        cin >> score;
        s->inputMidtermGrade(score);
    }
}

void Classroom::inputFinalGrade() {
    for(auto s : students) {
        float score;
        cout << "Enter grades for " << s->getName() << endl;
        cin >> score;
        s->inputFinalGrade(score);
    }
}

void Classroom::saveToFile(string filename) {
    ofstream fout(filename);
    for(Student* s : students){
        fout << s->getId() << "," << s->getName() << "," << s->calculateGPA() 
             << "," << s->getAttendance() << endl;
    }
    fout.close();
}

void Classroom::loadFromFile(string filename) {
    ifstream fin(filename);
    string line;
    while(getline(fin, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');
        string id = line.substr(0, pos1);
        string name = line.substr(pos1+1, pos2-pos1-1);
        Student* s = new Student(id, name);
        students.push_back(s);
    }
    fin.close();
}
