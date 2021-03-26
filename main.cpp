#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DApplicationSettings>
#include <dtksmartisanoswallpaper.h>
DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
   // DApplication::loadDXcbPlugin();
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    DApplication a(argc, argv);
    a.setOrganizationName("deepin");
    a.setApplicationName("dtk_SmartisanOS壁纸工具");
    a.setApplicationVersion("0.2");
    a.setProductIcon(QIcon(":/images/hyw.ico"));
    a.setProductName("SmartisanOS壁纸工具");
    a.setApplicationDescription("这是一个DTK_SmartisanOS壁纸工具");

    a.loadTranslator();
    a.setApplicationDisplayName(QCoreApplication::translate("Main", "DtkSerialport"));

    // 保存程序的窗口主题设置
    DApplicationSettings as;
    Q_UNUSED(as)

   // DMainWindow w;
   //w.show();

  DtkSmartisanosWallpaper d;
  d.show();


   // Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
