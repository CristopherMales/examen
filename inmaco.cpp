#include "inmaco.h"
#include "ui_inmaco.h"


InMaCo::InMaCo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InMaCo)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),
           this,SLOT(on_Registro()));
}

InMaCo::~InMaCo()
{
    delete ui;
}

void InMaCo::on_Registro()
{
       QString nombre_archivo = QCoreApplication::applicationDirPath() + "datos.txt";
       QFile archivo(nombre_archivo);
       if (!archivo.exists()){
           return;
       }
       QString fecha = ui->inputFecha->text();
       float altura = ui->inputAltura->value();
       float peso = ui->inputPeso->value();

       Datos *dt1 = new Datos(fecha, altura, peso);
       QString line = dt1->fecha() + ","+ dt1->altura()+","+dt1->peso();
       if(archivo.open(QFile::WriteOnly | QIODevice::Text)){

           QTextStream out(&archivo);

       out<<line<<endl;
       }

       archivo.close();

}
