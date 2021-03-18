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
        DLabel *Smartisan = new DLabel();
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

//      connect(this,SIGNAL(refresh_changed()),this,SLOT(refresh_ui()));
}
