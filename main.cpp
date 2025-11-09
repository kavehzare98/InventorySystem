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
int getMetalChoice();

int main() {

  Inventory inv;
  int metalChoice;
  int balance;
  cout << "Metal Choice: ";
  cin >> metalChoice;

  print("Here is your current balance: ");

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
      println("INVALID CHOICE ERROR!");
      break;
  }

  println("{0}",balance);

  int operationChoice = getOperationChoice();

  print("What's the amount: ");
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
      println("INVALID OPERATION ERROR!");
      break;
  }

  print("FINAL BALANCE: ");
  println("{}", balance);
  println("Goodbye");

  return 0;
}


int getMetalChoice()
{
  int choice;
  println("Please choose which metal you want to work with:\n 1. Gold\n 2. Silver\n 3. Copper");
  print("Metal Choice: ");
  cin >> choice;
  return choice;
}


int getOperationChoice()
{
  int choice;
  print("Choose what you want to do:\n  1. Withdraw\n  2. Deposit\n  3. Quit\nYour choice: ");
  cin >> choice;
  return choice;
}
