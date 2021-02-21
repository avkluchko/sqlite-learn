#include <iostream>
#include <sqlite3.h>

#include "db.h"

using namespace std;

int main(int argc, char *argv[]) {
    Database database("test2.db"s);

    database.Execute(
            "CREATE TABLE IF NOT EXISTS COMPANY( "
            "ID INT PRIMARY KEY     NOT NULL, "
            "NAME           TEXT    NOT NULL, "
            "AGE            INT     NOT NULL, "
            "ADDRESS        CHAR(50), "
            "SALARY         REAL );"
    );

//    database.Execute(
//            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
//            "VALUES (1, 'Paul', 32, 'California', 20000.00 ); "
//            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
//            "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
//            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
//            "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );"
//            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
//            "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );"
//    );

    database.Execute(
            "SELECT * from COMPANY",
            [](void *data, int argc, char **argv, char **azColName) {
                for (int i = 0; i < argc; i++) {
                    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
                }
                printf("\n");

                return 0;
            }
    );

    return 0;
}
