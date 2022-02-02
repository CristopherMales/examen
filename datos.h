#ifndef DATOS_H
#define DATOS_H
#include <QObject>

class Datos : public QObject
{
    Q_OBJECT
        Q_PROPERTY(QString fecha READ fecha WRITE setFecha)
        Q_PROPERTY(float altura READ altura WRITE setAltura)
            Q_PROPERTY(float peso READ peso WRITE setPeso)
private:
    QString d_fecha;
    float d_altura;
    float d_peso;

public:
    explicit Datos(QObject *parent = nullptr);
    Datos(QString fecha, float altura, float peso);

    QString fecha();
    void setFecha(QString fecha);

    float altura();
    void setAltura(float altura);

    float peso();
    void setPeso(float peso);
};

#endif // DATOS_H
