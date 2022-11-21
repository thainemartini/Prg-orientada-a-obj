#ifndef ANALISEPOT_H
#define ANALISEPOT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AnalisePot; }
QT_END_NAMESPACE

class AnalisePot : public QMainWindow
{
    Q_OBJECT

public:
    AnalisePot(QWidget *parent = nullptr);
    ~AnalisePot();

private:
    Ui::AnalisePot *ui;
};
#endif // ANALISEPOT_H
