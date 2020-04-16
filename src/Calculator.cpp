#include <Calculator.h>
#include "./ui_Calculator.h"
#include "lib.h"

double firstNumber = 0;
bool firstDigitIns = false;
using namespace MathFuncs;


Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    this->setWindowTitle("Calculator 2020");


    ui->Display->setText(QString::number(firstNumber));
    QPushButton *numButtons[10];
    for(int i = 0 ;i < 10; i++)
    {
        QString butName = "NumButton" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(digitPressed()));
    }

    connect(ui->AddButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->SubButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->DivButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->MulButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->ExpButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->RootButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->FactButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    
    ui->AddButton->setCheckable(true);
    ui->SubButton->setCheckable(true);
    ui->DivButton->setCheckable(true);
    ui->MulButton->setCheckable(true);
    ui->ExpButton->setCheckable(true);
    ui->RootButton->setCheckable(true);
    ui->FactButton->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::digitPressed()
{
    QPushButton *button = (QPushButton *) sender();

    double displayNumber;
    QString newDisplay;

    if ( ! firstDigitIns )
    {
        displayNumber = button->text().toDouble();
        firstDigitIns = true;
    }
    else
    {
        displayNumber = ( ui->Display->text() + button->text()).toDouble();
    }


    newDisplay = QString::number(displayNumber,'g',16);
    ui->Display->setText(newDisplay);
}

//point button
void Calculator::on_pointButton_released()
{
    ui->Display->setText(ui->Display->text() + ".");
}

//clear button
void Calculator::on_ClearButton_released()
{
    firstNumber = 0;

    ui->Display->setText("0");

    ui->AddButton->setChecked(false);
    ui->SubButton->setChecked(false);
    ui->DivButton->setChecked(false);
    ui->MulButton->setChecked(false);
    ui->ExpButton->setChecked(false);
    ui->RootButton->setChecked(false);
    ui->FactButton->setChecked(false);
    firstDigitIns = false;

}

//change sign button
void Calculator::on_ChangeSignButton_released()
{
    QPushButton *button = (QPushButton *) sender();

    double displayNumber;
    QString newDisplay;

    if (button->text() == "+/-")
    {
        displayNumber = ui->Display->text().toDouble();
        displayNumber = displayNumber * -1;
        newDisplay = QString::number(displayNumber,'g',16);
        ui->Display->setText(newDisplay);
    }
}
