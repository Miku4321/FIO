// #include "../../Headers/fio.h"

#ifndef FIO_H_
#define FIO_H_

#include <iostream>
#include <limits>
#include <conio.h>

namespace fio
{
    void pressProceed(std::string message = "Press any key to proceed...")
    {
        std::cout << message;
        getch();
    }

    char getSch(const std::string& wanted_chars)
    {
        char key;
        
        do
        {
            key = toupper(getch());

        } while (wanted_chars.find(key) == std::string::npos);

        return key;
    }

    char getRch(const char& char_begin, const char& char_end)
    {
        char key;

        do {
            key = toupper(getch());
        } while(key < char_begin || key > char_end);

        return key;
    }

    bool pressYN()
    {
        while (true) {
            switch(getch()) {
                case 'y': case 'Y': return true;
                case 'n': case 'N': return false;
            }
        }
    }

    template<typename T>
    void prompt(T& val, std::string err_message = "Wrong input! Enter again: ")
    {
        while(true)
        {
            std::cin >> val;
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << err_message;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }

    void removeSpaces(std::string &str)
    {
        // Remove from front
        while(!str.empty() && str[0] == ' ') {
            str.erase(str.begin());
        }
        
        // Remove from back
        while(!str.empty() && str[str.size()-1] == ' ') {
            str.erase(str.end() - 1);
        }
    }

    void promptStr(std::string& str, std::string err_message = "Field can not be empty! Enter again: ")
    {
        while (true)
        {
            getline(std::cin, str);
            removeSpaces(str);

            if (str.empty()) {
                std::cout << err_message;
            }
            else {
                break;
            }
        }
    }

    /*
        template<typename... Args>
        void print(const Args&... args) {
            (std::cout << ... << args);
        }
    */
};

#endif

/*

Functions list:

pressProceed() -
A simple "Press any key to continue" function.
Includes an optional, custom message

getSch() - getSpecifiedChar
As an argument, you need to pass a string of characters that you want the user to press,
then the loop doesn't end till the user presses any of the keys passed as arguments.
If user presses any of the keys, that one character is returned.
for example: getSch("+-/*")

getRch() - getRangeChar
It's the same as getSch, but instead it accepts a range of characters.
for example digits from 1 to 9.

pressYN() -
Similar to getSch, but returns a booelan based on Y/N.

prompt() -
std::cin, but with built in error handling and buffer flushing.

removeSpaces() -
Helper function for promptStr.
Removes spaces from both the front and back, but not between characters.

promptStr() -
getline, but trims spaces with removeSpaces.
It doesn't accept empty input, or input that consists of only spaces.

print() -
std::cout, but as a function. It wasn't really useful, so I deleted it.

*/