//
// Created by beder on 2022. 12. 07..
//

#include "GraduationServiceImpl.h"

Student GraduationServiceImpl::findById(int id) const {
    return dao->findById(id);
}

double GraduationServiceImpl::getResultByIdAndSubject(int id, const string &subject) const {
    return 0;
}

GraduationServiceImpl::GraduationServiceImpl(GraduationDao *dao) : dao(dao) {};