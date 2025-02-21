# 📂 File Management System with Caching  
A simple **C++ file management system** that supports **creating, reading, appending, deleting, and listing files**, with an **in-memory caching system** to optimize file reads.

---

## 🚀 Features  
✔️ **Create** a new file and store content.  
✔️ **Read** files efficiently with caching.  
✔️ **Append** new content to existing files.  
✔️ **Delete** files from the system.  
✔️ **List** all files in the current directory.  

---

## 🛠 Tech Stack  
- **C++** (OOP, File Handling, STL)  
- **Filesystem Library** (C++17)  

---

## 📂 Project Structure  
FileManageWithCache/
│── FileCache.h          # Header file for caching system
│── FileCache.cpp        # Implementation of caching
│── FileManagement.h     # Header file for file operations
│── FileManagement.cpp   # Implementation of file operations
│── FileMenu.h           # Header file for user interface
│── FileMenu.cpp         # Implementation of user interface
│── main.cpp             # Entry point of the program
│── output/              # Directory to store compiled files (optional)
│── file_manager.exe     # Compiled executable (Windows)
│── README.md            # Project documentation


---

## 💻 How to Compile and Run  
### 🔹 Using g++ (Linux/Windows)
```sh
g++ main.cpp FileCache.cpp FileManagement.cpp FileMenu.cpp -o file_manager
./file_manager  # Linux/macOS
file_manager.exe  # Windows