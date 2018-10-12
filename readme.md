Project 4 for Networking Fall 2016<br>
Devin Nemec<br>
<br>
Project Summary:<br>
  This program simulates TCP state transition by accepting command
  line input and moving through states as a server/client would.
<br>
Inventory:<br>
  Project4.cpp -- the main program logic<br>
  states.hpp --header holding the classes and enums I made<br>
  stateTCP --the compiled program<br>
  in1.txt --smaller test program with invalid input<br>
  in2.txt --large test program that checks all valid paths<br>
  testin.txt --something you included<br>
  README.txt --this file<br>
<br>
Instructions for Compiling:<br>
  `$> g++ Project4.cpp -std=C++14 -o stateTCP`<br>
<br>
Instructions for Running:<br>
  Manual Input<br>
    `$> ./stateTCP`<br>
  File Input<br>
    `$> cat <input file> | ./stateTCP > <outputfile>`<br>

Challenges Encountered:<br>
  Really didn't have any problems with it. Found a few logic
  errors when I built in2.txt, but nothing difficult. I did
  add FIN,ACK to the valid input to account for it being present
  on the diagram but not listed in the list of commands you gave.

Explanations:<br>
  "<"<br>
    Sends the file as Standard Input to a command.<br>
  ">"<br>
    Redirects the output to a file.<br>
  "|"<br>
    Pipes the output of a command to the input of another.<br>
  "diff"<br>
    diff compares the difference between 2 files, line by line. It
    prints out which lines are different after it's run
