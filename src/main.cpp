#include <iostream>
#include <print>
#include "Inventory.hpp"
using std::println, std::cin, std::print;

// Function prototypes
int getOperationChoice();
int getMetalChoice();
void showBalance(int metalChoice, Inventory &inv);

int main() {

  const int START_AMT = 20;
  int metalChoice;
  int operationChoice;
  int exchangeAmount;

  Inventory inv = Inventory(START_AMT, START_AMT, START_AMT);

  println("Welcome to Kaveh's inventory system:");
  metalChoice = getMetalChoice();
  showBalance(metalChoice, inv);

  operationChoice = getOperationChoice();

  print("What's the amount: ");
  cin >> exchangeAmount;

  int balance;
  if (operationChoice == WITHDRAW) {
    balance = inv.withdraw(metalChoice, exchangeAmount);
    println("FINAL BALANCE: {}\nGoodbye", balance);
  } else if (operationChoice == DEPOSIT) {
    balance = inv.deposit(metalChoice, exchangeAmount);
    println("FINAL BALANCE: {}\nGoodbye", balance);
  } else {
    println("Chose QUIT!");
  }

  return 0;
}

int getMetalChoice() {
  int choice;
  println("Please choose which metal you want to work with:\n 1. Gold\n 2. "
          "Silver\n 3. Copper");
  print("Metal Choice: ");
  cin >> choice;
  return choice;
} // end of getMetalChoice()

int getOperationChoice() {
  int choice;
  print("Choose what you want to do:\n  1. Withdraw\n  2. Deposit\n  3. "
        "Quit\nYour choice: ");
  cin >> choice;
  return choice;
} // end of getOperationChoice()

void showBalance(int metalChoice, Inventory &inv) {
  bool validChoice = true;
  int balance;
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
  default: {
    validChoice = false;
    println("INVALID CHOICE ERROR!");
    break;
           }
  }
  if (validChoice) {
    print("Here is your current balance: ");
    println("{0}", balance);
  }
} // end of showBalance()
