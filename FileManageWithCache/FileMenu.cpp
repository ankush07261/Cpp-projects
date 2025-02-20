#include "FileMenu.h"

void FileMenu::displayMenu()
{
    int choice;
    string filename;

    while (true)
    {
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

        if (choice >= 1 && choice <= 4)
        {
            cout << "Enter file name: ";
            cin >> filename;
            FileManagement fm(filename);

            switch (choice)
            {
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
        }
        else if (choice == 5)
        {
            FileManagement::listFiles();
        }
        else if (choice == 6)
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice, try again" << endl;
        }
    }
}
