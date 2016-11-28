// Program holding the classes for Project4.cpp
// Devin Nemec - Networking Fall 2016

#include <string>
#include <iostream>
#include <sstream>

////////////////////////////////////////
///////// Enumerations Types ///////////
////////////////////////////////////////

enum States {CLOSED, LISTEN, SYN_RCVD, SYN_SENT, ESTABLISHED, 
            FIN_WAIT_1, CLOSING, CLOSE_WAIT, LAST_ACK, 
            FIN_WAIT_2, TIME_WAIT};

enum Message {passive_open,
              active_open,
              SYN,
              FIN,
              ACK,
              SYNACK,
              INVALID,
              FINACK,
              close};

////////////////////////////////////////
/////////// Helper Functions ///////////
////////////////////////////////////////

States closedSel(Message input){
   // Variables

   // Code
   switch(input) {
      case passive_open : {std::cout << "send: <nothing>\n";
                           std::cout << "Current state is: LISTEN\n\n";
                           return LISTEN;
                           break;}
      case active_open  : {std::cout << "send: SYN\n";
                           std::cout << "Current state is: SYN_SENT\n\n";
                           return SYN_SENT;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is CLOSED\n\n";
                           return CLOSED;
                           break;}
   }
}

States listenSel(Message input){
   switch(input) {
      case SYN          : {std::cout << "send: SYN/ACK\n";
                           std::cout << "Current state is SYN_RCVD\n\n";
                           return SYN_RCVD;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is LISTEN\n\n";
                           return LISTEN;
                           break;}
   }
}

States synRcvdSel(Message input){
   switch(input) {
      case ACK          : {std::cout << "send: <nothing>\n";
                           std::cout << "Current state is ESTABLISHED\n\n";
                           return ESTABLISHED;
                           break;}
      case close        : {std::cout << "send: FIN\n";
                           std::cout << "Current state is FIN_WAIT_1\n\n";
                           return FIN_WAIT_1;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is SYN_RCVD\n\n";
                           return SYN_RCVD;
                           break;}
   }
}

States synSentSel(Message input){
   switch(input) {
      case SYNACK       : {std::cout << "send: ACK\n";
                           std::cout << "Current state is ESTABLISHED\n\n";
                           return ESTABLISHED;
                           break;}
      case SYN          : {std::cout << "send: SYN,ACK\n";
                           std::cout << "Current state is SYN_RCVD\n\n";
                           return SYN_RCVD;
                           break;}
      case close        : {std::cout << "send: <nothing>\n";
                           std::cout << "Current state is CLOSED\n\n";
                           return CLOSED;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is SYN_SENT\n\n";
                           return SYN_SENT;
                           break;}
   }
}

States establishedSel(Message input){
   switch(input) {
      case FIN          : {std::cout << "send: ACK\n";
                           std::cout << "Current state is CLOSE_WAIT\n\n";
                           return CLOSE_WAIT;
                           break;}
      case close        : {std::cout << "send: FIN\n";
                           std::cout << "Current state os FIN_WAIT_1\n\n";
                           return FIN_WAIT_1;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is ESTABLISHED\n\n";
                           return ESTABLISHED;
                           break;}
   }
}

States finWait1Sel(Message input){
   switch(input) {
      case ACK          : {std::cout << "send: <nothing>\n";
                           std::cout << "Current state is FIN_WAIT_2\n\n";
                           return FIN_WAIT_2;
                           break;}
      case FINACK       : {std::cout << "send: ACK\n";
                           std::cout << "Current state is TIME_WAIT\n";
                           std::cout << "Current state is CLOSED\n\n";
                           return CLOSED;
                           break;}
      case FIN          : {std::cout << "send: ACK\n";
                           std::cout << "Current state is CLOSING\n\n";
                           return CLOSING;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is FIN_WAIT_1\n\n";
                           return FIN_WAIT_1;
                           break;}
   }
}

States finWait2Sel(Message input){
   switch(input) {
      case FIN          : {std::cout << "send: ACK\n";
                           std::cout << "Current state is TIME_WAIT\n";
                           std::cout << "Current state is CLOSED\n\n";
                           return CLOSED;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is FIN_WAIT_2\n\n";
                           return FIN_WAIT_2;
                           break;}
   }
}

States closingSel(Message input){
   switch(input) {
      case ACK          : {std::cout << "send: <nothing>\n";
                           std::cout << "Current state is TIME_WAIT\n";
                           std::cout << "Current state is CLOSED\n\n";
                           return CLOSED;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is CLOSING\n\n";
                           return CLOSING;
                           break;}
   }
}

States closeWaitSel(Message input){
   switch(input) {
      case close        : {std::cout << "send: FIN\n";
                           std::cout << "Current state is LAST_ACK\n\n";
                           return LAST_ACK;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is CLOSE_WAIT\n\n";
                           return CLOSE_WAIT;
                           break;}
   }
}

States lastAckSel(Message input){
   switch(input) {
      case ACK          : {std::cout << "send: <nothing>\n";
                           std::cout << "Current state is CLOSED\n\n";
                           return CLOSED;
                           break;}
      default           : {std::cout << "Invalid\n";
                           std::cout << "Current state is LACK_ACK\n\n";
                           return LAST_ACK;
                           break;}
   }
}

States timeWaitSel(Message input){
   switch(input) {
      case passive_open : return LISTEN;break;
      case active_open  : return LISTEN;break;
      case SYN          : return LISTEN;break;
      case ACK          : return LISTEN;break;
      case FIN          : return LISTEN;break;
      case close        : return LISTEN;break;
      default           : return TIME_WAIT;break;
   }
}

Message catMessage (std::string iString) {
   if (iString.compare("passive open") == 0) {
      std::cout << "recv: passive open\n";
      return passive_open;
   } else if (iString.compare("active open") == 0) {
      std::cout << "recv: active open\n";
      return active_open;
   } else if (iString.compare("SYN") == 0) {
      std::cout << "recv: SYN\n";
      return SYN;
   } else if (iString.compare("ACK") == 0) {
      std::cout << "recv: ACK\n";
      return ACK;
   } else if (iString.compare("FIN") == 0) {
      std::cout << "recv: FIN\n";
      return FIN;
   } else if (iString.compare("close") == 0) {
      std::cout << "recv: close\n";
      return close;
   } else if (iString.compare("SYN,ACK") == 0) {
      std::cout << "recv: SYN/ACK\n";
      return SYNACK;
   } else if (iString.compare("FIN,ACK") == 0) {
      std::cout << "recv: FIN/ACK\n";
      return FINACK;
   } else {
      std::cout << "recv: " << iString << "\n";
      return INVALID;
   }
}

////////////////////////////////////////
/////////// Custom Classes /////////////
////////////////////////////////////////

class State {
   protected:
      // Protected Attributes
      States state;
      
      // Protected Methods
      States alterState(Message input) {
         States output;
         switch(state) {
            case CLOSED      : output = closedSel(input); break;
            case LISTEN      : output = listenSel(input); break;
            case SYN_RCVD    : output = synRcvdSel(input); break;
            case SYN_SENT    : output = synSentSel(input); break;
            case ESTABLISHED : output = establishedSel(input); break;
            case FIN_WAIT_1  : output = finWait1Sel(input); break;
            case FIN_WAIT_2  : output = finWait2Sel(input); break;
            case CLOSING     : output = closingSel(input); break;
            case CLOSE_WAIT  : output = closeWaitSel(input); break;
            case LAST_ACK    : output = lastAckSel(input); break;
            case TIME_WAIT   : output = timeWaitSel(input); break;
         }
         return output;
      }
   public:
      // Public Methods
      States getState() {
         return state;
      }

      State() {
         state = CLOSED;
      }
      
      void receiveMessage(std::string input) {
         // Variables
         state = alterState(catMessage(input));
      }
};
