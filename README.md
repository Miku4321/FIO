# FIO

**FIO:**<br>
"Functions input output" is a beginner-made C++ library that includes prompt utilities.
This library expands functions `std::cin`, `getch()` and `getline()` with error handling.
I'm a beginner and this repository was made to learn how Github works. 

**NOTE:** FIO doesn't really have any output functions, since fio::print() got disabled.<br>

# Known issues:

-`prompt()` and `promptStr()` may lock the user in an infinite loop<br>
-`removeSpaces()` is not really efficient as it goes through 2 loops instead of using standard string functions<br>
-`print()` doesn't work<br>
-Due to use of `getch()`, the library may be limited to Windows.

# Functions list:

### pressProceed()
A simple "Press any key to continue" function.
You can optionally pass a custom message.

```cpp
fio::pressProceed();
fio::pressProceed("Naciśnij dowolny przycisk, aby kontynuować...");
```

### getSpecChar()
As an argument, you need to pass a string of characters that you want the user to press,
the loop won't end till the user presses any of the specified keys.

If the user presses escape, programmer who uses the function handles it himself and cancels the input.
You can optionally pass `false` if you don't want the user to press escape.

```cpp
char math_operation;
char escape = 27;

std::cout << "Choose math operation +-*/ (Press escape to cancel): ";
math_operation = fio::getSpecChar("+-*/"); // Code will continue only if the user presses '+', '-', '*', '/' or 'escape'

if (math_operation == escape) // Handles the case if user wants to cancel
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

```cpp
char num_choice;
char escape = 27;

// get numbers
std::cout << "Press number 1-9: ";
num_choice = fio::getRangChar('1', '9');

if (num_choice == escape) {
	std::cout << "Cancelling";
	return 0;
}
else {
	std::cout << num_choice << "\n\n";
}

// get letters
std::cout << "Press letter a-z: ";
std::cout << fio::getRangChar('a', 'z', false); // User won't be able to cancel due to "false" parameter
```

### pressYN()
Similar to `getSpecChar()`, but returns a boolean based on if the user presses `Y` or `N`.

```cpp
std::cout << "Do you want to exit? Y/N";

if (fio::pressYN()) // if user presses 'Y' and the functions returns "true"
{
	std::cout << "Exiting...\n";
	return 0;
}
else // if user presses 'N' and the functions returns "false"
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
It doesn't accept empty input, or input that consists of only spaces.

```cpp
std::string name;

std::cout << "Enter your name: ";
fio::promptStr(name);

std::cout << "Your name is: " << name;
```

### print()
``std::cout``, but as a function. I couldn't really figure out how to print `, ` in between the arguments, so I disabled it as it's kinda useless without it.

```cpp
fio::print("Hello world");                  // Hello world
fio::print(5);                              // 5
fio::print(1, ". Your age is: ", 25, '\n'); // 1. Your age is: 25
```
