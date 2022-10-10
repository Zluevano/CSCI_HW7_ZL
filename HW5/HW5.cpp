/*
Programmer: Zachary Luevano
Date Finished: 10/09/22
Description: Certainly one of the more complicated programs we've made. Plays a
6 way game of rock paper scissors. REVISED with Arrays for added fun.

Works by using multiple prototype functions for part is a loop that repeats the
entire thing 3 times, second is a while loop that the user has a choice to pick
whatever they wish that is connected to a bool function that only proceeds once
a proper selection is chosen, this is sent to variable Translate pick that just
repeats the choice back to the user done through int 0 being set to the user as
declared on line 64 and sending the validPick a char. After that a computer
choice is done via a random time selection over 5 cases this is set to 1 for the
bool function, the random function picks between all other cases or selections
that may be chosen. After that it goes back into the main code and a if
statement is made to decide the winner of the game, a counter for both the
computer and user was created to count track. After the 3 rounds are finished
another random selection based on time is declared if the user wins the game
declaring a random winning message or if there is a tie.

This program was rewritten with arrays which was not easy as I had trouble understanding the exact purpose and format of blocks and overall array structure, the only difference between this is instead of having individual selections you have an array that then either userPick or computerPick correleates to as seen on multiple lines of the intmain() portion.
*/
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

/////////////////// Prototype Functions - Declared for use
/// later/////////////////////////////
void TranslatePick(int flag_who, char selection);
char ComputerSelectRPSLK(); // Rock-paper-scissors-lizard-spock
char GiveFeedBack();        // Random Winning message
///////////////////////////////// Main ///////////////////////////////////////
int main() {
  ///////////////////////////////// Array //////////////////////////////////////////
  // Five choices from 0 to 4, 0 for 'R' 1 for 'P' etc..
  char validPick[5]{'R', 'P', 'S', 'L', 'K'};
  char userPick; // Used for converting the validPick into the prior as used later.

  // Declare Global Variables
  int counter = 0;     // User Counter
  int CompCounter = 0; // Computer Counter
  char Win;
  //////////////////////////////////////////////////////////////////////////////////
  // For loop for repeating three times, does the other varibles that are
  // included in this aswell.
  for (int i = 0; i < 3; i++) {
    
    // Declare Variables:
    bool isValidPick = false; // Flag controlled while loop for obtaining user
                              // input, set to false for initial selection
    char computerPick; // Randomly selected computer selection for game - time
                       // based
    
    char Win;          // Used to get random Winning message

    // Display Rules of game:
    cout << endl;
    cout << "It's time to play Rock, Paper, Scissors, Lizard, Spock!" << endl;
    cout << "Use R (for Rock), P (for Paper), S (for Scissors), L (for Lizard) "
            "and K (for Spock)."
         << endl;
    cout << endl;

    // Obtain validPick goes until you enter the prior selection and it entered
    // true.
    while (isValidPick == false) {
      cout << "You pick: ";
      cin >> userPick; // Char for K, S, R etc...
      cout << endl;
//Because userPick is selecting a choice of validPick[0] which correleates to R and so on... If this was validPick[5]  == validPick[0] etc... then it results in a core dump as for the 5th value it doesn't have anything set to and hence is where the userpick comes into play at the top of the block. In otherwords the data only went up to [4] or 0,1,2,3,4 and so it had one empty space and this is where the userPick came in to fill that. Also this requires this format as if it was the prior it would imply anything other than a 0 is true even a 'X' 'Y' etc... This is because it is greater than 0 with ASCII code.
      if ((userPick == validPick[0]) || (userPick == validPick[1]) ||
          (userPick == validPick[2]) || (userPick == validPick[3]) ||
          (userPick == validPick[4])) {
        isValidPick = true;
      } else
        cout << "Invalid Selection. Try again." << endl;
    }

    // Repeat selection back to user:
    TranslatePick(0, userPick);

    // Obtain computer selection:
    computerPick = ComputerSelectRPSLK();
    TranslatePick(1, computerPick); // Inform user of computer selection

    // Handout (Part A): Determine the winner of the game.
// We are using validPick for both as it is the same array for both the user and the computer pick. The choice is just specific to the 
   if  ((userPick == validPick[0]) && (computerPick == validPick[2]) ||
        (userPick == validPick[0]) && (computerPick == validPick[3]) ||
        (userPick == validPick[1]) && (computerPick == validPick[4]) ||
        (userPick == validPick[1]) && (computerPick == validPick[0]) ||
        (userPick == validPick[2]) && (computerPick == validPick[1]) ||
        (userPick == validPick[2]) && (computerPick == validPick[3]) ||
        (userPick == validPick[3]) && (computerPick == validPick[4]) ||
        (userPick == validPick[3]) && (computerPick == validPick[1]) ||
        (userPick == validPick[4]) && (computerPick == validPick[0]) ||
        (userPick == validPick[4]) && (computerPick == validPick[2])) {


      /*
      if ((validPick == 'R') && (computerPick == 'S') ||
          (validPick == 'R') && (computerPick == 'L') ||
          (validPick == 'S') && (computerPick == 'P') ||
          (validPick == 'S') && (computerPick == 'L') ||
          (validPick == 'P') && (computerPick == 'R') ||
          (validPick == 'P') && (computerPick == 'K') ||
          (validPick == 'L') && (computerPick == 'K') ||
          (validPick == 'L') && (computerPick == 'P') ||
          (validPick == 'K') && (computerPick == 'R') ||
          (validPick == 'K') && (computerPick == 'S')) {&
  */
      counter++;
      cout << endl;
      cout << "User wins this round." << endl;
    }

     //The old format is still used because if we said validPick[4] == computerPick it would only imply for that case.
    else if (userPick == computerPick) {
      cout << endl;
      cout << "Is a tie!" << endl;
    }

    else {
      cout << endl;
      cout << "Computer wins this round." << endl;
      CompCounter++;
    }
  }

  cout << endl;
  cout << "You won: " << counter << " out of 3" << endl;
  cout << "Computer won: " << CompCounter << " out of 3" << endl;
  if (counter > CompCounter) {
    cout << "User won the game." << endl;
    Win = GiveFeedBack();
    cout << Win << endl;
  }

  if (counter < CompCounter)
    cout << "Computer won the game." << endl;
  if (counter == CompCounter) {
    cout << endl;
    cout << "The game is a tie!" << endl;
  }
}

//////////////////////////////// User-Created Functions
//////////////////////////////////
/* Decription: This function is used to translate the character selection to a
   statement which displayed to the user. Parameters: flag_who is an
   integer which is used to indicate if the computer or the user made    the
   choice. Selection is one of the 5 valid character selections */
void TranslatePick(int flag_who, char selection) {
  // Declare local fnction variables
  string who_text;

  // Identify which statements to insert into the output below
  if (flag_who == 0)
    who_text = "You ";
  else
    who_text = "The Computer ";

  // Display output where the char selection is translated into words:
  if (selection == 'R')
    cout << who_text << "selected Rock." << endl;
  else if (selection == 'P')
    cout << who_text << " selected Paper." << endl;
  else if (selection == 'S')
    cout << who_text << " selected Scissors." << endl;
  else if (selection == 'L')
    cout << who_text << " selected Lizard." << endl;
  else if (selection == 'K')
    cout << who_text << " selected Spock." << endl;
  else // something is wrong
    cout << "Check code for errors. Message from TranslatePick fcn." << endl;
  return;
}
//////////////////////////////////// Random Generated Selection
////////////////////////////////////////////
//   This function is used to make a random character selection in the game
//   Rock, Paper, Scissors, Lizard Spock. Parameters: there are no inputs

char ComputerSelectRPSLK() {
  // Declare Local Variables
  char randPickChar;
  int randPick;

  // Pick a random number from 0 to 4.
  srand(time(NULL));     // Initialize Random seed.
  randPick = rand() % 5; // Gives us 0 to 4
  // cout << randPick; //Debuging tool

  // Assign a random number to letter
  switch (randPick) {
  case 0:
    randPickChar = 'R';
    break;
  case 1:
    randPickChar = 'P';
    break;
  case 2:
    randPickChar = 'S';
    break;
  case 3:
    randPickChar = 'L';
    break;
  case 4:
    randPickChar = 'K';
    break;
  default:
    cout << "Error in the function ComputerSelectRPSLK. " << endl;
  }
  return randPickChar;
}

// Random Win message
char GiveFeedBack() {
  // Declare Local Variables
  char randPickChar;
  int randPick;

  // Pick a random number from 0 to 4.
  srand(time(NULL));     // Initialize Random seed.
  randPick = rand() % 5; // Gives us 0 to 4
  // cout << randPick; //Debuging tool

  // Assign a random number to a cout.
  switch (randPick) {
  case 0:
    cout << "Penny!";
    break;
  case 1:
    cout << "You did it yay!";
    break;
  case 2:
    cout << "To beat the computer is to understand the time solution.";
    break;
  case 3:
    cout << "That was easy!";
    break;
  case 4:
    cout << "Bazinga";
    break;
  default:
    cout << "Error in the function GiveFeedBack. " << endl;
  }
  return randPickChar;
}





















/*
It turns out doing it this way without having a seperate userpick also works 
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

/////////////////// Prototype Functions - Declared for use later/////////////////////////////
void TranslatePick(int flag_who, char selection);
char ComputerSelectRPSLK(); // Rock-paper-scissors-lizard-spock
char GiveFeedBack(); // Random Winning message
///////////////////////////////// Main ///////////////////////////////////////
int main() {
///////////////////////////////// Arrays ///////////////////////////////////////
char userPick[5] {'R', 'P', 'S','L','K'};

  
  //Declare Global Variables
  int counter = 0;        //User Counter
  int CompCounter = 0;    //Computer Counter
  char Win;
//////////////////////////////////////////////////////////////////////////////////
// For loop for repeating three times, does the other varibles that are included in this aswell.
  for (int i = 0; i < 3; i++) {
    // Declare Variables:
  //  char userPick;           // User selection for game
    bool valid_pick = false; // Flag controlled while loop for obtaining user
                             // input, set to false for initial selection
    char computerPick;       // Randomly selected computer selection for game - time based       
    char Win;                // Used to get random Winning message

    // Display Rules of game:
    cout << endl;
    cout << "It's time to play Rock, Paper, Scissors, Lizard, Spock!" << endl;
    cout << "Use R (for Rock), P (for Paper), S (for Scissors), L (for Lizard) "
            "and K (for Spock)."
         << endl;
    cout << endl;

    // Obtain userPick goes until you enter the prior selection and it entered
    // true.
    while (valid_pick == false) {
      cout << "You pick: ";
      cin >> userPick[5]; // Char for K, S, R etc...
      cout << endl;
      if ((userPick[5] == userPick [0]) || (userPick[5] == userPick[1]) || (userPick[5] == userPick[2]) ||
          (userPick[5] == userPick[3]) || (userPick[5] == userPick[4])) {
        valid_pick = true;
      } else
        cout << "Invalid Selection. Try again." << endl;
    }

    // Repeat selection back to user:
    TranslatePick(0, userPick[5]);

    // Obtain computer selection:
    computerPick = ComputerSelectRPSLK();
    TranslatePick(1, computerPick); // Inform user of computer selection

    // Handout (Part A): Determine the winner of the game.
    
    if  ((userPick[5] == userPick [0]) && (computerPick == 'S') ||
        (userPick[5] == userPick [0]) && (computerPick == 'L') ||
        (userPick[5] == userPick [2]) && (computerPick == 'P') ||
        (userPick[5] == userPick [2]) && (computerPick == 'L') ||
        (userPick[5] == userPick [1]) && (computerPick == 'R') ||
        (userPick[5] == userPick [1]) && (computerPick == 'K') ||
        (userPick[5] == userPick [3]) && (computerPick == 'K') ||
        (userPick[5] == userPick [3]) && (computerPick == 'P') ||
        (userPick[5] == userPick [4]) && (computerPick == 'R') ||
        (userPick[5] == userPick [4]) && (computerPick == 'S'))
         {





#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

/////////////////// Prototype Functions - Declared for use later/////////////////////////////
void TranslatePick(int flag_who, char selection);
char ComputerSelectRPSLK(); // Rock-paper-scissors-lizard-spock
char GiveFeedBack(); // Random Winning message
///////////////////////////////// Main ///////////////////////////////////////
int main() {
///////////////////////////////// Arrays ///////////////////////////////////////
char userPick[5] {'R', 'P', 'S','L','K'};

  
  //Declare Global Variables
  int counter = 0;        //User Counter
  int CompCounter = 0;    //Computer Counter
  char Win;
//////////////////////////////////////////////////////////////////////////////////
// For loop for repeating three times, does the other varibles that are included in this aswell.
  for (int i = 0; i < 3; i++) {
    // Declare Variables:
  //  char userPick;           // User selection for game
    bool valid_pick = false; // Flag controlled while loop for obtaining user
                             // input, set to false for initial selection
    char computerPick;       // Randomly selected computer selection for game - time based       
    char Win;                // Used to get random Winning message

    // Display Rules of game:
    cout << endl;
    cout << "It's time to play Rock, Paper, Scissors, Lizard, Spock!" << endl;
    cout << "Use R (for Rock), P (for Paper), S (for Scissors), L (for Lizard) "
            "and K (for Spock)."
         << endl;
    cout << endl;

    // Obtain userPick goes until you enter the prior selection and it entered
    // true.
    while (valid_pick == false) {
      cout << "You pick: ";
      cin >> userPick[5]; // Char for K, S, R etc...
      cout << endl;
      if ((userPick[5] == userPick [0]) || (userPick[5] == userPick[1]) || (userPick[5] == userPick[2]) ||
          (userPick[5] == userPick[3]) || (userPick[5] == userPick[4])) {
        valid_pick = true;
      } else
        cout << "Invalid Selection. Try again." << endl;
    }

    // Repeat selection back to user:
    TranslatePick(0, userPick[5]);

    // Obtain computer selection:
    computerPick = ComputerSelectRPSLK();
    TranslatePick(1, computerPick); // Inform user of computer selection

    // Handout (Part A): Determine the winner of the game.
    
    if  ((userPick[5] == userPick [0]) && (computerPick == 'S') ||
        (userPick[5] == userPick [0]) && (computerPick == 'L') ||
        (userPick[5] == userPick [2]) && (computerPick == 'P') ||
        (userPick[5] == userPick [2]) && (computerPick == 'L') ||
        (userPick[5] == userPick [1]) && (computerPick == 'R') ||
        (userPick[5] == userPick [1]) && (computerPick == 'K') ||
        (userPick[5] == userPick [3]) && (computerPick == 'K') ||
        (userPick[5] == userPick [3]) && (computerPick == 'P') ||
        (userPick[5] == userPick [4]) && (computerPick == 'R') ||
        (userPick[5] == userPick [4]) && (computerPick == 'S'))
         {
    
    /*
    if ((userPick == 'R') && (computerPick == 'S') ||
        (userPick == 'R') && (computerPick == 'L') ||
        (userPick == 'S') && (computerPick == 'P') ||
        (userPick == 'S') && (computerPick == 'L') ||
        (userPick == 'P') && (computerPick == 'R') ||
        (userPick == 'P') && (computerPick == 'K') ||
        (userPick == 'L') && (computerPick == 'K') ||
        (userPick == 'L') && (computerPick == 'P') ||
        (userPick == 'K') && (computerPick == 'R') ||
        (userPick == 'K') && (computerPick == 'S')) {&

      counter++;
      cout << endl;
      cout << "User wins this round." << endl;
    }

    else if (userPick[5] == computerPick) {
      cout << endl;
      cout << "Is a tie!" << endl;
    }

    else {
      cout << endl;
      cout << "Computer wins this round." << endl;
      CompCounter++;
    }
  }
  
  cout << endl;
  cout << "You won: " << counter << " out of 3" << endl;
  cout << "Computer won: " << CompCounter << " out of 3" << endl;
  if (counter > CompCounter) {
    cout << "User won the game." << endl;
    Win = GiveFeedBack();
    cout << Win << endl;
  }

  if (counter < CompCounter)
    cout << "Computer won the game." << endl;
  if (counter == CompCounter){
    cout << endl;
    cout << "The game is a tie!" << endl;
  }
  
}

//////////////////////////////// User-Created Functions ///////////////////////////////
/* 
void TranslatePick(int flag_who, char selection) {
  // Declare local fnction variables
  string who_text;

  // Identify which statements to insert into the output below
  if (flag_who == 0)
    who_text = "You ";
  else
    who_text = "The Computer ";

  // Display output where the char selection is translated into words:
  if (selection == 'R')
    cout << who_text << "selected Rock." << endl;
  else if (selection == 'P')
    cout << who_text << " selected Paper." << endl;
  else if (selection == 'S')
    cout << who_text << " selected Scissors." << endl;
  else if (selection == 'L')
    cout << who_text << " selected Lizard." << endl;
  else if (selection == 'K')
    cout << who_text << " selected Spock." << endl;
  else // something is wrong
    cout << "Check code for errors. Message from TranslatePick fcn." << endl;
  return;
}
//////////////////////////////////// Random Generated Selection /////////////////////////////////////////
//   This function is used to make a random character selection in the game Rock,
//   Paper, Scissors, Lizard Spock. Parameters: there are no inputs

char ComputerSelectRPSLK() {
  // Declare Local Variables
  char randPickChar;
  int randPick;

  // Pick a random number from 0 to 4.
  srand(time(NULL));     // Initialize Random seed.
  randPick = rand() % 5; // Gives us 0 to 4
  // cout << randPick; //Debuging tool

  // Assign a random number to letter
  switch (randPick) {
  case 0:
    randPickChar = 'R';
    break;
  case 1:
    randPickChar = 'P';
    break;
  case 2:
    randPickChar = 'S';
    break;
  case 3:
    randPickChar = 'L';
    break;
  case 4:
    randPickChar = 'K';
    break;
  default:
    cout << "Error in the function ComputerSelectRPSLK. " << endl;
  }
  return randPickChar;
}

// Random Win message
char GiveFeedBack() {
  //Declare Local Variables
  char randPickChar;
  int randPick;
  
  // Pick a random number from 0 to 4.
  srand(time(NULL));     // Initialize Random seed.
  randPick = rand() % 5; // Gives us 0 to 4
  // cout << randPick; //Debuging tool

  // Assign a random number to a cout.
  switch (randPick) {
  case 0:
    cout << "Penny!";
    break;
  case 1:
    cout << "You did it yay!";
    break;
  case 2:
    cout << "To beat the computer is to understand the time solution.";
    break;
  case 3:
    cout << "That was easy!";
    break;
  case 4:
    cout << "Bazinga";
    break;
  default:
    cout << "Error in the function GiveFeedBack. " << endl;
  }
  return randPickChar;
}

*/