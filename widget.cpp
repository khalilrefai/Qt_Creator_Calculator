#include "widget.h"
#include "./ui_widget.h"
#include <QIcon>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Set Icons & Colors
    this->setWindowTitle("Calculator");
    this->setFixedSize(350, 500);
    QIcon appIcon(":/resources/app.png");
    this->setWindowIcon(appIcon);

    QIcon deleteIcon(":/resources/delete.png");
    ui->pushButton_delete->setIcon(deleteIcon);

    QIcon binIcon(":/resources/bin.png");
    ui->pushButton_clear->setIcon(binIcon);

    ui->screenLabel->setStyleSheet("QLabel { border: 2px solid grey; }");
    ui->historyLabel->setStyleSheet("QLabel { color : grey; }");

    // Connections
    QObject::connect(ui->pushButton_0, &QPushButton::clicked, this, clickPushButton_0);
    QObject::connect(ui->pushButton_1, &QPushButton::clicked, this, clickPushButton_1);
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, clickPushButton_2);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, this, clickPushButton_3);
    QObject::connect(ui->pushButton_4, &QPushButton::clicked, this, clickPushButton_4);
    QObject::connect(ui->pushButton_5, &QPushButton::clicked, this, clickPushButton_5);
    QObject::connect(ui->pushButton_6, &QPushButton::clicked, this, clickPushButton_6);
    QObject::connect(ui->pushButton_7, &QPushButton::clicked, this, clickPushButton_7);
    QObject::connect(ui->pushButton_8, &QPushButton::clicked, this, clickPushButton_8);
    QObject::connect(ui->pushButton_9, &QPushButton::clicked, this, clickPushButton_9);
    QObject::connect(ui->pushButton_delete, &QPushButton::clicked, this, clickPushButton_delete);
    QObject::connect(ui->pushButton_clear, &QPushButton::clicked, this, clickPushButton_clear);
    QObject::connect(ui->pushButton_plus, &QPushButton::clicked, this, clickPushButton_plus);
    QObject::connect(ui->pushButton_minus, &QPushButton::clicked, this, clickPushButton_minus);
    QObject::connect(ui->pushButton_divide, &QPushButton::clicked, this, clickPushButton_divide);
    QObject::connect(ui->pushButton_multiply, &QPushButton::clicked, this, clickPushButton_multiply);
    QObject::connect(ui->pushButton_modulo, &QPushButton::clicked, this, clickPushButton_modulo);
    QObject::connect(ui->pushButton_power, &QPushButton::clicked, this, clickPushButton_power);
    QObject::connect(ui->pushButton_dot, &QPushButton::clicked, this, clickPushButton_dot);
    QObject::connect(ui->pushButton_equal, &QPushButton::clicked, this, clickPushButton_equal);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showScreenText()
{
    ui->screenLabel->setText(m_msg);
}

void Widget::showHistoryText()
{
    QString history_msg = "";
    for (int i = 0; i < m_history.size(); i++)
    {
        history_msg += m_history[i] + "\n";
    }
    ui->historyLabel->setText(history_msg);
}

void Widget::clickPushButton_0()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '0';
    }
    m_msg += ui->pushButton_0->text();
    emit showScreenText();
}

void Widget::clickPushButton_1()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '1';
    }
    m_msg += ui->pushButton_1->text();
    emit showScreenText();
}

void Widget::clickPushButton_2()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '2';
    }
    m_msg += ui->pushButton_2->text();
    emit showScreenText();
}

void Widget::clickPushButton_3()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '3';
    }
    m_msg += ui->pushButton_3->text();
    emit showScreenText();
}

void Widget::clickPushButton_4()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '4';
    }
    m_msg += ui->pushButton_4->text();
    emit showScreenText();
}

void Widget::clickPushButton_5()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '5';
    }
    m_msg += ui->pushButton_5->text();
    emit showScreenText();
}

void Widget::clickPushButton_6()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '6';
    }
    m_msg += ui->pushButton_6->text();
    emit showScreenText();
}

void Widget::clickPushButton_7()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '7';
    }
    m_msg += ui->pushButton_7->text();
    emit showScreenText();
}

void Widget::clickPushButton_8()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '8';
    }
    m_msg += ui->pushButton_8->text();
    emit showScreenText();
}

void Widget::clickPushButton_9()
{
    if (m_lastOp == '=')
    {
        m_msg = "";
        m_lastOp = '9';
    }
    m_msg += ui->pushButton_9->text();
    emit showScreenText();
}

void Widget::clickPushButton_delete()
{
    m_msg.chop(1);
    m_lastOp = 'd';
    emit showScreenText();
}

void Widget::clickPushButton_clear()
{
    m_msg = "";
    m_lastOp = 'c';
    emit showScreenText();
}

void Widget::clickPushButton_plus()
{
    if (!m_msg.isEmpty() && !m_msg[m_msg.size() - 1].isDigit()) m_msg.chop(1);
    if (m_msg.isEmpty()) m_msg = '0';
    m_msg += ui->pushButton_plus->text();
    m_lastOp = '+';
    emit showScreenText();
}

void Widget::clickPushButton_minus()
{
    if (!m_msg.isEmpty() && !m_msg[m_msg.size() - 1].isDigit()) m_msg.chop(1);
    if (m_msg.isEmpty()) m_msg = '0';
    m_msg += ui->pushButton_minus->text();
    m_lastOp = '-';
    emit showScreenText();
}

void Widget::clickPushButton_divide()
{
    if (!m_msg.isEmpty() && !m_msg[m_msg.size() - 1].isDigit()) m_msg.chop(1);
    if (m_msg.isEmpty()) m_msg = '0';
    m_msg += ui->pushButton_divide->text();
    m_lastOp = '/';
    emit showScreenText();
}

void Widget::clickPushButton_multiply()
{
    if (!m_msg.isEmpty() && !m_msg[m_msg.size() - 1].isDigit()) m_msg.chop(1);
    if (m_msg.isEmpty()) m_msg = '0';
    m_msg += ui->pushButton_multiply->text();
    m_lastOp = '*';
    emit showScreenText();
}

void Widget::clickPushButton_modulo()
{
    if (!m_msg.isEmpty() && !m_msg[m_msg.size() - 1].isDigit()) m_msg.chop(1);
    if (m_msg.isEmpty()) m_msg = '0';
    m_msg += ui->pushButton_modulo->text();
    m_lastOp = '%';
    emit showScreenText();
}

void Widget::clickPushButton_power()
{
    if (!m_msg.isEmpty() && !m_msg[m_msg.size() - 1].isDigit()) m_msg.chop(1);
    if (m_msg.isEmpty()) m_msg = '0';
    m_msg += ui->pushButton_power->text();
    m_lastOp = '^';
    emit showScreenText();
}

void Widget::clickPushButton_dot()
{
    if (!m_msg.isEmpty() && !m_msg[m_msg.size() - 1].isDigit()) m_msg.chop(1);
    if (m_msg.isEmpty()) m_msg = '0';
    m_msg += ".";
    m_lastOp = '.';
    emit showScreenText();
}

void Widget::clickPushButton_equal()
{
    if (m_msg.isEmpty()) m_msg = "0";
    compute_sum();
    m_lastOp = '=';
    emit showScreenText();
    emit showHistoryText();
}

void Widget::compute_sum()
{
    std::set<QChar> st = {'+', '-', '*', '/', '%', '^'};

    std::vector<QString> vec;
    std::vector<QChar> vec_ops;
    QString temp = "";

    for (int i = 0; i < m_msg.size(); ++i)
    {
        QChar ch = m_msg[i];

        if (st.find(ch) != st.end())
        {
            if (!temp.isEmpty())
            {
                vec.push_back(temp);
                temp.clear();
            }
            vec_ops.push_back(ch);
        }
        else
        {
            temp += ch;
        }
    }

    if (!temp.isEmpty())
    {
        vec.push_back(temp);
    }

    // First pass: handle * and /
    for (int i = 0; i < vec_ops.size(); )
    {
        if (vec_ops[i] == '*' || vec_ops[i] == '/' || vec_ops[i] == '%' || vec_ops[i] == '^')
        {
            bool isNumber1, isNumber2;
            double num1 = vec[i].toDouble(&isNumber1);
            double num2 = vec[i + 1].toDouble(&isNumber2);

            if (!isNumber1 || !isNumber2)
            {
                m_msg = "Error: Incorrect Number";
                return;
            }

            double result = 0.0;
            if (vec_ops[i] == '*')
                result = num1 * num2;
            else if (vec_ops[i] == '/')
            {
                if (num2 == 0)
                {
                    m_msg = "Error: Can't divide by 0";
                    return;
                }
                result = num1 / num2;
            }
            else if (vec_ops[i] == '%')
            {
                result = std::fmod(num1, num2);
            }
            else if (vec_ops[i] == '^')
            {
                result = std::pow(num1, num2);
            }

            vec[i] = QString::number(result, 'g', 15);
            vec.erase(vec.begin() + i + 1);
            vec_ops.erase(vec_ops.begin() + i);
        }
        else
        {
            ++i;
        }
    }

    // Second pass: handle + and -
    bool isNumber;
    double sum = vec[0].toDouble(&isNumber);
    if (!isNumber)
    {
        m_msg = "Error: Incorrect Number";
        return;
    }

    int j = 0;
    for (int i = 1; i < vec.size(); ++i, ++j)
    {
        bool isNumber;
        double num = vec[i].toDouble(&isNumber);

        if (!isNumber)
        {
            m_msg = "Error: Incorrect Number";
            return;
        }

        if (vec_ops[j] == '+')
            sum += num;
        else if (vec_ops[j] == '-')
            sum -= num;
        else
        {
            m_msg = "Error :( ";
            return;
        }
    }

    m_msg = QString::number(sum, 'g', 15);
    if (m_history.size() < 9)
    {
        m_history.push_back(m_msg);
    }
    else
    {
        m_history.erase(m_history.begin());
        m_history.push_back(m_msg);
    }
}
