#pragma once

#include <sqlite3.h>

#include <iostream>
#include <string>
#include <utility>

class Database { ;
public:
    explicit Database(std::string path) : path_(std::move(path)) {}

    void Execute(const std::string &sql, int (*callback)(void *, int, char **, char **) = EmptyCallback);

    ~Database() {
        Close();
    }

private:
    std::string path_;
    sqlite3 *db_ = nullptr;

    static int EmptyCallback(void *NotUsed, int argc, char **argv, char **azColName) {
        return 0;
    };

    void Open();
    void Close();
};
