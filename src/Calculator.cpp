#include <calculator.h>
#include "./ui_calculator.h"
#include "lib.h"
#include <QtCore>
#include <QDesktopServices>
#include <QApplication>

double firstNumber = 0;
double keepnumber =0;
bool firstDigitIns = false;
bool checked = false;
using namespace MathFuncs;


Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    this->setWindowTitle("Hobbit Gang Calculator");

    ui->Display->setReadOnly(true);
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
    connect(ui->LogButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    connect(ui->HelpButton, SIGNAL(released()), this, SLOT(helpPressed()));

    ui->AddButton->setCheckable(true);
    ui->SubButton->setCheckable(true);
    ui->DivButton->setCheckable(true);
    ui->MulButton->setCheckable(true);
    ui->ExpButton->setCheckable(true);
    ui->RootButton->setCheckable(true);
    ui->FactButton->setCheckable(true);
    ui->LogButton->setCheckable(true);
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
    ui->LogButton->setChecked(false);
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
        newDisplay = QString::number(displayNumber,'g',15);
        ui->Display->setText(newDisplay);
    }
}

//equals button
void Calculator::on_EqualsButton_released()
{
    double displayNumber, secondNumber;
    secondNumber = ui->Display->text().toDouble();
    QString newDisplay;
    firstDigitIns = false;

    if(ui->AddButton->isChecked())
    {
        displayNumber = OurMathFuncs::Add(firstNumber, secondNumber);
        newDisplay = QString::number(displayNumber,'g',16);
        ui->Display->setText(newDisplay);
        ui->AddButton->setChecked(false);

    }

    else if(ui->SubButton->isChecked())
    {
        displayNumber = OurMathFuncs::Subtract(firstNumber, secondNumber);
        newDisplay = QString::number(displayNumber,'g',16);
        ui->Display->setText(newDisplay);
        ui->SubButton->setChecked(false);
    }

    else if(ui->DivButton->isChecked())
    {
        if(secondNumber == 0)
        {
            ui->Display->setText("Syntax error");
            return;
        }
        displayNumber = OurMathFuncs::Divide(firstNumber, secondNumber);
        newDisplay = QString::number(displayNumber,'g',16);
        ui->Display->setText(newDisplay);
        ui->DivButton->setChecked(false);
    }

    else if(ui->MulButton->isChecked())
    {
        displayNumber = OurMathFuncs::Multiply(firstNumber, secondNumber);
        newDisplay = QString::number(displayNumber,'g',16);
        ui->Display->setText(newDisplay);
        ui->MulButton->setChecked(false);
    }

    else if(ui->ExpButton->isChecked())
    {
        if(secondNumber!=(int)secondNumber)
        {
            ui->Display->setText("Syntax error");
            return;
        }
        if (secondNumber < 0)
        {
            ui->Display->setText("Syntax error");
            return;
        }
        displayNumber = OurMathFuncs::Exponent(firstNumber, secondNumber);
        newDisplay = QString::number(displayNumber,'g',16);
        ui->Display->setText(newDisplay);
        ui->ExpButton->setChecked(false);
    }

    else if(ui->RootButton->isChecked())
    {
        if(firstNumber!=(int)firstNumber)
        {
            ui->Display->setText("Syntax error");
            return;
        }
        if (secondNumber < 0 || firstNumber < 0)
        {
            ui->Display->setText("Syntax error");
            return;
        }
        displayNumber = OurMathFuncs::Root(secondNumber, firstNumber);
        newDisplay = QString::number(displayNumber,'g',6);
        ui->Display->setText(newDisplay);
        ui->RootButton->setChecked(false);
    }

    else if(ui->FactButton->isChecked())
    {
        if(keepnumber != 0)
        {
            firstNumber = keepnumber;
        }
        if(firstNumber!=(int)firstNumber)
        {
            ui->Display->setText("Syntax error");
            return;
        }
        if (firstNumber < 0)
        {
            ui->Display->setText("Syntax error");
            return;
        }
        displayNumber = OurMathFuncs::Factorial(firstNumber);
        newDisplay = QString::number(displayNumber,'g',16);
        ui->Display->setText(newDisplay);
        ui->FactButton->setChecked(false);
        checked = false;
        keepnumber = 0;
    }
    else if(ui->LogButton->isChecked())
    {
        if(keepnumber != 0)
        {
            firstNumber = keepnumber;
        }
        if (firstNumber <= 0)
        {
            ui->Display->setText("Syntax error");
            return;
        }
        displayNumber = OurMathFuncs::Logarithm(firstNumber);
        newDisplay = QString::number(displayNumber,'g',16);
        ui->Display->setText(newDisplay);
        ui->LogButton->setChecked(false);
        checked = false;
        keepnumber = 0;
    }
}

//Math buttons
void Calculator::MathButtonPressed()
{
    ui->AddButton->setChecked(false);
    ui->SubButton->setChecked(false);
    ui->DivButton->setChecked(false);
    ui->MulButton->setChecked(false);
    ui->ExpButton->setChecked(false);
    ui->RootButton->setChecked(false);
    ui->FactButton->setChecked(false);
    ui->LogButton->setChecked(false);

    QPushButton * button = (QPushButton*) sender();

    firstNumber = ui->Display->text().toDouble();
    button->setChecked(true);
    if (ui->FactButton->isChecked())
    {
        if(checked)
        {
            ui->Display->setText(ui->Display->text());
        }
        else
        {
            ui->Display->setText(ui->Display->text() + "!");
            keepnumber = firstNumber;
            checked = true;
        }
    }
    if (ui->LogButton->isChecked())
    {
        if(checked)
        {
            ui->Display->setText(ui->Display->text());
        }
        else
        {
            ui->Display->setText( "log("+ ui->Display->text() + ")");
            keepnumber = firstNumber;
            checked = true;
        }
    }

    firstDigitIns = false;
}
void Calculator::helpPressed()
{

    QDesktopServices::openUrl(QUrl( "https://www.youtube.com/"));

}


