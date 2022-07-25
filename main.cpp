#include "conversor.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traducion;
    QStringList idiomas;
    idiomas << "Chino" << "Japones" << "Ruso" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);
    if (idiomaSeleccionado == "Chino"){
        traducion.load(":/Conversor-Temperatura_cn.qm");
    }else if (idiomaSeleccionado == "Japones"){
        traducion.load(":/Conversor-Temperatura_jp.qm");
    }else if(idiomaSeleccionado == "Ruso"){
        traducion.load(":Conversor-Temperatura_ru.qm");
    }
    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }
    Conversor w;
    w.show();
    return a.exec();
}
