#include<iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(string (&mainArrayToRead)[1000], int &elementCounter, string fileToRead) {
    int i = 0;
    string temp;
    fstream readThisFile;

    readThisFile.open(fileToRead, ios::in);
    if (readThisFile.is_open()) {
        string line;
        while (getline(readThisFile, line)) {
            mainArrayToRead[i] = line;
            i++;
        }
    }
    if(fileToRead == "setup.txt") {
        string name = mainArrayToRead[0];
        int nameLength = int(name.length());
        for(i=(int(name.find('='))+1); i<nameLength; i++) {
            cout << name[i];
        }
    }

    readThisFile.close();
    elementCounter = i;
}

void writeToFile(string (&arrayFFHistory)[6], string fileToWrite) {
    string temp;
    fstream writeToThisFile;

    writeToThisFile.open(fileToWrite, ios::app);
    if (writeToThisFile.is_open()) {
        for(int i=0; i<6; i++){
            writeToThisFile << arrayFFHistory[i] <<endl;
        }
    }
    writeToThisFile.close();
}

int main() {
    /// Glowna tablica do czytania z plikow ktora zawsze wywolujemy, rozmiar 100 bo zakladamy ze wiecej i tak nie moze byc, w poleceniu mozemy uzyc hardcoded wartosci
    string mainArrayToRead[1000];
    /// Tablica do zapisywania historii w pliku
    string arrayFFHistory[6];
    /// Zmienna do liczenie elementów tablicy podczas czytania, elementCounter uzywamy do wypisania danych z pliku jak w przykladowych petlach (patrz nizej przyklad)
    int elementCounter;

    /// Glowne pliki do obslugi programu
    string burgerFile = "burger.txt";
    string pizzaFile = "pizza.txt";
    string drinksFile = "drinks.txt";
    string historyFile = "history.txt";
    string setupFile = "setup.txt";

    /// Testowe zmienne
    string readTestFile = "test2.txt";

    /// Przykladowe wywolanie funkcji i wypisanie z tablicy przy uzyciu elementCounter
    /// readFile(zawsze podajemy nazwe tablicy ogolnej, elementCounter - zlicza rozmiar tablicy, plik jaki chcecie wczytac do tablicy)
//    readFile(mainArrayToRead, elementCounter, readTestFile);
//    for (int i = 0; i < elementCounter; i++) {
//        cout << mainArrayToRead[i] << endl;
//    }

    /// TEST ZAPISU I ODCZYTU
    /// Przykladowa tablica do zapisania w historii - rozmiar 5 bo mamy 6 pozycji w historii(0,1,2,3,4,5)
    string appendToHistory[6];
    /// Testowy plik
    string writoToTestFile = "test2.txt";
    /// Przykladowa tablica do wpisania do pliku
    appendToHistory[0] = "03";
    appendToHistory[1] = "2022-01-19";
    appendToHistory[2] = "ID465152";
    appendToHistory[3] = "Burger Duzy,Burger Maly,Pizza Duza,Pizza Mala,Cola";
    appendToHistory[4] = "15.99,16.99,20.99,15.99,16.99";
    appendToHistory[5] = "1,1,1,1,1";
    /// writeToFile()
    /// Przykladowe wywolanie funkcji do zapisu
    /// writeToFile(Wprowadz tablice z ktorej informacje chcesz wpisac do pliku(6 linijek wedle ustalen), podaj plik do jakiego zapisac)
//    writeToFile(appendToHistory, writoToTestFile);
//    readFile(mainArrayToRead, elementCounter, writoToTestFile);
//    for (int i = 0; i < elementCounter; i++) {
//        cout << mainArrayToRead[i] << endl;
//    }

    /// Przkladowe wypisanie nazwy resturacji z SETUPFILE
    ///Funckji odrazu wypisze nazwe wiec mozna uzywac wewnatrz np cout, skladnia musi byc zawsza taka sama
    readFile(mainArrayToRead, elementCounter, setupFile);

    return 0;
}
