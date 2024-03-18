<<<<<<< HEAD
#include "mybutton.h"

MyButton::MyButton(const QString &text, QWidget *parent) : QToolButton(parent)
{
    setText(text);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

}

QSize MyButton::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
=======
#include "mybutton.h"

MyButton::MyButton(const QString &text, QWidget *parent) : QToolButton(parent)
{
    setText(text);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

}

QSize MyButton::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
>>>>>>> 95b5017db28af4af24456be456ed91d3ec8a5e05
