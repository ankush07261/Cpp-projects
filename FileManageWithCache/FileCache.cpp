#include "FileCache.h"

FileCache *FileCache::instance = nullptr;

FileCache *FileCache::getInstance()
{
    if (instance == nullptr)
        instance = new FileCache();
    return instance;
}

FileCache::~FileCache() {}

void FileCache::store(string &filename, string &content)
{
    cache[filename] = content;
}

bool FileCache::getCache(string &filename, string &content)
{
    if (cache.find(filename) != cache.end())
    {
        content = cache[filename];
        return true;
    }
    return false;
}

void FileCache::invalidate(string &filename)
{
    cache.erase(filename);
}

void FileCache::clean()
{
    delete instance;
    instance = nullptr;
}
