#include <set>

#include <algorithm>
#include "GraduationDaoImpl.h"
#include "GraduationServiceImpl.h"
#include "SettlementStatistics.h"
#include "SettlementStatisticsImpl.h"


string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

int main() {
//    // ADMIN
//    GraduationDao *dao = new GraduationDaoImpl();
//    dao->enrollStudents("names.txt");
//    cout << "Number of enrolled students: " << dao->numEnrolled() << endl;
//
//    for (int i = 0; i < numSubjects; ++i) {
//        dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
//    }
//    dao->computeAverage();
//
//    cout << "Subject's averages: " << endl;
//    try {
//        for (int i = 0; i < numSubjects; ++i) {
//            cout << "\taverage(" << subjects[i] << "): " << dao->getAverageBySubject(subjects[i]) << endl;
//        }
//    }catch( domain_error& e){
//        cerr << e.what() << endl;
//    }
//
//    GraduationService *service = new GraduationServiceImpl(dao);
//
//    cout << "Individual results: " << endl;
//    int id = 0;
//    while (id != -1) {
//        cout << "Enter ID (-1 for EXIT): ";
//        cin >> id;
//        if (id == -1) {
//            break;
//        }
//        cout << "Student id=" << id << " results: " << endl;
//        try {
//            auto results = service->findById(id);
//            for_each(results.getGrades().begin(), results.getGrades().end(), [](const pair<string, double> &e) {
//                cout << "\t" << e.first << " : " << e.second << endl;
//            });
//        } catch (out_of_range &e) {
//            cerr << "Nem letezo ID " << e.what() << endl;
//        }
//    }
//
//    delete service;
//    delete dao;
    SettlementStatistics *statistics = new SettlementStatisticsImpl("telepulesek.csv");

    cout << "Number of settlements: " << statistics->numSettlements() << endl;

    cout << "Number of counties: " << statistics->numCounties() << endl;

    cout << "Number of settlements by county : " << statistics->numSettlementsByCounty("CV");



    delete statistics;
    return 0;
}