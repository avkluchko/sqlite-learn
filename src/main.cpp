#include <iostream>
#include <sqlite3.h>

using namespace std;

int main() {
    sqlite3 *db;
//    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    return 0;
}

