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
    titlebar()->setIcon(QIcon(":/images/iconfinder-icon.svg"));


    QHBoxLayout *h1layout =new QHBoxLayout(s);
    QVBoxLayout *v1layout = new QVBoxLayout(s);
        QHBoxLayout *pagelayout =new QHBoxLayout(s);
            DComboBox *sortcombobox= new DComboBox;
            sortcombobox->addItem("Artand");
            sortcombobox->addItem("Smartisan");
            sortcombobox->addItem("Unsplash");
            sortcombobox->addItem("Minimography");
            sortcombobox->addItem("Pexels");
            sortcombobox->addItem("Magdeleine");
            sortcombobox->addItem("Fancycrave");
            sortcombobox->addItem("Snapwiresnaps");
            sortcombobox->addItem("Memento");
            sortcombobox->addItem("纹理与材质壁纸");
            sortcombobox->addItem("壁纸摄影大赛精选");
            DLabel *pagelabel = new DLabel;
            pagelabel->setText("第几页");
            DPushButton *firstpage = new DPushButton;
            firstpage->setText("首页");
            DPushButton *uppage = new DPushButton;
            uppage->setText("上一页");
            DPushButton *downtpage = new DPushButton;
            downtpage->setText("下一页");



    QVBoxLayout *v2layout = new QVBoxLayout(s);

        name->setText("name"); 
        auther->setText("auther");       
        source->setText("source");     
        des->setText("des");
        DLineEdit *locationLineEdit = new DLineEdit;
        DPushButton *download = new DPushButton;
        DLabel *Smartisan = new DLabel();

        Smartisan->setAlignment(Qt::AlignHCenter);
        Smartisan ->setText("Smartisan");
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
      QHBoxLayout *h2layout =new QHBoxLayout(s);
     h2layout->addWidget(pic1);
     h2layout->addWidget(pic2);
     h2layout->addWidget(pic3);
     pic1->setAlignment(Qt::AlignCenter);
     pic2->setAlignment(Qt::AlignCenter);
     pic3->setAlignment(Qt::AlignCenter);
     QImage *default_img=new QImage;
     default_img->load(":/images/smartisan.png");
     pic1->setPixmap(QPixmap::fromImage(*default_img).scaled(250,250 ,Qt::KeepAspectRatio, Qt::SmoothTransformation));
     pic2->setPixmap(QPixmap::fromImage(*default_img).scaled(250,250 ,Qt::KeepAspectRatio, Qt::SmoothTransformation));
     pic3->setPixmap(QPixmap::fromImage(*default_img).scaled(250,250 ,Qt::KeepAspectRatio, Qt::SmoothTransformation));
      QVBoxLayout *v3layout = new QVBoxLayout(s);
      v3layout->addLayout(h2layout);
      v1layout->addLayout(v3layout);


      h1layout->addLayout(v2layout);
      h1layout->setStretchFactor(v2layout,1);
      v2layout->addWidget(name);
      v2layout->addWidget(auther);
      v2layout->addWidget(source);
      v2layout->addWidget(des);
      v2layout->addWidget(locationLineEdit);
      v2layout->addWidget(download);
      v2layout->addWidget(Smartisan);


//      refresh_ui();
      connect(this,SIGNAL(refresh_changed()),this,SLOT(refresh_ui()));
//      emit refresh_changed();
      //wallpaper sorts
      connect(sortcombobox, &DComboBox::currentTextChanged, this, [ = ] {
          sorts = sortcombobox->currentText();
          pagenum = 0;
          emit refresh_changed();
      });

      //firstpage button
      connect(firstpage,&DPushButton::clicked,this,[ = ]{
        pagenum = 0;
        qDebug()<<"pagenum"<<pagenum;
        emit refresh_changed();
      });

      //uppage button
      connect(uppage,&DPushButton::clicked,this,[ = ]{
       pagenum--;
       qDebug()<<"pagenum"<<pagenum;
       emit refresh_changed();
      });

      //downpage button
      connect(downtpage,&DPushButton::clicked,this,[ = ]{
        pagenum++;
        qDebug()<<"pagenum"<<pagenum;
        emit refresh_changed();
      });

}

void DtkSmartisanosWallpaper::refresh_ui()
{
    QNetworkAccessManager manager;
    QNetworkRequest request;

    QString url ="http://wallpaper-api.smartisan.com/app/index.php?r=paperapi/index/list&client_version=2&source="+sorts+"&limit=20&paper_id=0";
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
                            for (int i = 0;i < 20 ;i++ ) {
                            QJsonObject obj = array.at(i).toObject();
                            if (obj.contains("author")) {
                                 QJsonValue value = obj.value("author");
                                    if (value.isString()) {
                                        author[i] = value.toString();
                                        qDebug() << "author : " << author[i];
                                     }
                             }

                            if (obj.contains("id")) {
                                 QJsonValue value = obj.value("id");
                                    if (value.isString()) {
                                        id[i] = value.toString();
                                        qDebug() << "id : " << id[i];
                                     }
                             }

                            if (obj.contains("url")) {
                                 QJsonValue value = obj.value("url");
                                    if (value.isString()) {
                                        url_png[i] = value.toString();
                                        qDebug() << "url : " << url_png[i];

                                    }
                             }
                             }
                       }
                   }
        }
    }
    pic1->setPixmap(setpnglabel(url_png[3*pagenum+0]));
    pic2->setPixmap(setpnglabel(url_png[3*pagenum+1]));
    pic3->setPixmap(setpnglabel(url_png[3*pagenum+2]));
     name->setText("name:"+id[0]);
     auther->setText("auther:"+author[0]);
     source->setText("source:"+sorts);
//     des->setText("des:"+des[0]);
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
