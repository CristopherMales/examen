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
    QList<Datos*> l_datos;
    void calcular();

private slots:
    void on_Registro();
    void cargarDatos();

private:
    Ui::InMaCo *ui;
};
#endif // INMACO_H
