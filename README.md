# FIO

**FIO:**<br>
"Functions input output" is a beginner-made C++ library that includes prompt utilities.
This library expands `std::cin`, `getch()` and `getline()` with quality of life and error handling.
I'm a beginner and this repository was made to learn how Github works.

# Known issues:

-`prompt()` may lock the user in an infinite loop<br>
-Due to use of `getch()`, the library may be limited to Windows.

# Functions list:

### pressProceed()
A simple "Press any key to continue" function.
You can optionally pass a custom message.

```cpp
fio::pressProceed();

//Same message, but in polish language
fio::pressProceed("Naciśnij dowolny przycisk, aby kontynuować...");
```

### getSpecChar()
As an argument, you need to pass a string of characters that you want the user to press, the loop won't end till the user presses any of the specified keys.You can optionally pass `true` if you want the user to press escape.

```cpp
char math_operation;

// Without cancelling
std::cout << "Press either of +-*/ to choose a math operation: ";
math_operation = fio::getSpecChar("+-*/");
std::cout << math_operation;

std::cout << "\n\n";

// With cancelling
std::cout << "Press either of +-*/ to choose a math operation (Press escape to cancel): ";
math_operation = fio::getSpecChar("+-*/", true); // true allows for cancelling

if (math_operation == fio::C_ESCAPE) // Handles the case if user wants to cancel
{ 
    std::cout << "Cancelling...\n";
    return 0;
}
else {
    std::cout << math_operation;
}
```

### getRangeChar()
It's the same as `getSpecChar()`, but instead it accepts a range of characters, for example digits from 1 to 9.
Just like in `getSpecChar()`, you can optionally pass `true` if you want the user to press escape and cancel.

```cpp
// get numbers
std::cout << "Press a number 1-9: ";
std::cout << fio::getRangeChar('1', '9') << "\n\n";

// get letters (with cancelling)
char letter_choice;

std::cout << "Press a letter a-z: ";
letter_choice = fio::getRangeChar('a', 'z', true);

if (letter_choice == fio::C_ESCAPE) {
    std::cout << "Cancelling...\n";
    return 0;
}
else {
    std::cout << letter_choice;
}
```

### pressYN()
Similar to `getSpecChar()`, but accepts only `y/Y/n/N` and returns a boolean.

```cpp
std::cout << "Do you want to exit? Y/N";

if (fio::pressYN()) // If user presses `y/Y` and the functions returns `true`
{
    std::cout << "Exiting...\n";
    return 0;
}
else // If user presses `n/N` and the functions returns `false`
{
    std::cout << "Exiting cancelled!\n";
    // continue
}
```

### prompt()
`std::cin`, but with built in error handling and buffer flushing.
For example, the user can't input a string for an int.

```cpp
int age;

std::cout << "Enter your age: ";
fio::prompt(age);

std::cout << "Your age is: " << age;
```

### removeSpaces()
Helper function for `promptStr()`.
Removes spaces from both the front and back, but not between characters.

### promptStr()
`getline()`, but trims spaces with `removeSpaces()`.

Just like with other functions, cancelling is disabled by default but can be enabled by passing `true`.
If cancelling is enabled and user entered empty input (or input that consists of only spaces), function will interpret is as cancellation, but if cancelling is disabled and user entered empty input, function will interpret it as an error and ask for input again.

You can optionally pass a custom error message.

```cpp
std::string name;

std::cout << "Enter your name: ";
fio::promptStr(name);


std::cout << "Your name is: " << name;
```

### print()
``std::cout``, but as a function. I couldn't really figure out how to print `, ` in between the arguments, so it only prints a '\n' at the end.
You decide if it's useful or not.

```cpp
int age = 25;

fio::print("Hello world");             // Hello world
fio::print(5);                         // 5
fio::print(1, ". Your age is: ", age); // 1. Your age is: 25
```
