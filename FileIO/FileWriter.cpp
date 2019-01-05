//
// Created by Rabia on 30/12/2018.
//

#include "FileWriter.h"
#include <cstdio>


FileWriter::FileWriter () {}


FileWriter::~FileWriter () {}


void FileWriter::writeFile (char *fileName, char data[])
{
    FILE *file = fopen (fileName, "w+");
    int return_val = fputs (data, file);

    if ( return_val >= 0 )
        printf ("Success");
    else
        printf ("failed");

    fclose (file);
    return;
}
