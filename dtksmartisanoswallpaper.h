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
    DLabel *Smartisan = new DLabel();
private:
    QWidget *s=new QWidget;
    void setTheme(DGuiApplicationHelper::ColorType);

signals:
    void refresh_changed();

public slots:
    void refresh_ui();



};

#endif // DTKSMARTISANOSWALLPAPER_H
