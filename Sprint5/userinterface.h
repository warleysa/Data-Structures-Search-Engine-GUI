#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

class userInterface {
private:
    char ignoreChar;
public:
    userInterface () {
        //int testi = 1000;
        //double testd = 100;
        //float testf = 1000;
        //long double testld = 10000;
        /* DocumentParser
         * WITH
         * readInAllFiles();
         * getTop50Words();
         * readInTagFile(string);
         * readInQuesFile(string);
         * Once Query is implemented (after we can read in all data),
         * - search(string);
         * - openAtSearch(int);
         * - printAllQueries();
         * ^^^This all will be my responsibility (THE QUERY). Just have a function that calls that function in the QueryProcessor
         */
    }

    ~userInterface() {

    }

    void menu() {
        cout << "Search Engine Options:  (Choose a option between 1-4)" << endl;
        cout << "\t1) Search: " << endl;
        cout << "\t2) Print the top 50 words: " << endl;
        cout << "\t3) Add more CSV files to parse: " << endl;
        cout << "\t4) Enter maintenence mode: " << endl;
        int menuInput = -1;
        while((menuInput != 1) && (menuInput != 2) && (menuInput != 3)
              && (menuInput != 4)) {
            cout << "Enter a valid option for the menu: " << endl;
            cin >> menuInput;
        }
        switch(menuInput) {
        case 1:
            cout << "search case..." << endl;
            menu();
            search();
            break;
        case 2:
            cout << "top 50 words..." << endl;
            menu();
            //top50words();
            break;
        case 3:
            cout << "adding file case..." << endl;
            menu();
            //addFile();
            break;
        case 4:
            cout << "maintenence case..." << endl;
            maintenence();
            break;
        default:
            cout << "ERROR with the menu!!!!!" << endl;
            break;
        }
    }

    void fileHandler() {
        cout << "Reading in the files in the specified folder..." << endl;

    }

    void maintenence() {
        cout << "1) Add a pair of Tag and Question Files: " << endl;
        cout << "2) Clear all data: " << endl;
        cout << "3) Return to User Menu: " << endl;
        int input;
        while((input != 1) && (input != 2) && (input != 3)) {
            cout << "Please enter a value between 1-3:\n";
            while(!(cin >> input)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.  Try again: ";
            }
        }
        cout << "You entered: " << input << endl;
        switch(input) {
        case 1:
            cout << "Adding pair of Documents..." << endl;
            //addUserFiles();
            maintenence();
            break;
        case 2:
            cout << "Clearing all data..." << endl;
            //clearData();
            cout << "\t***Data is Cleared! Press enter any value to return to the User Menu***" << endl;
            cin >> ignoreChar;
            cin.ignore();
            menu();
            break;
        case 3:
            cout << "\t***Exiting maintenence mode. Returning to the Menu...***" << endl;
            menu();
            break;
        default:
            cout << "ERROR with the Maintenence menu!!!!!" << endl;
            cout << "Please Restart the Program!" << endl;
            break;
        }
    }

    void addUserFiles();

    void clearData();

    void search() {
        cout << "Please enter the word or phrase you would like search: " << endl;
        string query;
        cin >> query;
        //queryProcessor(query); //implementation after query processor is completed

    }

};


#endif // USERINTERFACE_H
