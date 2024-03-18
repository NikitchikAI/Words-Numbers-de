<<<<<<< HEAD
#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QToolButton>

class MyButton : public QToolButton
{
public:
    explicit MyButton(const QString& text, QWidget *parent = nullptr);

    QSize sizeHint() const override;
};

#endif // MYBUTTON_H
=======
#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QToolButton>

class MyButton : public QToolButton
{
public:
    explicit MyButton(const QString& text, QWidget *parent = nullptr);

    QSize sizeHint() const override;
};

#endif // MYBUTTON_H
>>>>>>> 95b5017db28af4af24456be456ed91d3ec8a5e05
