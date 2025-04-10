# FIO

**FIO** (Functions input output) is a begginer-made C++ library that includes prompt utilities.
This library expands functions std::cin, getch() and getline() with error handling.
I'm a beginner and this repository was made to learn how Github works. 

**Note**: FIO doesn't really have any functions output, since fio::print() got disabled

# Functions list:

### pressProceed() -
A simple "Press any key to continue" function.
Includes an optional, custom message

### getSch() - getSpecifiedChar
As an argument, you need to pass a string of characters that you want the user to press,
then the loop doesn't end till the user presses any of the keys passed as arguments.
If user presses any of the keys, that one character is returned.
for example: getSch("+-/*")

### getRch() - getRangeChar
It's the same as getSch, but instead it accepts a range of characters.
for example digits from 1 to 9.

### pressYN() -
Similar to getSch, but returns a booelan based on Y/N.

### prompt() -
std::cin, but with built in error handling and buffer flushing.

### removeSpaces() -
Helper function for promptStr.
Removes spaces from both the front and back, but not between characters.

### promptStr() -
getline, but trims spaces with removeSpaces.
It doesn't accept empty input, or input that consists of only spaces.

### print() -
std::cout, but as a function. I couldn't really figure out how to print ", " in between the argumetnts so I disabled as it's kinda useless without it.
