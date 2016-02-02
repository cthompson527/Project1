## Independent Project 1

This project is broken into three major sections:

#### Section 1 - Retrieve the Data
The data is retrived from espn.go.com. This data is saved in an Excel file and then formulas are ran on the Excel file to populate the information needed to perform the calculations. The data is saved as a .csv file, and then formated by into a space separated .txt file saved in Input File/.

#### Section 2 - Java Code
A Java Project is created and saved under the Java/ folder. In this project, there are three Java classes: Main, Parser, and Team. Parser parses the information in the input file. Team is a class of the team object for each of the 32 teams in the NFL. Main does the calculations of the information, and prints it to the console.

#### Section 3 - C++ Code
A C++ Project is created and saved under the C++/ folder. In this project, there are two C++ classes: Parser, and Team, each with their respective .h and .cpp files associated with them. Parser parses the information in the input file. Team is a class of the team object for each of the 32 teams in the NFL. The main function does the calculations of the information, and prints it to the console.

# Running the Programs
#### Program 1 - Java
The Java project can be compiled and ran from the command-line while in the Java directory:

```
$ javac -classpath commons-math3-3.6.jar:. edu/tamu/csce315/Main.java
$ java -cp commons-math3-3.6.jar:. edu/tamu/csce315/Main
```

#### Program 2 - C++
The C++ project can be compiled and ran from the command-line while in the C++ directory:

```
$ g++ Main.cpp -o main
$ ./main
```
