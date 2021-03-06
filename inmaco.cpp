#include "inmaco.h"
#include "ui_inmaco.h"
#include <QObject>

InMaCo::InMaCo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InMaCo)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(on_Registro()));
    cargarDatos();
}

InMaCo::~InMaCo()
{
    delete ui;
}

void InMaCo::on_Registro()
{

QString nombre_archivo = QDir::home().absolutePath()+"/registro_datos.txt";

QFile archivo(nombre_archivo);

QString fecha = ui->inputFecha->text();
float altura = ui->inputAltura->value();
float peso = ui->inputPeso->value();

Datos *dt1 = new Datos(fecha, altura, peso);
QString line = dt1->fecha() + ","+ QString::number(dt1->altura(),'f',2)+","+QString::number(dt1->peso(),'f',2);
archivo.open(QIODevice::ReadWrite | QIODevice::Append);
QTextStream out(&archivo);
out<<line<<endl;
archivo.close();
cargarDatos();
}

void InMaCo::calcular(){
    float value_max = 0;
    float value_min= 600;
    float icm = 0;

    //Calcular Max Min
    for (int var = 0; var < l_datos.length(); ++var) {
        if(l_datos.at(var)->peso() > value_max){
               value_max = l_datos.at(var)->peso();
        }
        if(l_datos.at(var)->peso() < value_min){
               value_min = l_datos.at(var)->peso();
        }
    }

    //Calcular ICM
    float c_altura = l_datos.at(l_datos.length()-1)->altura();
    float c_peso = l_datos.at(l_datos.length()-1)->peso();
    icm = c_peso / (c_altura*c_altura);
    if(icm< 18.5){
        ui->lblicm->setText("Bajo de Peso");
        ui->lblicm->setStyleSheet("QLabel { color : blue; }");
    }else if(icm>=18.5 && icm<25){
        ui->lblicm->setText("Normal");
        ui->lblicm->setStyleSheet("QLabel { color : orange; }");
    }else if(icm>=25 && icm<30){
        ui->lblicm->setText("Superior al normal");
        ui->lblicm->setStyleSheet("QLabel { color : green; }");
    }else if(icm>=30){
        ui->lblicm->setText("Obeso");
        ui->lblicm->setStyleSheet("QLabel { color : red; }");
    }


    ui->inputActual->setText(QString::number(l_datos.at(l_datos.length()-1)->peso(),'f',2));
    ui->inputMax->setText(QString::number(value_max,'f',2));
    ui->inputMin->setText(QString::number(value_min,'f',2));
    ui->inputicm->setText(QString::number(icm,'f',2));
    ui->slidericm->setValue(icm);
    ui->lblaltura->setText(QString::number(c_altura,'f',2));
}

void InMaCo::cargarDatos(){
    QString nombre_archivo = QDir::home().absolutePath()+"/registro_datos.txt";
    ui->path->setText(nombre_archivo);
    QFile archivo(nombre_archivo);

    if(archivo.open(QFile::ReadOnly | QIODevice::Text)){
    QTextStream in(&archivo);
    while(!in.atEnd()){
        QStringList line= in.readLine().split(",");
        l_datos.append(new Datos(line.at(0),line.at(1).toFloat(),line.at(2).toFloat()));
    }
    calcular();
    }
    archivo.close();

}



