#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>


using namespace std;

int main() {
    //1.feladat

    cout << "1. feladat" << endl;
    vector<string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };

    string whatToFind = "straw";

    auto result1 = find_if(fruits.begin(), fruits.end(), [&whatToFind](const string &f) {
        return !f.find(whatToFind);
    });

    cout << *result1 << endl;

    vector<int> numbers = {1, 2, 3, 4, 5};


//    generate(numbers.begin(), numbers.end(), [n = 0]() mutable {
//        return n = n + 2;
//    });

    cout << endl;
    auto result2 = all_of(numbers.begin(), numbers.end(), [](const int &e) {
        return e % 2 == 0;
    });

    //2.feladat
    cout << "Numbers: ";
    for_each(numbers.begin(), numbers.end(), [](const int &e) {
        cout << e << " ";
    });

    cout << endl << "2.feladat" << endl;
    cout << (result2 ? "Mind paros" : "Nem mind paros") << endl << endl;

    //3.feladat
    cout << "3.feladat" << endl;
    for_each(numbers.begin(), numbers.end(), [](int &e) {
        e += e;
    });
    for_each(numbers.begin(), numbers.end(), [](const int &e) {
        cout << e << " ";
    });
    cout << endl << endl;

    //4.feladat
    cout << "4.feladat" << endl;

    vector<string> months{
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    int result4 = count_if(months.begin(), months.end(), [](const string &e) {
        return e.length() == 5;
    });

    cout << result4 << endl << endl;

    //5.feladat
    cout << "5.feladat" << endl;

    sort(numbers.begin(), numbers.end(), greater<int>());
    for_each(numbers.begin(), numbers.end(), [](const int &e) {
        cout << e << " ";
    });
    cout << endl;

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });
    for_each(numbers.begin(), numbers.end(), [](const int &e) {
        cout << e << " ";
    });
    cout << endl << endl;

    //6.feladat
    cout << "6.feladat" << endl;
    vector<pair<string, double> > monthsWithTemp = {make_pair("January", -1), make_pair("February", 1),
                                                    make_pair("March", 5), make_pair("April", 9), make_pair("May", 15),
                                                    make_pair("November", 4), make_pair("December", -2)
    };
    sort(monthsWithTemp.begin(), monthsWithTemp.end(),
         [](const pair<string, double> &pair1, const pair<string, double> &pair2) {
             return pair1.second < pair2.second;
         });
    for_each(monthsWithTemp.begin(), monthsWithTemp.end(), [](const pair<string, double> &pair) {
        cout << pair.first << ":" << pair.second << " ";
    });

    cout << endl << endl;
    //7.feladat

    cout << "7.feladat" << endl;
    vector<double> numbers2 {-5, -6, -12, 5, 8, 10, -25, -46, 120};
    sort(numbers2.begin(), numbers2.end(), [](double a, double b){
        return abs(a) < abs(b);
    });
    for_each(numbers2.begin(), numbers2.end(), [](const double &e) {
        cout << e << " ";
    });

    return 0;
}