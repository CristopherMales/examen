#ifndef INMACO_H
#define INMACO_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include "datos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InMaCo; }
QT_END_NAMESPACE

class InMaCo : public QMainWindow
{
    Q_OBJECT

public:
    InMaCo(QWidget *parent = nullptr);
    ~InMaCo();
    Datos dt;
private slots:
    void on_Registro();

private:
    Ui::InMaCo *ui;
};
#endif // INMACO_H
