/*
Programmer: Zachary Luevano
Date Finished: 9/30/22
Description: Certainly one of the more complicated programs we've made. Plays a 6 way game of rock paper scissors.

Works by using multiple prototype functions for part is a loop that repeats the entire thing 3 times, second is a while loop that the user has a choice to pick whatever they wish that is connected to a bool function that only proceeds once a proper selection is chosen, this is sent to variable Translate pick that just repeats the choice back to the user done through int 0 being set to the user as declared on line 64 and sending the userpick a char. After that a computer choice is done via a random time selection over 5 cases this is set to 1 for the bool function, the random function picks between all other cases or selections that may be chosen. After that it goes back into the main code and a if statement is made to decide the winner of the game, a counter for both the computer and user was created to count track. After the 3 rounds are finished another random selection based on time is declared if the user wins the game declaring a random winning message or if there is a tie.

*/
// If user = R AND computer pick = S then cout "You won" or R and R is cout "is
// tie."


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
  //Declare Global Variables
  int counter = 0;        //User Counter
  int CompCounter = 0;    //Computer Counter
  char Win;


// For loop for repeating three times, does the other varibles that are included in this aswell.
  for (int i = 0; i < 3; i++) {
    // Declare Variables:
    //char userPick;           // User selection for game
    char userPick[5] {'R','P','S','L','K'};
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
      for (int i = 0; i < 5; i++)
      cout << "You pick: ";
      cin >> userPick; // Char for K, S, R etc...
      cout << endl;

      if ((userPick ['R']) || (userPick ['P']) || (userPick ['S']) ||
          (userPick == 'L') || (userPick == 'K')) {
        valid_pick = true;
      } else
        cout << "Invalid Selection. Try again." << endl;
    }

    // Repeat selection back to user:
    TranslatePick(0, userPick);

    // Obtain computer selection:
    computerPick = ComputerSelectRPSLK();
    TranslatePick(1, computerPick); // Inform user of computer selection

    // Handout (Part A): Determine the winner of the game.
    if ((userPick == 'R') && (computerPick == 'S') ||
        (userPick == 'R') && (computerPick == 'L') ||
        (userPick == 'S') && (computerPick == 'P') ||
        (userPick == 'S') && (computerPick == 'L') ||
        (userPick == 'P') && (computerPick == 'R') ||
        (userPick == 'P') && (computerPick == 'K') ||
        (userPick == 'L') && (computerPick == 'K') ||
        (userPick == 'L') && (computerPick == 'P') ||
        (userPick == 'K') && (computerPick == 'R') ||
        (userPick == 'K') && (computerPick == 'S')) {
      counter++;
      cout << endl;
      cout << "User wins this round." << endl;
    }

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
  if (counter == CompCounter){
    cout << endl;
    cout << "The game is a tie!" << endl;
  }
  
}

//////////////////////////////// User-Created Functions ///////////////////////////////
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
