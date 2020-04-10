#include "Calculator.h"
#include "ui_calc.h"

double calcVal = 0.0;
int currSign = -1;
QString prevString = "";
enum MATH{ADD, SUB, MUL, DIV, EXP, ROOT, FACT};

calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i = 0 ;i < 10; i++)
    {
        QString butName = "NumButton" + QString::number(i);
        numButtons[i] = calc::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
    connect(ui->AddButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->SubButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->DivButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->MulButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->ExpButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->RootButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->FactButton, SIGNAL(released()), this, SLOT(MathButtonPressed()));

}

calc::~calc()
{
    delete ui;
}

void calc::NumPressed()
{
    QPushButton *button = (QPushButton *) sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0))
    {
        ui->Display->setText(butVal);
        calcVal = butVal.toDouble();
    }
    else if(currSign == -1)
    {
        double fullVal = displayVal.toDouble() * 10 + butVal.toDouble();
        ui->Display->setText(QString::number(fullVal,'g',16));
        calcVal = fullVal;
        return;
    }
    if(currSign != -1)
    {
        double fullVal = displayVal.toDouble() * 10 + butVal.toDouble();
        prevString += butVal;
        ui->Display->setText(prevString);
    }
}
void calc::MathButtonPressed()
{
    QPushButton *button = (QPushButton *) sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/",Qt::CaseInsensitive) == 0)
    {
        currSign = DIV;
        prevString = QString::number(calcVal) + "/";
        ui->Display->setText(prevString);
    }
    else if (QString::compare(butVal, "*",Qt::CaseInsensitive) == 0)
    {
        currSign = MUL;
        prevString = QString::number(calcVal) + "*";
        ui->Display->setText(prevString);
    }
    else if (QString::compare(butVal, "-",Qt::CaseInsensitive) == 0)
    {
        currSign = SUB;
        prevString = QString::number(calcVal) + "-";
        ui->Display->setText(prevString);
    }
    else if (QString::compare(butVal, "+",Qt::CaseInsensitive) == 0)
    {
        currSign = ADD;
        prevString = QString::number(calcVal) + "+";
        ui->Display->setText(prevString);
    }
    else if (QString::compare(butVal, "x!",Qt::CaseInsensitive) == 0)
    {
        currSign = FACT;
        prevString = QString::number(calcVal) + "!";
        ui->Display->setText(prevString);
    }
    else if (QString::compare(butVal, "√",Qt::CaseInsensitive) == 0)
    {
        currSign = ROOT;
        prevString = QString::number(calcVal) + "√";
        ui->Display->setText(prevString);
    }
    else if (QString::compare(butVal, "x^z",Qt::CaseInsensitive) == 0)
    {
        currSign = EXP;
        prevString = QString::number(calcVal) + "^";
        ui->Display->setText(prevString);
    }
}


