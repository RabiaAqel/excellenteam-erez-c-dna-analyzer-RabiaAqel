//
// Created by Rabia on 30/12/2018.
//

#ifndef DNA_ANALYZER_FILEWRITER_H
#define DNA_ANALYZER_FILEWRITER_H


class FileWriter
{
public:
    FileWriter ();
    ~FileWriter ();

    void writeFile (char *fileName, char *data);
};


#endif //DNA_ANALYZER_FILEWRITER_H
