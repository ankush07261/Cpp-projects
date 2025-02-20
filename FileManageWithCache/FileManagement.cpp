#include "FileManagement.h"

FileManagement::FileManagement(string &name) : filename(name)
{
    cache = FileCache::getInstance();
}

void FileManagement::create()
{
    try
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "An error occurred";
            return;
        }
        cout << "Enter content:\n";
        cin.ignore();
        string content;
        getline(cin, content);
        file << content;
        cache->store(filename, content);
        file.close();
        cout << "File created successfully";
    }
    catch (const exception &e)
    {
        cout << "Exception occurred: " << e.what() << endl;
    }
}

void FileManagement::read()
{
    string content;
    if (cache->getCache(filename, content))
    {
        cout << "It's stored in cache, here's the content:\n\n"
             << content << endl;
        return;
    }

    ifstream file(filename);
    if (!file)
    {
        cout << "File not found";
        return;
    }

    cout << "File Content:\n";
    string line, fullContent;
    while (getline(file, line))
    {
        cout << line << endl;
        fullContent += line + "\n";
    }
    file.close();
    cache->store(filename, fullContent);
}

void FileManagement::append()
{
    ofstream file(filename, ios::app);
    if (!file)
    {
        cout << "File not found\n";
        return;
    }

    cout << "Enter content to append:\n";
    cin.ignore();
    string content;
    getline(cin, content);
    file << endl
         << content;
    file.close();

    cache->invalidate(filename);
    cout << "Content appended.\n";
}

void FileManagement::deleteFile()
{
    if (fs::remove(filename))
    {
        cache->invalidate(filename);
        cout << "Deleted successfully\n";
    }
    else
    {
        cout << "File not found\n";
    }
}

void FileManagement::listFiles()
{
    cout << "Files in this directory are:\n";
    for (const auto &entry : fs::directory_iterator("."))
    {
        if (fs::is_regular_file(entry.path()))
            cout << entry.path().filename() << endl;
    }
}
