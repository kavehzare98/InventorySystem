#include "MainWindow.h"
#include "Inventory.hpp"

#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(Inventory* inventory, QWidget* parent)
    : QMainWindow(parent)
    , m_inventory(inventory)
{
    setupUi();
    refreshTable();
}

void MainWindow::setupUi() {
    auto *central = new QWidget(this);
    auto *vLayout = new QVBoxLayout(central);

    m_table = new QTableWidget(this);
    m_table->setColumnCount(2);
    QStringList headers { "Metal", "Balance" };
    m_table->setHorizontalHeaderLabels(headers);
    m_table->horizontalHeader()->setStretchLastSection(true);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_table->setSelectionMode(QAbstractItemView::SingleSelection);
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 3 fixed rows: Gold, Silver, Copper
    m_table->setRowCount(3);
    m_table->setItem(0, 0, new QTableWidgetItem("Gold"));
    m_table->setItem(1, 0, new QTableWidgetItem("Silver"));
    m_table->setItem(2, 0, new QTableWidgetItem("Copper"));

    auto *buttonsLayout = new QHBoxLayout;
    m_depositButton = new QPushButton("Deposit", this);
    m_withdrawButton = new QPushButton("Withdraw", this);

    buttonsLayout->addWidget(m_depositButton);
    buttonsLayout->addWidget(m_withdrawButton);
    buttonsLayout->addStretch();

    vLayout->addWidget(m_table);
    vLayout->addLayout(buttonsLayout);

    setCentralWidget(central);
    setWindowTitle("Inventory Balances");

    connect(m_depositButton, &QPushButton::clicked,
            this, &MainWindow::onDeposit);
    connect(m_withdrawButton, &QPushButton::clicked,
            this, &MainWindow::onWithdraw);
}

void MainWindow::refreshTable() {
    // Column 1 (index 1) holds balances
    m_table->setItem(0, 1, new QTableWidgetItem(
        QString::number(m_inventory->getGoldBalance())));
    m_table->setItem(1, 1, new QTableWidgetItem(
        QString::number(m_inventory->getSilverBalance())));
    m_table->setItem(2, 1, new QTableWidgetItem(
        QString::number(m_inventory->getCopperBalance())));
}

int MainWindow::currentMetalType() const {
    int row = m_table->currentRow();
    if (row < 0)
        return GOLD; // default if nothing selected

    switch (row) {
    case 0: return GOLD;
    case 1: return SILVER;
    case 2: return COPPER;
    default: return GOLD;
    }
}

void MainWindow::onDeposit() {
    int metal = currentMetalType();

    bool ok = false;
    int amount = QInputDialog::getInt(
        this,
        "Deposit",
        "Amount to deposit:",
        0,         // default
        0,         // min
        1000000,   // max
        1,         // step
        &ok
    );

    if (!ok || amount <= 0)
        return;

    int newBalance = m_inventory->deposit(metal, amount);
    if (newBalance < 0) {
        QMessageBox::warning(this, "Invalid Deposit",
                             "Deposit would exceed maximum capacity.");
    }

    refreshTable();
}

void MainWindow::onWithdraw() {
    int metal = currentMetalType();

    bool ok = false;
    int amount = QInputDialog::getInt(
        this,
        "Withdraw",
        "Amount to withdraw:",
        0,
        0,
        1000000,
        1,
        &ok
    );

    if (!ok || amount <= 0)
        return;

    int newBalance = m_inventory->withdraw(metal, amount);
    if (newBalance < 0) {
        QMessageBox::warning(this, "Invalid Withdrawal",
                             "Insufficient balance or below zero.");
    }

    refreshTable();
}

