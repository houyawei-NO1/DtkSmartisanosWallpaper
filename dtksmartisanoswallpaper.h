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
#include <QSize>
DWIDGET_USE_NAMESPACE
#ifndef DTKSMARTISANOSWALLPAPER_H
#define DTKSMARTISANOSWALLPAPER_H


class DtkSmartisanosWallpaper : public DMainWindow
{
    Q_OBJECT
public:
    DtkSmartisanosWallpaper(DMainWindow *parent = nullptr);
    QPixmap setpnglabel(const QString &szUrl);
    bool downIURL_to_picture(const QString &url, const QString &fileName);
    DLabel *pic1 = new DLabel;
    DLabel *pic2 = new DLabel;
    DLabel *pic3 = new DLabel;
    QString sorts = "";
    int pagenum = 0;
    QString author[50];
    QString id[50];
    QString url_png[50];
    DLabel *name = new DLabel;
    DLabel *auther = new DLabel;
    DLabel *source = new DLabel;
    DLabel *des = new DLabel;
    DLabel *pagelabel = new DLabel;
    DPushButton *filelocation = new DPushButton();
    QString PathName,current_File;
private:
    QWidget *s=new QWidget;
    void setTheme(DGuiApplicationHelper::ColorType);

signals:
    void refresh_changed();

public slots:
    void refresh_ui();



};

#endif // DTKSMARTISANOSWALLPAPER_H
