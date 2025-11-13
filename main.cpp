#include "Classroom.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Classroom cls;
    cls.loadFromFile("students.txt");

    int choice;
    do {
        cout << "\n==== HCE Smart Class Manager ====\n";
        cout << "1. Add student\n";
        cout << "2. Display students\n";
        cout << "3. Mark attendance\n";
        cout << "4. Input miterm grades\n";
        cout << "5. Input final grades\n";
        cout << "6. Save to file\n";
        cout << "7. Remove student\n";
        cout << "0. Exit\n";
        cout << "Choose: "; cin >> choice;
        cin.ignore();

        if(choice==1){
            Student* s = new Student();
            s->input();
            cls.addStudent(s);
        } 
        else if(choice==2){
            cls.displayAll();
        } 
        else if(choice==3){
            vector<string> presentIds;
            string id;
            cout << "Enter present IDs (type 0 to end): ";
            while(cin >> id && id!="0") presentIds.push_back(id);
            cls.markAttendance(presentIds);
        } 
        else if(choice==4){
            cls.inputMidtermGrade();
        } else if (choice==5) {
            cls.inputFinalGrade();
        }
        else if(choice==6){
            cls.saveToFile("students.txt");
            cout << "Saved successfully!\n";
        } else if (choice==7){
            string id;
            cout << "Enter student ID to remove: ";
            cin >> id;
            cls.removeStudent(id);
            cout << "Student removed if ID existed.\n";
        }

    } while(choice!=0);

    return 0;
}
