#include <iostream>

#include "Ceg.h"

int main() {
    Szemely szemely("Nagy", "Janos", 2001);
    cout << szemely << endl;
    Manager manager1("Szep", "Tunde", 1976, "manager");
    Manager manager2("Kedves", "Sandor", 1985, "manager");
    Manager manager3("Eross", "Kelemen", 1963, "manager");

    Alkalmazott alkalmazott1("Kiss", "Erno", 1996, "automatizalo");
    Alkalmazott alkalmazott2("Beder", "Norbert", 2002, "programozo");
    Alkalmazott alkalmazott3("Nagy", "Matyas", 1977, "rendszergazda");
    Alkalmazott alkalmazott4("Orban", "Akos", 1967, "automatizalo");
    Alkalmazott alkalmazott5("Nemeth", "Andras", 2003, "programozo");
    Alkalmazott alkalmazott6("Bacs", "Zoltan", 1989, "rendszergazda");
    Alkalmazott alkalmazott7("Dobos", "Imre", 1992, "automatizalo");


    cout << alkalmazott1 << endl;
    cout << alkalmazott2 << endl;
    cout << alkalmazott3 << endl;
    cout << alkalmazott4 << endl;
    cout << alkalmazott5 << endl;
    cout << alkalmazott6 << endl;
    cout << alkalmazott7 << endl << endl;





    manager1.addAlkalmazott(&alkalmazott1);
    manager1.addAlkalmazott(&alkalmazott2);
    manager1.addAlkalmazott(&alkalmazott3);
    cout << manager1 << endl;

    cout << "2. alkalmazott kirugasa a manager alol" << endl;
    manager1.deleteAlkalmazott(&alkalmazott2);

    cout << manager1 << endl;
    manager1.deleteAlkalmazott(&alkalmazott1);


    Ceg ceg;
    ceg.addWorker(&manager1);
    ceg.addWorker(&manager2);
    ceg.addWorker(&manager3);
    ceg.addWorker(&alkalmazott1);
    ceg.addWorker(&alkalmazott2);
    ceg.addWorker(&alkalmazott3);
    ceg.addWorker(&alkalmazott4);
    ceg.addWorker(&alkalmazott5);
    ceg.addWorker(&alkalmazott6);
    ceg.addWorker(&alkalmazott7);

    ceg.removeWorker(&alkalmazott1);
    ceg.addToManager(&manager1, &alkalmazott1); // nem lehet mert mar kivolt rugva az alkalmazott2


    cout << "a cegben a manager1-tol eltavolitsuk az alkalmazott3-at: " << endl;
    ceg.removeFromManager(&manager1, &alkalmazott3);
    cout << manager1 << endl << endl << endl;

    cout << "CEG TESZTELES: " << endl << endl;
    ceg.addToManager(&manager1, &alkalmazott2);
    ceg.addToManager(&manager1, &alkalmazott3);
    ceg.addToManager(&manager1, &alkalmazott4);
    ceg.addToManager(&manager2, &alkalmazott5);
    ceg.addToManager(&manager2, &alkalmazott6);
    ceg.addToManager(&manager3, &alkalmazott7);

    cout << "PRINT EVERY WORKER: " << endl;
    ceg.print(cout);

    ceg.removeFromManager(&manager1, &alkalmazott3);
    ceg.addToManager(&manager3, &alkalmazott3);

    cout << endl << endl << "PRINT ONLY MANAGERS AND THEIR SUBORDINATES" << endl;
    ceg.printManager(cout);
    return 0;
}