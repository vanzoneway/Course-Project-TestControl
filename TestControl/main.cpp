#include "menuwindow.h"
#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Set the app style sheet
    QFile styleSheetFile("../GUITheme/SyNet.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    MenuWindow w;
    w.show();
    return a.exec();
}
