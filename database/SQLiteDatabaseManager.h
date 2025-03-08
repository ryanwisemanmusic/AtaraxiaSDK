#ifndef SQLITEDATABASEMANAGER
#define SQLITEDATABASEMANAGER

#include <sqlite3.h>
#include <string>
#include <vector>

struct ScoreEntry
{
    int id;
    std::string player_name;
    int score;
    std::string timestamp;
};

class DatabaseManager
{
    public:
    std::string dbFile;
    DatabaseManager(const std::string& dbFile);
    ~DatabaseManager();

    private:
    sqlite3* db;
    bool executeSQL(const std::string& sql);
};

#endif