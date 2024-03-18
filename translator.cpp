#include "translator.h"

#include <QGridLayout>
#include <mybutton.h>
#include <QDebug>

Translator::Translator()
{
    m_dislay_up    = new QLineEdit();
    m_display_down = new QLineEdit();
    m_display_warning      = new QLabel;
    mainLayout = new QGridLayout;

    m_display_down->setReadOnly(true);
    QFont font = m_dislay_up->font();
    font.setPointSize(font.pointSize() + 3);
    m_dislay_up->setFont(font);
    m_display_down->setFont(font);
    m_display_warning->setFont(font);
    numbers = {
        {"null", 0},
        {"und", 0},
        {"ein", 1},
        {"zwei", 2},
        {"drei", 3},
        {"vier", 4},
        {"funf", 5},
        {"sech", 6},
        {"sieben", 7},
        {"acht", 8},
        {"neun", 9},
        {"zehn", 10},
        {"elf", 11},
        {"zwolf", 12},
        {"dreizehn", 13},
        {"vierzehn", 14},
        {"funfzehn", 15},
        {"sechzehn", 16},
        {"siebzehn", 17},
        {"achtzehn", 18},
        {"neunzehn", 19},
        {"zwanzig", 20},
        {"dreizig", 30},
        {"vierzig", 40},
        {"funfzig", 50},
        {"sechzig", 60},
        {"siebzig", 70},
        {"achtzig", 80},
        {"neunzig", 90},
        {"hundert", 100}
    };


    MyButton* wrdTNumber = createButton("Translate", SLOT(wordToNumberClicked()));

    wrdTNumber->setFont(font);

    mainLayout->addWidget(m_dislay_up, 0, 0, 6, 120);
    mainLayout->addWidget(m_display_warning, 12, 0, 6, 1);
    mainLayout->addWidget(m_display_down, 18, 0, 6, 120);
    mainLayout->addWidget(wrdTNumber, 6 , 0, 6, 120);
    setLayout(mainLayout);

    setWindowTitle("Translator");

}

Translator::~Translator()
{
    delete m_dislay_up;
    delete m_display_down;
    delete m_display_warning;
    delete mainLayout;
}

MyButton *Translator::createButton(const QString &text, const char *member)
{
    MyButton* btn = new MyButton(text);
    connect(btn, SIGNAL(clicked()), this, member);
    return btn;
}

std::vector<std::string> Translator::input(const std::string& s)
{
    std::vector<std::string> str;
    std::string word;
    for (size_t i = 0; i != s.size(); ++i) {
        if (s[i] == ' ' && !word.empty()) {
            str.push_back(word);
            word.erase();
        }
        else {
            word += s[i];
        }
    }
    if (!word.empty()) {
        str.push_back(word);
        word.erase();
    }
    return str;

}

void Translator::warningPrint(const std::string &warning_message)
{
    qDebug() << QString::fromStdString(warning_message);
    m_display_warning->setText("Warning! " + QString::fromStdString(warning_message));

}

bool Translator::sequenceCorrect(const std::string& first, const std::string& second, size_t i) {
    if (first == second) {
        warningPrint("Oшибка последовательности. Числа одинакового формата не могут стоять подряд");
        return false;
    }
    if (second == "hundert" && i == 3) {
        warningPrint("Ошибка последовательности. В числе не может быть двух 'hundert'");
        return false;
    }
    if ((numbers[first] % 10 == 0 && numbers[first] > 0 &&  numbers[first] < 91) || (numbers[first] > 10 && numbers[first] < 20)) {
        warningPrint("Ошибка последовательности. После десятков и чисел типа 11-19 ничего стоять не может");
        return false;
    }
    if ((numbers[first] >= 0 && numbers[first] < 10) && (first != "und") && (second != "hundert") && (second != "und")) {
        warningPrint("Ошибка последовательности. После единиц могут стоять только сотни или слово 'und'");
        return false;
    }
    if (second == "und" && i == str.size() - 1) {
        warningPrint("Ошибка последовательности. После слова 'und' должны стоять десятки");
        return false;
    }
    if (first == "und" && !(numbers[second] % 10 == 0 && numbers[second] > 0 &&  numbers[second] < 91)) {
        warningPrint("Ошибка последовательности. После слова 'und' должны стоять десятки");
        return false;
    }
    return true;
}

unsigned short int Translator::sumNumbers(const std::vector<std::string> &str, size_t str_size)
{
    unsigned short int result = 0;
    if (str.empty()) {
        qDebug() << "Warning! пустая строка\n";
        m_display_warning->setText("Warning! пустая строка\n");
        return 0;
    }
    if (str_size > 5) {
        warningPrint("Запись числа (0-999) может состоять максимум из 5 слов");
        return 0;
    }
    else {
        if (!numbers.count(str[0])) {
            qDebug() << "Не правильно введено слово:" << str[0];
            m_display_warning->setText("Не правильно введено слово: " + QString::fromStdString(str[0]));
            m_display_down->setText("Warning!");
                return 0;
        }
        if (str[0] == "hundert") {
            warningPrint("Перед словом 'hundert' должно стоять число единичного формата");
            return 0;
        }
        else if (str[0] == "und") {
            warningPrint("Перед словом 'und' должно стоять число единичного формата");
            return 0;
        }
        result = numbers[str[0]];
        for (size_t i = 1; i != str_size; ++i) {
            if (!numbers.count(str[i])) {
                qDebug() << "Не правильно введено слово:" << str[i];
                m_display_warning->setText("Не правильно введено слово: " + QString::fromStdString(str[i]));
                m_display_down->setText("Warning!");
                return 0;
            }
            if (!sequenceCorrect(str[i-1], str[i], i)) {
                return 0;
            }
            if (str[i] == "hundert") { result *= 100; }
            else { result += numbers[str[i]]; }
        }
    }
    return result;
}

void Translator::wordToNumberClicked() {
    m_display_down->clear();
    m_display_warning->clear();
    str = input(m_dislay_up->text().toStdString());
    m_display_down->setText(QString::number(sumNumbers(str, str.size())));
    }


