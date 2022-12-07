//
// Created by beder on 2022. 12. 07..
//

#ifndef CPP_2022_GRADUATIONSERVICE_H
#define CPP_2022_GRADUATIONSERVICE_H

class GraduationService {
public:
    virtual Student findById(int id) const = 0;

    virtual double getResultByIdAndSubject(int id, const string &subject) const = 0;
};

#endif //CPP_2022_GRADUATIONSERVICE_H
