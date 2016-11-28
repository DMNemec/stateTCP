Project 4 for Networking Fall 2016
Devin Nemec

Project Summary:
  This program simulates TCP state transition by accepting command
  line input and moving through states as a server/client would.

Inventory:
  Project4.cpp -- the main program logic
  states.hpp --header holding the classes and enums I made
  stateTCP --the compiled program
  in1.txt --smaller test program with invalid input
  in2.txt --large test program that checks all valid paths
  testin.txt --something you included

Instructions for Compiling:
  $> g++ Project4.cpp -std=C++14 -o stateTCP

Instructions for Running:
  Manual Input
    $> ./stateTCP
  File Input
    $> cat <input file> | ./stateTCP > <outputfile>

Challenges Encountered:
  Really didn't have any problems with it. Found a few logic
  errors when I built in2.txt, but nothing difficult. I did
  add FIN,ACK to the valid input to account for it being present
  on the diagram but not listed in the list of commands you gave.

Explanations:
  "<"
    Sends the file as Standard Input to a command.
  ">"
    Redirects the output to a file.
  "|"
    Pipes the output of a command to the input of another.
  "diff"
    diff compares the difference between 2 files, line by line. It
    prints out which lines are different after it's run
