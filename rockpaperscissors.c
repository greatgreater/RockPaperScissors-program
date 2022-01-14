#include <stdio.h>

#include <stdlib.h> //this header is for the rand() function which will be needed for the computer to generate a random number choice

#include <time.h> //this header is needed for the srand() function which will be needed for the computer to generate different number choices everytime


//global variables
int playerwincount   = 0;  //These are set as global variables because they allow functions to display the scoreboard.
int computerwincount = 0; //Without these global variables, the scoreboard would have to be manually typed everytime after every round.

int ChoiceGenerator(void);
int StartMessage(void);
void Borders(void);
void Result(int val);
char PlayAgain(void);

void main(void) {

  //declaration
  // 1 = rock, 2 = paper, 3 = scissors
  char programrestart = 'y';
  int playerchoiceinput, playerchoice, computerchoice;
  int round, wincount;
  int choiceconfirm = 0;

  //welcome
  printf("Welcome to George's Rock, Paper, Scissors program!\n\n");
  while (programrestart == 'y') {
    round = 1;
    wincount = StartMessage();

    //player input
    while ((playerwincount < wincount) && (computerwincount < wincount)) {
      computerchoice = ChoiceGenerator();
      while (choiceconfirm == 0) { //This while-loop is necessary for data validation when the user inputs a value
        Borders();
        printf("ROUND %d\n\n", round);
        printf("Rock = 1, Paper = 2, Scissors = 3\n\n");
        printf("Rock, paper, or scissors?: ");
        scanf("%d", &playerchoiceinput);
        fflush(stdin);

        if (playerchoiceinput == 1) {
          playerchoiceinput = 0; //playerchoiceinput has to be declared as 0. If not, from round 2 onwards
                                //if the user were to input a letter isntead of a number, the program would not
                               //recognize it as an invalid value, and will take the previous input instead.
          printf("You have chosen rock!\n\n");
          printf("Push Enter to continue.");
          getchar();
          printf("\n");
          playerchoice  = 1;
          round         = round + 1;
          choiceconfirm = 1; //choiceconfirm = 1 will escape the while-loop for data validation.
        } else if (playerchoiceinput == 2) {
          playerchoiceinput = 0;
          printf("You have chosen paper!\n\n");
          printf("Push Enter to continue.");
          getchar();
          printf("\n");
          playerchoice  = 2;
          round         = round + 1;
          choiceconfirm = 1;
        } else if (playerchoiceinput == 3) {
          playerchoiceinput = 0;
          printf("You have chosen scissors!\n\n");
          printf("Push Enter to continue.");
          getchar();
          printf("\n");
          playerchoice  = 3;
          round         = round + 1;
          choiceconfirm = 1;
        } else printf("Invalid input! Please try again.\n");

      }
      //computer chooses rock
      if (computerchoice == 1) {
        if (playerchoice == 2) {
          printf("The computer chose rock!");
          Result(1);
          choiceconfirm = 0;
        } else if (playerchoice == 1) {
          printf("The computer chose rock too!");
          Result(0);
          choiceconfirm = 0;
        } else if (playerchoice == 3) {
          printf("Oh no! The computer chose rock!");
          Result(2);
          choiceconfirm = 0;
        }

      }
      //computer chooses paper
      if (computerchoice == 2) {
        if (playerchoice == 1) {
          printf("Oh no! The computer chose paper!");
          Result(2);
          choiceconfirm = 0;
        } else if (playerchoice == 2) {
          printf("The computer chose paper too!");
          Result(0);
          choiceconfirm = 0;
        } else if (playerchoice == 3) {
          printf("The computer chose paper!");
          Result(1);
          choiceconfirm = 0;
        }
      }
      //computer chooses scissors
      if (computerchoice == 3) {
        if (playerchoice == 1) {
          printf("The computer chose scissors!");
          Result(1);
          choiceconfirm = 0;
        } else if (playerchoice == 2) {
          printf("Oh no! The computer chose scissors!");
          Result(2);
          choiceconfirm = 0;
        } else if (playerchoice == 3) {
          printf("The computer chose scissors too!");
          Result(0);
          choiceconfirm = 0;
        }
      }
      if (playerwincount == wincount) {
        wincount = 0; //The wincount has to be reset to 0, otherwise program will keep continuing 
                     //regardless of whether the player chooses yes or no.
        round    = round - 1;
        printf("\n\n\n#####Congratulations! You are the winner of the game which lasted %d rounds.#####\n\n\n", round);
        programrestart = PlayAgain();
        Borders();
      } else if (computerwincount == wincount) {
        wincount = 0; //refer to the lines above
        round = round - 1;
        printf("\n\n\n#####You lost the game which lasted %d rounds. Better luck next time!#####\n\n\n", round);
        programrestart = PlayAgain();
        Borders();
      }

    }

  }
  //end of main program
  printf("\nThanks for playing!!\n\n\n");
}
char PlayAgain(void) {
  playerwincount = 0;
  computerwincount = 0;
  char restart;
  int restartcondition = 0;
  while (restartcondition == 0) {
    printf("Do you want to play again? (y for yes, n for no): ");
    fflush(stdin);
    scanf("%c", &restart);
    if (restart == 'y' || restart == 'n') {
      restartcondition = 1;
      return restart;
    } else printf("\n\nInvalid input! Please try again.\n\n");
  }
}
int StartMessage(void) {
  int NumberofRounds = 0;
  int condition;
  char YesNo = 'n';

  printf("To start playing,");

  while (NumberofRounds < 1 || YesNo == 'n') {
    printf(" indicate how many rounds need to be won in order to win: ");
    scanf("%d", &NumberofRounds);
    fflush(stdin);
    condition = 0; // It is important that condition is declared as 0 here so that it can get into the while-loop 
    // which asks if the user is sure of their input.

    if (NumberofRounds < 1) {
      printf("Invalid input! Please try again.\n\n");
      printf("Okay,");
    } else if (NumberofRounds >= 1) {

      while (condition == 0) {
        printf("\nAre you sure? Input y for yes, n for no: ");
        scanf("%c", &YesNo);
        fflush(stdin);
        if (YesNo == 'y') {
          printf("\nOkay, first to %d wins!", NumberofRounds);
          condition = 1;
          return NumberofRounds;
        }
        if (YesNo == 'n') {
          condition = 1; // If condition is not declared as 1, it will be in the while-loop which asks if the user is sure
          // until the user chooses yes, which does not allow the user to make changes.
          printf("Okay,");
        } else if (YesNo != 'n') {
          printf("Invalid input! Please try again.\n");
        }
      }
    }
  }

  printf("\nOkay, first to %d wins!", NumberofRounds);
}

void Borders(void) {
  printf("\n===========================================================================\n");
}

void Result(int val) {
  if (val == 0) {
    printf("\n(SCORES: PLAYER - %d , COMPUTER - %d)", playerwincount, computerwincount);
    printf("\n\n#####It's a draw!#####\n\n");
    printf("Push Enter to continue.");
    getchar();
    system("cls");
  } else if (val == 1) {
    playerwincount = playerwincount + 1;
    printf("\n(SCORES: PLAYER - %d, COMPUTER - %d)", playerwincount, computerwincount);
    printf("\n\n#####You win!#####\n\n");
    printf("Push Enter to continue.");
    getchar();
    system("cls");
  } else if (val == 2) {
    computerwincount = computerwincount + 1;
    printf("\n(SCORES: PLAYER - %d, COMPUTER - %d)", playerwincount, computerwincount);
    printf("\n\n#####You lost! The computer wins.#####\n\n");
    printf("Push Enter to continue.");
    getchar();
    system("cls");
  }
}

int ChoiceGenerator(void) {
  srand(time(NULL));
  int choice;
  choice = 1 + (rand() % 3);
  return choice;
}
