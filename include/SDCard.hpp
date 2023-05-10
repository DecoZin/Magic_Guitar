#ifndef SDCARD
#define SDCARD

#include <vector>
#include <SD.h>
#include <string>
#include <regex>
using namespace std;

class SDCard
{
public:
    SDCard();

    vector<string> getList();

    void Makelist();

    void printPosition(std::string pFileName);

    string readFile(int pNumFile, char pNumStroke);

    void writeInFile(vector<int> pEnginePos);

    String getCurrentTarget();

    int SD_SPEED;

    string SD_SUBDIVISION;

    string authorName;

private:
    vector<string> mFilesNames;
};

#endif