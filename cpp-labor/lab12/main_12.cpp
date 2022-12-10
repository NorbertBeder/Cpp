#include <set>

#include <algorithm>
#include "GraduationDaoImpl.h"
#include "GraduationServiceImpl.h"
#include "SettlementStatistics.h"
#include "SettlementStatisticsImpl.h"


string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

int main() {
    // ADMIN
    int feladat;
    cout << "Students (1) or Settlements (2):";
    cin >> feladat;
    switch (feladat) {
        case 1: {
            GraduationDao *dao = new GraduationDaoImpl();
            dao->enrollStudents("names.txt");
            cout << "Number of enrolled students: " << dao->numEnrolled() << endl;

            for (int i = 0; i < numSubjects; ++i) {
                dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
            }
            dao->computeAverage();

            cout << "Subject's averages: " << endl;
            try {
                for (int i = 0; i < numSubjects; ++i) {
                    cout << "\taverage(" << subjects[i] << "): " << dao->getAverageBySubject(subjects[i]) << endl;
                }
            } catch (domain_error &e) {
                cerr << e.what() << endl;
            }

            GraduationService *service = new GraduationServiceImpl(dao);

            cout << "Individual results: " << endl;
            int id = 0;
            while (id != -1) {
                cout << "Enter ID (-1 for EXIT):";
                cin >> id;
                if (id == -1) {
                    break;
                }
                cout << "Student id = " << id << " results:" << endl;
                try {
                    auto results = service->findById(id);
                    for_each(results.getGrades().begin(), results.getGrades().end(), [](const pair<string, double> &e) {
                        cout << "\t" << e.first << " : " << e.second << endl;
                    });
                } catch (out_of_range &e) {
                    cerr << "Nem letezo ID " << e.what() << endl;
                }
            }

            id = 0;
            string subject;
            while (id != -1) {
                cout << "Enter ID and subject (-1 for EXIT):";
                cin >> id;
                if (id == -1) {
                    break;
                }
                cin >> subject;
                cout << "Student id = " << id << " " << subject << " result: ";
                try {
                    auto result = service->getResultByIdAndSubject(id, subject);
                    cout << result << endl;
                } catch (out_of_range &e) {
                    cerr << "Nem letezo ID " << e.what() << endl;
                }
            }

            delete service;
            delete dao;
            break;
        }
        case 2:
        {
            SettlementStatistics *statistics = new SettlementStatisticsImpl("telepulesek.csv");

            cout << "Number of settlements: " << statistics->numSettlements() << endl << endl;

            cout << "Number of counties: " << statistics->numCounties() << endl << endl;

            cout << "Number of settlements by county : " << statistics->numSettlementsByCounty("CV") << endl << endl;

            string name, county;
            cout << "Enter name and county:";
            getline(cin >> ws, name);
            cin >> county;

            cout << "Find settlements by name and county: " << statistics->findSettlementsByNameAndCounty(name, county) << endl;

            cout << endl << "Settlements in CV: " << endl;
            vector<Settlement> result = statistics->findSettlementsByCounty("CV");
            for(auto & r : result) {
                cout << r << ", ";
            }
            cout << endl;

            cout << endl << "Settlements with the name Padureni: " << endl;
            vector<Settlement> result2 = statistics->findSettlementsByName("Padureni");
            for(auto & r : result2) {
                cout << r << ", ";
            }
            cout << endl;
            delete statistics;
            break;
        }
        default:
        {
            cout << "Not valid.";
            break;
        }
    }


    return 0;
}