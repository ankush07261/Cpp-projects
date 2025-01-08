#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>

using namespace std;
namespace fs = filesystem;

class FileCache
{
private:
    unordered_map<string, string> cache;
    static FileCache *instance;
    FileCache() {}

public:
    static FileCache *getInstance()
    {
        if (instance == nullptr)
            instance = new FileCache();
        return instance;
    }

    ~FileCache(){}

    void store(string &filename, string &content)
    {
        cache[filename] = content;
    }

    bool getCache(string &filename, string &content)
    {
        if (cache.find(filename) != cache.end()){
            content = cache[filename];
            return true;
        }
        return false;
    }

    void invalidate(string &filename)
    {
        cache.erase(filename);
    }

    static void clean(){
        delete instance;
        instance = nullptr;
    }
};

class FileManagement
{
private:
    string filename;
    FileCache *cache;

public : 
    FileManagement(string &name) : filename(name)
    {
        cache = FileCache::getInstance();
    }

    void create(){
        try{
        ofstream file(filename);

        if(!file){
            cout << "an error occured";
            return;
        }
        cout<<"enter content:\n";
        cin.ignore();
        string content;
        getline(cin, content);
        file << content;
        cache->store(filename, content);
        file.close();
        cout << "File created successfully";
        } catch (const exception &e){
            cout << "exception occured: " << e.what() << endl;
        }
    }

    void read(){
        string content;

        if(cache->getCache(filename, content)){
            cout << "its stored in cache, heres the content:" << endl
                 << endl;
            cout << content << endl;
            return;
        }

        ifstream file(filename);

        if(!file){
            cout << "File not found";
            return;
        }

        cout << "File Content:\n";
        string line, fullContent;
        while(getline(file,line)){
            cout << line << endl;
            fullContent += line + "\n";
        }
        file.close();
        cache->store(filename, fullContent);
    }

    void append(){
        ofstream file(filename, ios::app);
        if(!file){
            cout << "file not found\n";
            return;
        }

        cout << "enter content to append:\n";
        cin.ignore();
        string content;
        getline(cin, content);
        file << endl
             << content;
        file.close();

        cache->invalidate(filename);
        cout << "Content appended.\n";
    }

    void deleteFile(){
        if(fs::remove(filename)){
            cache->invalidate(filename);
            cout << "deleted successfully\n";
        }
        else{
            cout << "file not found\n";
        }
    }

    static void listFiles(){
        cout << "Files in this directory are:\n";
        for(const auto& entry : fs::directory_iterator(".")){
            if(fs::is_regular_file(entry.path()))
                cout << entry.path().filename() << endl;
        }
    }
};

class FileMenu{
public:
    void displayMenu(){
        int choice;
        string filename;

        while(true){
            cout << "\nFile Management System with Caching\n";
            cout << "---------------------------------------\n";
            cout << "1. Create a File\n";
            cout << "2. Read a File\n";
            cout << "3. Append to a File\n";
            cout << "4. Delete a File\n";
            cout << "5. List Files\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cout << "---------------------------------------\n";

            if(choice >= 1 && choice <= 4){
                cout<<"Enter file name: ";
                cin >> filename;
                FileManagement fm(filename);

                switch(choice){
                    case 1:
                        fm.create();
                        break;
                    case 2:
                        fm.read();
                        break;
                    case 3:
                        fm.append();
                        break;
                    case 4:
                        fm.deleteFile();
                        break;
                }
            } else if (choice == 5){
                FileManagement::listFiles();
            } else if (choice == 6){
                cout << "Exiting..." << endl;
                break;
            } else {
                cout << "Invalid choice, try again" << endl;
            }
        }
    }
};

FileCache *FileCache::instance = nullptr;

int main()
{
    FileMenu fmenu;
    fmenu.displayMenu();
    FileCache::clean();
    return 0;
}