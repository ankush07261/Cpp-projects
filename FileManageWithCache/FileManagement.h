#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include "FileCache.h"
using namespace std;
namespace fs = filesystem;

class FileManagement
{
private:
    string filename;
    FileCache *cache;

public:
    FileManagement(string &name);
    void create();
    void read();
    void append();
    void deleteFile();
    static void listFiles();
};

#endif
