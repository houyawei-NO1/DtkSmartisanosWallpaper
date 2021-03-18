#include <QWidget>
#include <DMainWindow>
#include <DGuiApplicationHelper>
#include <DLabel>
#include <DPushButton>
#include <DTextEdit>
#include <DGroupBox>
#include <DComboBox>
#include <DCheckBox>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <DDialog>
#include <QNetworkReply>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QDateTime>
#include <QJsonArray>
#include <QTimer>
#include <DScrollArea>
DWIDGET_USE_NAMESPACE
#ifndef DTKSMARTISANOSWALLPAPER_H
#define DTKSMARTISANOSWALLPAPER_H


class DtkSmartisanosWallpaper : public DMainWindow
{
    Q_OBJECT
public:
    DtkSmartisanosWallpaper(DMainWindow *parent = nullptr);

private:
    QWidget *s=new QWidget;
    void setTheme(DGuiApplicationHelper::ColorType);

signals:
//    void refresh_changed();
private slots:
//    void refresh_ui();

};

#endif // DTKSMARTISANOSWALLPAPER_H
