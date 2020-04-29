/**
* @file calculator.h
* @author BORIS BOBOCKY, MICHAL VISNOVSKY
* @date 12.04.2020
*
* @brief Functions for funcionality of calculator
*/


#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

/**
* @class Calculator
*/
class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    
    /**
    * @brief calculator destructor
    * 
    * @pre ui has to be inicialized
    * @post calculator no longer exist
    */
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:

    /**
    * @brief Function to check if the pressed button is digit
    * 
    * @pre Any button has to be pressed
    * @post Value of pressed button is showed on display
    */
    void digitPressed();
    
    /**
    * @brief Function to display file, which contains instructions for using calculator 
    * 
    * @pre Button 'Help' has to be pressed
    * @post User is redirected to github, manual is displayed
    */
    void helpPressed();
    
     /**
     * @brief Addition of numbers
     *
     * @pre One button must be pressed to make a mathematical operation
     * @post Pressed button value is set checked true and waits equal button to be pressed
     *
     */
    void MathButtonPressed();
    
    /**
    * @brief Function to display '.'
    * 
    * @pre Any number button has to be pressed
    * @post Given number is displayed with decimal point
    */
    void on_pointButton_released();
    
    /**
    * @brief Function to set all buttons and variables to to default values
    * 
    * @post Buttons are set to default values
    */
    void on_ClearButton_released();
    
     /**
    * @brief Function to change the sign of the given value from positive to negative and vice versa
    * 
    * @pre Button of number, which you want to change has to be pressed
    * @post Given number has opposite sign
    */
    void on_ChangeSignButton_released();
    
    /**
    * @brief Function to call a functions from lib.h, depending on wich button was pressed 
    * 
    * @pre Button '=' has to be pressed
    * @post The math function from lib.h is executed, after then the button set to default
    */
    void on_EqualsButton_released();
};
#endif // CALCULATOR_H

/**
* @endif
*/
