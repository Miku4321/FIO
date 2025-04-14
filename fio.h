#ifndef FIO_H_
#define FIO_H_

#include <iostream> // std::cout and std::cin
#include <limits>   // removeSpaces()
#include <conio.h>  // getch()

namespace fio
{
    constexpr char C_ESCAPE = 27;

    void pressProceed(std::string message = "Press any key to proceed...")
    {
        std::cout << message;
        getch();
    }

    // Get one of the characters specified in the string
    char getSpecChar(const std::string& wanted_chars, bool allow_to_cancel = false)
    {
        char key;

        if (wanted_chars.empty()) {
            std::cerr << "\nWanted chars can't be empty as this introduces an infinite loop!\n";
            return C_ESCAPE;
        }

        do
        {
            key = getch();

            if (key == C_ESCAPE && allow_to_cancel == true) {
                return C_ESCAPE;
            }

        } while (wanted_chars.find(key) == std::string::npos);

        return key;
    }

    // Get one of the characters specified in range
    char getRangeChar(const char& char_begin, const char& char_end, bool allow_to_cancel = false) 
    {
        char key;
        
        do
        {
            key = getch();

            if (key == C_ESCAPE && allow_to_cancel == true) {
                return C_ESCAPE;
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

    // Get a variable from the user
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
            return;
        }

        str.erase(str.begin(), str.begin() + str.find_first_not_of(' '));
        str.erase(str.begin() + str.find_last_not_of(' ') + 1, str.end());
    }

    bool promptStr(std::string& input, bool allow_to_cancel = false, std::string err_msg = "Input can't be empty! Enter again: ")
    {
        while (true)
        {
            getline(std::cin, input);
            removeSpaces(input);

            // User cancelled input and function returns true
            if (input.empty() && allow_to_cancel == true) {
                return true;
            }

            // User gave empty input. Ask for input again
            else if (input.empty() && allow_to_cancel == false) {
                std::cout << err_msg;
            }

            // User gave normal input. Terminate
            else {
                return false;
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
