#ifndef OPG_H
#define OPG_H
#include<string>

class opg
{
public:
    opg();
    void opg1();
    void opg2();
    void opg3();
    void opg4();
    void engineeringFowchart();

    void numberInList();
    void numberIntoArray();
    void stringToGnirts();
    void stringToInt();
private:
    int askUserForInt();
    bool askUserForYesNoInput();
    enum possFlow {noProblem,oil,tape};
    void printCases(possFlow);
    int picShow(int argc, char *argv[], std::string filePath);
};

#endif // OPG_H
