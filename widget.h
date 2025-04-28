#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void showScreenText();
    void showHistoryText();
    void clickPushButton_0();
    void clickPushButton_1();
    void clickPushButton_2();
    void clickPushButton_3();
    void clickPushButton_4();
    void clickPushButton_5();
    void clickPushButton_6();
    void clickPushButton_7();
    void clickPushButton_8();
    void clickPushButton_9();

    void clickPushButton_delete();
    void clickPushButton_clear();
    void clickPushButton_plus();
    void clickPushButton_minus();
    void clickPushButton_divide();
    void clickPushButton_multiply();
    void clickPushButton_modulo();
    void clickPushButton_power();
    void clickPushButton_dot();
    void clickPushButton_equal();

    void compute_sum();

private:
    Ui::Widget *ui;

    QString m_msg = "";
    std::vector<QString> m_history = {};
    QChar m_lastOp = '?';
};
#endif // WIDGET_H
