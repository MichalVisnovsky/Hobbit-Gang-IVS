#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void digitPressed();
    void helpPressed();
    void MathButtonPressed();
    void on_pointButton_released();
    void on_ClearButton_released();
    void on_ChangeSignButton_released();
    void on_EqualsButton_released();
};
#endif // CALCULATOR_H
