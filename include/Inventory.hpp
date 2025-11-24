#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#define MAX_CAPACITY 100

enum Metals { GOLD = 1, SILVER, COPPER };
enum Operation { WITHDRAW = 1, DEPOSIT, QUIT };

class Inventory {
private:
  int m_goldBalance;
  int m_silverBalance;
  int m_copperBalance;

public:
  Inventory();
  Inventory(int gold, int silver, int copper);

  int getGoldBalance() const;
  int getSilverBalance() const;
  int getCopperBalance() const;

  void setGoldBalance(int newBalance);
  void setSilverBalance(int newBalance);
  void setCopperBalance(int newBalance);

  int withdraw(int metalType, int withdrawAmount); // returns the final balance
  int deposit(int metalType, int depositAmount); // returns the final balance
  bool validateTransaction(int type, int amount);
};
#endif
