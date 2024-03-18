<<<<<<< HEAD
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <mybutton.h>
#include <vector>
#include <string>
#include <map>
#include <QGridLayout>

class Translator : public QWidget
{
    Q_OBJECT

public:
    Translator();
    ~Translator();

private slots:
    void wordToNumberClicked();

private:
    MyButton* createButton(const QString& text, const char* member);
    QLineEdit* m_dislay_up;
    QLineEdit* m_display_down;
    QLabel*    m_display_warning;
    QGridLayout* mainLayout;
    std::vector<std::string> input(const std::string &s);
    void warningPrint(const std::string& warning_message);
    unsigned short int sumNumbers(const std::vector<std::string>& str, size_t str_size);
    std::vector<std::string> str;
    std::map<std::string, int> numbers;
    bool sequenceCorrect(const std::string& first, const std::string& second, size_t i);
};

#endif // TRANSLATOR_H
=======
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <mybutton.h>
#include <vector>
#include <string>
#include <map>

class Translator : public QWidget
{
    Q_OBJECT

public:
    Translator();
    ~Translator();

private slots:
    void wordToNumberClicked();

private:
    MyButton* createButton(const QString& text, const char* member);
    QLineEdit* m_dislay_up;
    QLineEdit* m_display_down;
    QLabel*    m_display_warning;
    std::vector<std::string> input(const std::string &s);
    void warningPrint(const std::string& warning_message);
    unsigned short int sumNumbers(const std::vector<std::string>& str, size_t str_size);
    std::vector<std::string> str;
    std::map<std::string, int> numbers;
    bool sequenceCorrect(const std::string& first, const std::string& second, size_t i);
};

#endif // TRANSLATOR_H
>>>>>>> 95b5017db28af4af24456be456ed91d3ec8a5e05
