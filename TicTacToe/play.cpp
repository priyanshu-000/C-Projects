#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "play.hpp"

  string player1;
  string player2;
  int player_position;
  int turn = 1;
  bool player1_win=false;
  bool player2_win=false;
  vector<string> value_v = {" ","1","2","3","4","5","6","7","8","9"};
  vector<string> value = {" ","1","2","3","4","5","6","7","8","9"};

void main_loop() {

  introduction();
  
  toss();
  
  player_turn();

  rematch();

  system("clear");

}

void position_check1() {
   
   board();
   cout << "Player " << turn << " Turn : \n";
   cout << "\nEnter your position : ";
   cin >> player_position;
   if(player_position<10) {
   if(value[player_position]!="⊙" && value[player_position]!="✖") {
      value[player_position]=player1;
    }
    else {
      system("clear");
      cout << "OOPS! That position is already occupied.\nEnter again!\n";
      position_check1();
    }
   }

   else {
      system("clear");
      cout << "\n\nThere is only 9 positions. The position you enetered is not available\nEnter again!\n";
      position_check1();
   }
}

void position_check2() {

   board();
   cout << "Player " << turn << " Turn : \n";
   cout << "\nEnter your position : ";
   cin >> player_position;
   if(player_position<10) {
   if(value[player_position]!="⊙" && value[player_position]!="✖") {
      value[player_position]=player2;
    }
    else {
      system("clear");
      cout << "OOPS! That position is already occupied.\nEnter again!\n";
      position_check1();
    }
   }

   else {
      system("clear");
      cout << "\n\nThere is only 9 positions. The position you enetered is not available\nEnter again!\n";
      position_check1();
   }
}

void toss() {
   srand(time(NULL));

   if(rand() % 2 == 0) {
   player1="⊙"; player2="✖";
   }
   else {
   player1="✖"; player2="⊙";
   }
   cout << "\n" << "Player 1 is " << player1; cout << "\t\t" << "Player 2 is " <<player2 << "\n\n";
  }

void player_turn() {

   while (player1_win!=true && player2_win!=true && draw()!=true) {
      position_check1();
      is_player1_winner();
      system("clear");
      end_game();
      turn++;

    if(player1_win!=true && draw()!=true) {
      system("clear");
      position_check2();
      is_player2_winner();
      system("clear");
      end_game();
    }
    turn--;
   }
   
}

bool draw() {
   bool draw = true;
   for(int i=1; i<10; i++) {
      if(value[i]==value_v[i]) {
         draw = false;
      }
   }
   return draw;
}

void end_game() {

  if (player1_win==true || player2_win==true) {
    system("clear");
    cout << "You Win!\n";
  }
  else if (draw()==true) {
    system("clear");
    cout << "There's a tie!\n";
  }

}

void rematch() {
   char choice;
   cout << "\nDo you want a rematch!\n";
   cout << "\nEnter Y to get a rematch\n";
   cout << "Enter N to quit\n\n";
   cout << "Y/N : "; cin >> choice;
   
   if(choice=='y') {
      player1_win=false; player2_win=false; value=value_v; turn=1;
      main_loop();
   }
   else if (choice!='y' && choice!='n') {
      cout << "\nI don't know, what you wanna do?\n";
      rematch();
   }
}

void introduction() {
  std::cout << "Press [Enter] to Start :[Enter]: ";
  std::cin.ignore();
  system("clear");
  cout << "\n=====================================================================\n";
  cout << "Welcome to the fun of tic tac toe || It would be ✖ or It would be ⊙ !\n";
  cout << "=====================================================================\n\n";
  board();
  cout << "\nThe following number located onto board is position to select.\n";
  
  cout << "\nPress enter to toss for who will be the ✖ and who will be the ⊙\n";
  cin.ignore();
  system("clear");
}

void board() {
 
    std::cout << "     |     |      \n";
 
    std::cout << "  " << value[1] << "  |  " << value[2] << "  |  " << value[3] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << value[4] << "  |  " << value[5] << "  |  " << value[6] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << value[7] << "  |  " << value[8] << "  |  " << value[9] << "\n";
    std::cout << "     |     |      \n";
 
    std::cout << "\n";
}

void is_player1_winner() {

  if(value[1]==player1 && value[2]==player1 && value[3]==player1) {
     player1_win=true; 
  }
  if(value[4]==player1 && value[5]==player1 && value[6]==player1) {
     player1_win=true; 
  }
  if(value[7]==player1 && value[8]==player1 && value[9]==player1) {
     player1_win=true; 
  }
  if(value[1]==player1 && value[4]==player1 && value[7]==player1) {
     player1_win=true; 
  }
  if(value[2]==player1 && value[5]==player1 && value[8]==player1) {
     player1_win=true; 
  }
  if(value[3]==player1 && value[6]==player1 && value[9]==player1) {
     player1_win=true; 
  }
  if(value[1]==player1 && value[5]==player1 && value[9]==player1) {
     player1_win=true; 
  }
  if(value[3]==player1 && value[5]==player1 && value[7]==player1) {
     player1_win=true; 
  }

}

void is_player2_winner() {

  if(value[1]==player2 && value[2]==player2 && value[3]==player2) {
     player2_win=true; 
  }
  if(value[4]==player2 && value[5]==player2 && value[6]==player2) {
     player2_win=true; 
  }
  if(value[7]==player2 && value[8]==player2 && value[9]==player2) {
     player2_win=true; 
  }
  if(value[1]==player2 && value[4]==player2 && value[7]==player2) {
     player2_win=true; 
  }
  if(value[2]==player2 && value[5]==player2 && value[8]==player2) {
     player2_win=true; 
  }
  if(value[3]==player2 && value[6]==player2 && value[9]==player2) {
     player2_win=true; 
  }
  if(value[1]==player2 && value[5]==player2 && value[9]==player2) {
     player2_win=true; 
  }
  if(value[3]==player2 && value[5]==player2 && value[7]==player2) {
     player2_win=true; 
  }

}