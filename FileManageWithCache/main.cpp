#include "FileMenu.h"

int main()
{
    FileMenu fmenu;
    fmenu.displayMenu();
    FileCache::clean();
    return 0;
}
