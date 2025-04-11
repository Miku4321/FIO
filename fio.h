#ifndef FIO_H_
#define FIO_H_

#include <iostream> // std::cout and std::cin
#include <limits>   // removeSpaces()
#include <conio.h>  // getch()

namespace fio
{
    void pressProceed(std::string message = "Press any key to proceed...")
    {
        std::cout << message;
        getch();
    }

    // Get character specified in the string
    char getSpecChar(const std::string& wanted_chars, bool allow_to_cancel = true)
    {
        char key;
        char escape_char = 27;

        if (wanted_chars.empty()) {
            std::cout << "Wanted chars can't be empty as this introduces an infinite loop!\n";
            return escape_char;
        }

        do
        {
            key = getch();

            if (key == escape_char && allow_to_cancel == true) {
                return escape_char;
            }

        } while (wanted_chars.find(key) == std::string::npos); 

        return key;
    }

    // Get Character specified in range
    char getRangeChar(const char& char_begin, const char& char_end, bool allow_to_cancel = true) 
    {
        char key;
        char escape_char = 27;

        do
        {
            key = getch();

            if (key == escape_char && allow_to_cancel == true) {
                return escape_char;
            }
        
        } while((key < char_begin || key > char_end));

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
        while (true)
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

    void removeSpaces(std::string &str) // Helper function for promptStr()
    {
        if(str.find_first_not_of(' ') == std::string::npos)
        {
            str.clear();
            return;
        }

        str.erase(str.begin(), str.begin() + str.find_first_not_of(' '));
        str.erase(str.begin() + str.find_last_not_of(' ') + 1, str.end());
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

    template<typename... Types>
    void print(const Types&... args)
    {
        (std::cout << ... << args);
        std::cout << '\n';
    }
};

#endif
