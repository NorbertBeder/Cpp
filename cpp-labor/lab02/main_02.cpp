#include "Util.h"


void test_distance();
void is_square();
void testIsSquare(const char * filename);
void testRandomPoints();
void printArray(Point* points, int numPoints);
void testClosestPoints();
void testSort();
void testFarthestPointsFromOrigin();

int main(int argc, char** argv) {
    //test_distance();
    //is_square();
    //testIsSquare("points.txt");
    //testRandomPoints();
    //testClosestPoints();
    //testSort();
    testFarthestPointsFromOrigin();
    return 0;
}

void test_distance(){
    Point p1(0, 0);
    cout << "distSq = " << distance(p1, p1) << endl;
    cout << "distSq = " << distance(p1, Point(3, 4)) << endl;
}

void is_square() {
    Point p1 = {20, 10}, p2 = {10, 20}, p3 = {20, 20}, p4 = {10, 10};

    isSquare(p1, p2, p3, p4) ? cout << "YES" : cout << "NO" << endl;
}

void testIsSquare(const char * filename){
    ifstream ifs("points.txt");
    if(!ifs){
        cout << "File not found." << endl;
        exit(0);
    }

    int p1A, p1B, p2A, p2B, p3A, p3B, p4A, p4B;
    Point p1, p2, p3, p4;
    while(ifs >> p1A >> p1B >> p2A >> p2B >> p3A >> p3B >> p4A >> p4B){
        p1 = {p1A, p1B};
        p2 = {p2A, p2B};
        p3 = {p3A, p3B};
        p4 = {p4A, p4B};
        p1.print();
        p2.print();
        p3.print();
        p4.print();
        isSquare(p1, p2, p3, p4) ? cout << "YES" << endl : cout << "NO" << endl;
    }

}

void testRandomPoints(){
    int N;
    cout << "N:";
    cin >> N;
    Point *points = createArray(N);
    cout << points << endl;
    printArray(points, N);

    deletePoints(points);

}

void printArray(Point* points, int numPoints){
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
    }
    cout << endl;
}

void testClosestFurthestPoints(){
    int N;
    cout << "N:";
    cin >> N;
    Point *points = createArray(N);
    cout << endl;

    pair<Point, Point> closest = closestPoints(points, N);
    cout << "Closest: ";
    closest.first.print();
    closest.second.print();
    cout << endl;

    pair<Point, Point> farthest = farthestPoints(points, N);
    cout << "Farthest: ";
    farthest.first.print();
    farthest.second.print();

    deletePoints(points);

}

void testSort(){
    int N;
    cout << "N:";
    cin >> N;
    Point *points = createArray(N);
    printArray(points, N);
    sortPoints(points, N);
    printArray(points, N);
    deletePoints(points);

}

void testFarthestPointsFromOrigin(){
    int N;
    cout << "N:";
    cin >> N;
    Point *points = createArray(N);
    cout << "The points: - "; printArray(points, N);
    Point * farPoints = farthestPointsFromOrigin(points, N);
    cout << "10 furthest points: - ";
    for (int i = 0; i < 10; ++i) {
        farPoints[i].print();
    }
    deletePoints(points);
}