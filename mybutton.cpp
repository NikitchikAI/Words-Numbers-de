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
