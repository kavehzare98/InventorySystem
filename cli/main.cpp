#include "Inventory.hpp"
#include <iostream>
using namespace std;

// Function prototypes
int getMetalChoice();
int getOperationChoice();
void showBalance(int metalChoice, Inventory &inv);
void showInventoryView(Inventory &inv);

int main() {
  const int START_AMT = 20;
  int metalChoice;
  int operationChoice;
  int exchangeAmount;

  Inventory inv = Inventory(START_AMT, START_AMT, START_AMT);

  cout << "Welcome to Kaveh's inventory system:" << endl;

  while (true) {
    showInventoryView(inv);

    metalChoice = getMetalChoice();
    if (metalChoice == NO_METAL) {
      break;
    }

    showBalance(metalChoice, inv);

    operationChoice = getOperationChoice();
    if (operationChoice == QUIT) {
      break;
    }

    cout << "What's the amount: ";
    cin >> exchangeAmount;

    int balance = -1;

    if (operationChoice == WITHDRAW) {
      balance = inv.withdraw(metalChoice, exchangeAmount);
    } else if (operationChoice == DEPOSIT) {
      balance = inv.deposit(metalChoice, exchangeAmount);
    }

    if (balance != -1) {
      cout << "FINAL BALANCE: " << balance << endl;
    } else {
      cout << "INVALID OPERATION!" << endl;
    }
  }

  return 0;
}

int getMetalChoice() {
  int choice;

  cout << "Please choose which metal you want to work with:\n"
       << "  1. Gold\n"
       << "  2. Silver\n"
       << "  3. Copper\n"
       << "  4. Quit\n"
       << "Metal Choice: ";

  cin >> choice;
  return choice;
} // end of getMetalChoice()

int getOperationChoice() {
  int choice;
  cout << "Choose what you want to do:\n"
       << "  1. Withdraw\n"
       << "  2. Deposit\n"
       << "  3. Quit\n"
       << "Your choice: ";
  cin >> choice;
  return choice;
} // end of getOperationChoice()

void showBalance(int metalChoice, Inventory &inv) {
  bool validChoice = true;
  int balance = -1;

  switch (metalChoice) {
  case GOLD:
    balance = inv.getGoldBalance();
    break;
  case SILVER:
    balance = inv.getSilverBalance();
    break;
  case COPPER:
    balance = inv.getCopperBalance();
    break;
  default:
    validChoice = false;
    cout << "INVALID CHOICE ERROR!\n";
    break;
  }

  if (validChoice) {
    cout << "Here is your current balance: " << balance << endl;
  }
} // end of showBalance()

void showInventoryView(Inventory &inv) {
  cout << "\n|=========||====================|\n";
  cout <<   "|  Metal  ||  Current Amount    |\n";
  cout <<   "|---------||--------------------|\n";
  cout <<   "|  Gold   ||\t"   << inv.getGoldBalance()   << "\t\t|\n";
  cout <<   "|---------||--------------------|\n";
  cout <<   "|  Silver ||\t" << inv.getSilverBalance() << "\t\t|\n";
  cout <<   "|---------||--------------------|\n";
  cout <<   "|  Copper ||\t" << inv.getCopperBalance() << "\t\t|\n";
  cout <<   "|=========||====================|\n\n";
}

