#ifndef FILECACHE_H
#define FILECACHE_H

#include <unordered_map>
#include <string>
using namespace std;

class FileCache
{
private:
    unordered_map<string, string> cache;
    static FileCache *instance;
    FileCache() {}

public:
    static FileCache *getInstance();
    ~FileCache();
    void store(string &filename, string &content);
    bool getCache(string &filename, string &content);
    void invalidate(string &filename);
    static void clean();
};

#endif
