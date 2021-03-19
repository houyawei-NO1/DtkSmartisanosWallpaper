#include "dtksmartisanoswallpaper.h"
#include <DWidgetUtil>
#include <DSearchEdit>
#include <DTitlebar>

DtkSmartisanosWallpaper::DtkSmartisanosWallpaper(DMainWindow *parent)
    : DMainWindow(parent)
{
    setCentralWidget(s);
    moveToCenter(this);
    DtkSmartisanosWallpaper::resize(1200,700);
    DtkSmartisanosWallpaper::setMinimumSize(1200,700);

    QHBoxLayout *h1layout =new QHBoxLayout(s);
    QVBoxLayout *v1layout = new QVBoxLayout(s);
        QHBoxLayout *pagelayout =new QHBoxLayout(s);
            DComboBox *sortcombobox= new DComboBox;
            sortcombobox->addItem("壁纸分类");
            DLabel *pagelabel = new DLabel;
            pagelabel->setText("第几页");
            DPushButton *firstpage = new DPushButton;
            DPushButton *uppage = new DPushButton;
            DPushButton *downtpage = new DPushButton;
        DScrollArea *piclayout = new DScrollArea(s);
//    QHBoxLayout *h2layout =new QHBoxLayout(s);
    QVBoxLayout *v2layout = new QVBoxLayout(s);
        DLabel *name = new DLabel;
        name->setText("name");
        DLabel *auther = new DLabel;
        auther->setText("auther");
        DLabel *source = new DLabel;
        source->setText("source");
        DLabel *des = new DLabel;
        des->setText("des");
        DLineEdit *locationLineEdit = new DLineEdit;
        DPushButton *download = new DPushButton;

        Smartisan->setAlignment(Qt::AlignHCenter);
       // Smartisan ->setText("Smartisan");
        QImage *img=new QImage;
        img->load(":/images/smartisanos.png");
        Smartisan->setPixmap(QPixmap::fromImage(*img));

      h1layout->addLayout(v1layout);
      h1layout->setStretchFactor(v1layout,5);
      v1layout->addLayout(pagelayout);
      pagelayout->addWidget(sortcombobox);
      pagelayout->addWidget(pagelabel);
      pagelayout->addWidget(firstpage);
      pagelayout->addWidget(uppage);
      pagelayout->addWidget(downtpage);
      v1layout->addWidget(piclayout);

      h1layout->addLayout(v2layout);
      h1layout->setStretchFactor(v2layout,1);
      v2layout->addWidget(name);
      v2layout->addWidget(auther);
      v2layout->addWidget(source);
      v2layout->addWidget(des);
      v2layout->addWidget(locationLineEdit);
      v2layout->addWidget(download);
      v2layout->addWidget(Smartisan);


      refresh_ui();
      connect(this,SIGNAL(refresh_changed()),this,SLOT(refresh_ui()));
}

void DtkSmartisanosWallpaper::refresh_ui()
{
    QNetworkAccessManager manager;
    QNetworkRequest request;
    QString url ="http://wallpaper-api.smartisan.com/app/index.php?r=paperapi/index/list&client_version=2&limit=1&paper_id=0";
    request.setUrl(url);
//    request.setRawHeader("Content-Type", "application/json;charset=utf8");
    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if (reply->error() != QNetworkReply::NoError)
    {
//        return false;
    }
//    QFile file(fileName);

    QByteArray receive =reply->readAll();
    qDebug()<<"receive:"<<receive;
    delete reply;

    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(receive, &jsonError);  // 转化为 JSON 文档
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (doucment.isObject()) {  // JSON 文档为对象
            QJsonObject object = doucment.object();  // 转化为对象

            if (object.contains("code")) {
                QJsonValue value = object.value("code");
                if (value.isDouble()) {
                    int strName =  value.toVariant().toInt();
                    qDebug() << "code : " << strName;
                }
             }

            if (receive.contains("data")) {
                       QJsonValue value = object.value("data");
                       if (value.isArray()) {
                            QJsonArray array = value.toArray();
                            QJsonObject obj = array.at(0).toObject();

                            if (obj.contains("author")) {
                                 QJsonValue value = obj.value("author");
                                    if (value.isString()) {
                                        QString author = value.toString();
                                        qDebug() << "author : " << author;
                                     }
                             }

                            if (obj.contains("id")) {
                                 QJsonValue value = obj.value("id");
                                    if (value.isString()) {
                                        QString id = value.toString();
                                        qDebug() << "id : " << id;
                                     }
                             }

                            if (obj.contains("url")) {
                                 QJsonValue value = obj.value("url");
                                    if (value.isString()) {
                                        QString url_png = value.toString();
                                        qDebug() << "url : " << url_png;
                                        Smartisan->setPixmap(setpnglabel(url_png));
                                     }
                             }
                       }
                   }

        }




    }
}
QPixmap DtkSmartisanosWallpaper::setpnglabel(const QString &szUrl)
{
    //QString szUrl="http://icon.smartisan.com/drawable/com.sina.weibo/logo.png";
    QUrl url(szUrl);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *replypng = manager.get(QNetworkRequest(url));
    QObject::connect(replypng, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray jpegData = replypng->readAll();
    QPixmap pix;
    pix.loadFromData(jpegData);

    QSize picSize(500,500);
    //将pixmap缩放成picSize大小然后保存在scaledPixmap中
    QPixmap scaledPixmap = pix.scaled(picSize, Qt::KeepAspectRatio);

    return scaledPixmap;
    //logoPng->setPixmap(pix);
}
