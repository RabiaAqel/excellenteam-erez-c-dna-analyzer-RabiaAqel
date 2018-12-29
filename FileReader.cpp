//
// Created by Rabia on 29/12/2018.
//

#define MAXBUFLEN 1000000

#include <stdio.h>
#include <stdlib.h>

#include "FileReader.h"


FileReader::FileReader ()
{

}

FileReader::~FileReader ()
{

}


char *FileReader::readFile (char *fileName)
{

    char source[MAXBUFLEN + 1];
    FILE *fp = fopen (fileName, "r");
    if (fp != NULL)
    {
        size_t newLen = fread (source, sizeof (char), MAXBUFLEN, fp);
        if (newLen == 0)
        {
            fputs ("Error reading file", stderr);
        } else
        {
            source[newLen] = '\0';
        }

        fclose (fp);
    }

    return source;

}


