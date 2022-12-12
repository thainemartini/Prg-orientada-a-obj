#include "analisepot.h"
#include <iostream>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    //ifstream inputFile;
    //inputFile.open("C:\\Documents/GitHub/Prg-orientada-a-obj/M1.csv");


    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "AnalisePot_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    AnalisePot w;
    w.show();
    return a.exec();
}
