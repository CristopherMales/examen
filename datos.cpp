#include "datos.h"

QString Datos::fecha(){
 return d_fecha;
}
void Datos::setFecha(QString fecha){
 d_fecha = fecha;
}

float Datos::altura(){
 return d_altura;
}
void Datos::setAltura(float altura){
 d_altura= altura;
}

float Datos::peso(){
 return d_peso;
}
void Datos::setPeso(float peso){
 d_peso= peso;
}

Datos::Datos(QObject *parent) : QObject(parent)
{
    d_fecha = "";
    d_altura = 0.00;
    d_peso = 0.00;
}

Datos::Datos(QString fecha, float altura, float peso)
{
    d_fecha = fecha;
    d_altura = altura;
    d_peso = peso;
}
