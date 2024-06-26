//
// Created by beder on 2022. 12. 07..
//

#ifndef CPP_2022_STUDENT_H
#define CPP_2022_STUDENT_H

#include <string>
#include <map>
#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:

    Student(int id, const string &firstName, const string &lastName);

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    const string &getFirstName() const {
        return firstName;
    }

    void setFirstName(const string &firstName) {
        this->firstName = firstName;
    }

    const string &getLastName() const {
        return lastName;
    }

    void setLastName(const string &lastName) {
        this->lastName = lastName;
    }

    void addGrade(const string& subject, double grade){
        this->grades[subject] = grade;
    }

//    throws out_of_range exception for nonexistent subject
    double getGrade(const string& subject){
        return this->grades[subject];
    }

    const map<string, double> &getGrades() const;

    void computeAverage();

    double getAverage() const {
        return average;
    }
    friend ostream& operator<<(ostream& os, const Student& student);
};

#endif //CPP_2022_STUDENT_H
