#pragma once
#include "defs.h"

class Save
{
public:
    Save();

    ~Save();

    int readFile();

    void writeFile(int x);

private:
    string file_path;
};
