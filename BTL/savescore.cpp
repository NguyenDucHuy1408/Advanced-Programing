#include "savescore.h"


Save::Save()
{
    file_path = HIGHSCORE_FILE;
}

Save::~Save()
{

}

int Save::readFile()
{
    ifstream file(file_path);
    if (!file.is_open()) return -1;

    int highscore = 0;
    file >> highscore;
    file.close();
    return highscore;
}

void Save::writeFile(int highscore)
{
    ofstream file(file_path);
    if (!file.is_open()) return;

    file << highscore;
    file.close();
}
