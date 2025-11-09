#include <print>
#include <iostream>
using std::println, std::cin, std::print;

const int SIZE = 20;

struct Inventory {
  int goldBalance {10};
  int silverBalance {15};
  int copperBalance {3};
};

enum Metals { GOLD=1, SILVER, COPPER};
enum Operation {WITHDRAW=1, DEPOSIT, QUIT};

// Function prototypes
int getOperationChoice();

int main() {

  Inventory inv;

  println("Welcome to my crib");
  cout << "Welcome to my shitty inventory system:" << endl;
  cout << "Please choose which metal you want to work with: " << endl;

  cout << "1. Gold" << endl
       << "2. Silver" << endl
       << "3. Copper" << endl << endl;

  int metalChoice;
  int balance;
  cout << "Metal Choice: ";
  cin >> metalChoice;

  cout << "Here is your current balance: ";

  switch (metalChoice) {
    case GOLD:
      balance = inv.goldBalance;
      break;
    case SILVER:
      balance = inv.silverBalance;
      break;
    case COPPER:
      balance = inv.copperBalance;
      break;
    default:
      cout << "INVALID CHOICE ERROR!" << endl;
      break;
  }

  cout << balance << endl;

  int operationChoice = getOperationChoice();

  int exchangeAmount;
  cout << "What's the amount: ";
  cin >> exchangeAmount;

  switch (operationChoice)
  {
    case WITHDRAW:
    {
      if (metalChoice == GOLD) {
        inv.goldBalance -= exchangeAmount;
        balance = inv.goldBalance;
      } else if (metalChoice == SILVER) {
        inv.silverBalance -= exchangeAmount;
        balance = inv.silverBalance;
      } else if (metalChoice == COPPER) {
        inv.copperBalance -= exchangeAmount;
        balance = inv.copperBalance;
      }
      break;
    }
    case DEPOSIT:
    {
      if (metalChoice == GOLD) {
        inv.goldBalance += exchangeAmount;
        balance = inv.goldBalance;
      } else if (metalChoice == SILVER) {
        inv.silverBalance += exchangeAmount;
        balance = inv.silverBalance;
      } else if (metalChoice == COPPER) {
        inv.copperBalance += exchangeAmount;
        balance = inv.copperBalance;
      }
      break;
    }
    case QUIT:
      break;
    default:
      cout << "INVALID OPERATION ERROR!" << endl;
      break;
  }

  cout << "Here is your final balance: " << balance << endl;
  cout << "Goodbye" << endl;

  return 0;
}


int getOperationChoice() {

  int choice;
  cout << "Choose what you want to do: " << endl
       << "  1. Withdraw" << endl
       << "  2. Deposit"  << endl
       << "  3. Quit"     << endl
       << "Your choice: ";
  cin >> choice;
  return choice;
}
