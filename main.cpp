#include "inmaco.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traducion;
        // Solicitando al usuario que seleccione un idioma
        QStringList idiomas;
        idiomas << "Ruso" << "Español";
        QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                   "Idioma",
                                   "Seleccione un idioma",
                                   idiomas);

        if (idiomaSeleccionado == "Ruso"){
            traducion.load(":/IMC_ru_RU.qm");
            a.installTranslator(&traducion);
        }

    InMaCo w;
    w.show();
    return a.exec();
}
