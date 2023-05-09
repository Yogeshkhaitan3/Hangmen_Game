#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
void hang_man(char);
int checkGuess(char, string, string &);
int tries = 3;
string message = "You have 3 chances!";

int main() {
  char letter;
  string month;
  string months[12] = {"januaury",  "februaury", "march",    "april",
                       "may",       "june",      "july",     "august",
                       "september", "october",   "november", "december"};

  srand(time(NULL));

  int month_number = rand() % 12;
  
  month = months[month_number];
  
  string hide_month(month.length(), 'X');
 

  system("cls");
  while (tries != 0) {
    hang_man('n');
    cout<<"\t\t\t\tThere is you guess a character from name of monthes:"<<endl;
    cout << "\t\t\t\tLife: " << tries << endl;
    cout << "\t\t\t\t" << hide_month << endl;
    cout << "\t\t\t\tGuess A Letter:";
    cin >> letter;
    system("cls");

    if (checkGuess(letter, month, hide_month) == 0) {
      message = "Incorrect Letter!";
      tries--;
    } else {
      message = "Nice! Correct Guess";
    }

    if (hide_month == month) {
      message = "You're Free!";
      hang_man('f');
      cout << "\t\t\t\tLife: " << tries << endl;
      cout << "\t\t\t\tThe Month is:" << month << endl;
      break;
    }
  }
  if (tries == 0) {
    message = "YOU ARE Hanged!";
    hang_man('h');
    cout << "\t\t\t\tLife: " << tries << endl;
    cout << "\t\t\t\tThe Month is:" << month << endl;
  }
  return 0;
}
void hang_man(char state) {
  string head_string ="|";
  string stage="====";
  if(state=='f'){
    head_string=" ";
  }
  if(state=='h'){
    stage="    ";
  }
  cout << "\t\t\t\t_______________________" << endl;
  cout << "\t\t\t\t         "<<head_string<<"           | " << endl;
  cout << "\t\t\t\t         O           | " << endl;
  cout << "\t\t\t\t        / \\          | "<< "\t           " << message << endl;
  cout << "\t\t\t\t         |           | "<< "\t          / " << endl;
  cout << "\t\t\t\t        / \\          |           O   " << endl;
  cout << "\t\t\t\t    ==="<<stage<<"====      |          / \\" << endl;
  cout << "\t\t\t\t    |         |      |           |" << endl;
  cout << "\t\t\t\t    |         |      |     ___  / \\" << endl;
  cout << "\t\t\t\t===========================|=|=============" << endl;
}
int checkGuess(char guess, string real_month, string &hidden_month) {
  int matches = 0;
  int len = real_month.length();
  for (int i = 0; i < len; i++) {
    if (guess == hidden_month[i]) {
      return 0;
    }
    if (guess == real_month[i]) {
      hidden_month[i] = guess;
      matches++;
    }
  }
  return matches;
}