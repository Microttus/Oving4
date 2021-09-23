#include "opg.h"
#include<iostream>
#include<list>
#include<string.h>
#include<QApplication>
#include<QtWidgets/QLabel>
#include<cstring>
#include<sstream>
#include<bits/stdc++.h>

opg::opg()
{

}

void opg::opg1(){
    int detNyeTallet = 42;
    std::cout << "Tallet er: " << detNyeTallet << std::endl;

    int* denNyePeker = &detNyeTallet;
    std::cout << "Adresstd::cout << dasList[];sen er: " << denNyePeker << ", og operatoren er *." << std::endl;

    int tallListe[10] = {0,1,2,3,4,5,6,7,8,9};
    //int* listePeker = tallListe;
    //std::cout << &tallListe[1] << " " << tallListe << tallListe + 1 << std::endl;
    for (int i = 0; i < 10; i++){
        std::cout << *(tallListe + i) << "  Adresse: ";
        std::cout << tallListe + i << std::endl; // Den øker med 4 siden hvert minneområde i 16 bit består av 4 blokker med 4 bit
    }
    //Akkuratt det samme, pga arkitekturen
}

int opg::askUserForInt(){
    std::cout << "Skriv et heltall her: ";
    int detNyeTallet = 0;
    std::cin >> detNyeTallet;
    std::cout << std::endl;
    return detNyeTallet;
}

bool opg::askUserForYesNoInput(){
    char svar;
    std::cout << "[y/n] ";
    std::cin >> svar;
    std::cout << std::endl;
    //std::cout << svar << std::endl;

    switch (svar){
        case 'y':
            return true;
            break;
        case 'Y':
            return true;
            break;
        case 'N':
            return false;
            break;
        case 'n':
            return false;
            break;
        default:
            std::cout << "Not suported input, please try again" << std::endl;
            askUserForYesNoInput();
    }
    return false;
}

void opg::printCases(possFlow theCase){
    switch (theCase){
        case noProblem:
            std::cout << "No Problem" << std::endl;
            return;
        case oil:
            std::cout << "Use oil" << std::endl;
            return;
        case tape:
            std::cout << "Use duct tape" << std::endl;
            return;
    } return;
}

void opg::opg2(){
    std::cout << "Verdi for A. ";
    int a = askUserForInt();
    std::cout << "Verdi for B. ";
    int b = askUserForInt();
    int* ptrA = &a;
    int* ptrB = &b;
    std::cout << "Addressen til A er: " << ptrA << ", og til B: " << ptrB << std::endl;
    return;
}

void opg::opg3(){
    std::cout << "Hvor lang skal listen være?: ";
    int listeLengde = askUserForInt();
    int dasList[listeLengde];
    for (int i=0; i < listeLengde; i++){
        std::cout << i + 1 << ". nummer i listen: ";
        int numberToAdd = askUserForInt();
        dasList[i] = numberToAdd;
    }
    int* indexList[listeLengde];
    int counter = 0, lastNum = 0;
    for (int i = 0; i < listeLengde; i++){
        if (dasList[i] > lastNum){
            counter = 0;
            indexList[counter] = &dasList[i];
            lastNum = dasList[i];
        } else if (dasList[i] == lastNum){
            counter ++;
            indexList[counter] = &dasList[i];
        }
    }
    for (int i = 0; i < counter + 1; i++){
        std::cout << indexList[i] << std::endl;
    }
}

void opg::opg4(){
    std::string text = "A string";
    std::cout << text[0] << " " << &text << " - " << text[3] << " " << &text + 3;
    std::cout << *(&text + 2) << " " << &text + 4 << " " << &text + 7;
    return;
}

void opg::engineeringFowchart(){
    std::cout << "DOES IT MOVE?";
    bool ans = askUserForYesNoInput();
    if (ans == true){
        std::cout << "Should it?";
        ans = askUserForYesNoInput();
        if (ans == true){
            //std::cout << "No Problem!" << std::endl;
            printCases(noProblem);
            return;
        } else {
            //std::cout << "Duck Tape!" << std::endl;
            printCases(tape);
            return;
        }
    } else {
        std::cout << "Should it?";
        ans = askUserForYesNoInput();
        if (ans == true){
            //std::cout << "WD-40!" << std::endl;
            printCases(oil);
            return;
        } else {
            //std::cout << "No Porblem!" << std::endl;
            printCases(noProblem);
            return;
        }
    }
}

//int opg::picShow(int argc, char *argv[],std::string filePath){
//   QApplication a(argc, argv);
//    QImage image;

//   bool loaded = image.load(filePath);
//    return 0;

//}

void opg::numberInList(){
    int lengthList = 10;
    int numberList[lengthList];
    for (int i=0;i<lengthList;i++){
        std::cout << i << ". nummer i listen på 10: ";
        numberList[i] = askUserForInt();
    }
    std::cout << "Nummer som skal telles: ";
    int theMagicNumber, counter = 0;
    std::cin >> theMagicNumber;
    for (int i=0; i<lengthList; i++){
        if (numberList[i] == theMagicNumber){
            counter++;
        }
    }
    std::cout << "Nummeret " << theMagicNumber << ", oppråtte " << counter << " ganger i listen." << std::endl;
    return;
}

void opg::numberIntoArray(){
    int theArray[6] = {1,2,3,4,5,6};
    int theNewNumber, theNewINdex, theNewArray[7];
    std::cout << "Det nye nummeret takk: ";
    theNewNumber = askUserForInt();
    std::cout << "Den ønskede indexen: ";
    theNewINdex = askUserForInt();
    for (int i=0; i<7; i++){
        if (i == theNewINdex){
            theNewArray[i] = theNewNumber;
        } else if (i < theNewINdex){
            theNewArray[i] = theArray[i];
        } else {
            theNewArray[i] = theArray[i+1];
        }
    }
    for (int i=0; i<7; i++){
        std::cout << theNewArray[i] << " ";
    }
}

void opg::stringToGnirts(){
    std::string theOriginal = "I feel you watching";
    //int arrSize = sizeof(theOriginal)/sizeof(theOriginal[0]);
    std::reverse(theOriginal.begin(),theOriginal.end());
    std::cout << theOriginal << std::endl;
}

void opg::stringToInt(){
    std::string sensorReaings = "name: Sensor A, value: 34.9;""name: Sensor B, Value: -9.2334200";

    std::stringstream ss;
    sensorReaings.erase(0,51);
    ss << sensorReaings;
    float num;
    ss >> num;

    std::cout << "The number is: " << std::setprecision(4) << num << std::endl;
}








