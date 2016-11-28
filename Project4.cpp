/***********************************************************
Devin Nemec
Networking - Fall 2016
TCP State Diagram Program

Purpose:
Example to show how server/clients manage states with TCP.
Written in C++

Input:
This program accepts input via the command line interface.

Output:
Current TCP state based on input
***********************************************************/

#include "states.hpp"
#include <iostream>
#include <string>

using namespace std;

int main () {
   // Variables
   string inputString = "";
   State computer;

   // Code
   while (true) {
      // Print Prompt to receive state
      cout << "Choice : ";
      getline (cin, inputString);
      cout << "\n";

      if (inputString.compare("quit") == 0) {
         cout << "Quiting!\n";
         return 0;
      }

      // Receive State
      computer.receiveMessage(inputString);
   }
}
