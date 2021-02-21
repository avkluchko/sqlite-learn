#include "db.h"

#include <stdexcept>

using namespace std;

void Database::Open() {
    if (sqlite3_open(path_.c_str(), &db_)) {
        throw runtime_error("Can't open database: " + string(sqlite3_errmsg(db_)));
    }
}

void Database::Execute(const string &sql, int (*callback)(void *, int, char **, char **)) {
    Open();

    char *zErrMsg = nullptr;
    if (sqlite3_exec(db_, sql.c_str(), callback, nullptr, &zErrMsg) != SQLITE_OK) {
        sqlite3_free(zErrMsg);
        throw runtime_error("SQL error: " + string(zErrMsg));
    }

    Close();
}

void Database::Close() {
    sqlite3_close(db_);
}