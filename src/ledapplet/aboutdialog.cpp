#include <MLabel>
#include <QGraphicsLinearLayout>
#include <MImageWidget>
#include "aboutdialog.h"

AboutDialog::AboutDialog()
{
    this->addButton(M::CloseButton);
    this->setTitle("");

    const QChar CopyrightSymbol(0x00a9);

    QString text(qtTrId("qtn_ledapplet_about_text"));
    QString copyright_string(QString(CopyrightSymbol) + QString::fromUtf8(" 2012 Tomasz Pieniążek"));

    MLabel *textSystemModal= new MLabel(text + "\n" + copyright_string);
    textSystemModal->setStyleName("CommonBodyTextInverted");
    textSystemModal->setAlignment(Qt::AlignCenter);
    textSystemModal->setWordWrap(true);
    textSystemModal->setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);

    MLabel *title= new MLabel(qtTrId("LED notifications"));
    title->setStyleName("title_label");
    title->setAlignment(Qt::AlignCenter);
    title->setWordWrap(true);
    title->setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);

    QGraphicsLinearLayout *layoutDesc = new QGraphicsLinearLayout(Qt::Horizontal);
    layoutDesc->addStretch();
    layoutDesc->addItem(textSystemModal);
    layoutDesc->addStretch();

    QGraphicsLinearLayout *layoutTitle = new QGraphicsLinearLayout(Qt::Horizontal);
    layoutTitle->addStretch();
    layoutTitle->addItem(title);
    layoutTitle->addStretch();

    MImageWidget *image = new MImageWidget(new QPixmap("/opt/ledapplet/styles/led.png"));

    QGraphicsLinearLayout *layout1 = new QGraphicsLinearLayout(Qt::Vertical);
    layout1->addItem(image);
    layout1->addItem(layoutTitle);
    layout1->addItem(layoutDesc);
    layout1->addStretch();

    this->centralWidget()->setLayout(layout1);
    this->setObjectName("about_dialog");
}
