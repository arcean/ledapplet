/***************************************************************************
**
** Copyright (C) 2012 Tomasz Pieniążek
** All rights reserved.
** Contact: Tomasz Pieniążek <t.pieniazek@gazeta.pl>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include "ledwidget.h"

#include <MLayout>
#include <MLinearLayoutPolicy>
#include <QGraphicsLinearLayout>
#include <MContainer>
#include <MButton>
#include <MDialog>
#include <MMessageBox>
#include <MSeparator>
#include <MLabel>
#include <MLocale>

#include "TitleWidget.h"
#include "aboutdialog.h"

LedWidget::LedWidget (
        LedBusinessLogic     *LedBusinessLogic,
        QGraphicsWidget        *parent) :
    DcpWidget (parent),
    m_LedBusinessLogic (LedBusinessLogic)
{
    MLocale locale;
    locale.installTrCatalog("ledapplet");
    MLocale::setDefault(locale);

    createContent();
}

LedWidget::~LedWidget ()
{
}


void
LedWidget::createContent ()
{
    QGraphicsLinearLayout   *mainLayoutPolicy;
    MSeparator              *titleSeparator;
    // Title:
    QGraphicsLinearLayout   *titleLayout;
    TitleWidget             *title;
    MButton                 *aboutButton;

    MTheme *theme = MTheme::instance();
    theme->loadCSS("/opt/ledapplet/styles/ledapplet.css");

    mainLayoutPolicy = new QGraphicsLinearLayout(Qt::Vertical);
    mainLayoutPolicy->setSpacing(0);
    mainLayoutPolicy->setContentsMargins(0, 0, 0, 0);

    /* HEADER ==================================== */
    /* title */
    titleLayout = new QGraphicsLinearLayout(Qt::Horizontal);
    titleLayout->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    titleLayout->setSpacing(0);
    titleLayout->setContentsMargins(0, 0, 0, 0);

    title = new TitleWidget(qtTrId("qtn_led_applet_title"), "CommonHeaderInverted");
    aboutButton = new MButton(this);
    aboutButton->setIconID ("icon-s-description-inverse");
    aboutButton->setViewType (MButton::iconType);
    aboutButton->setStyleName("CommonRightIcon");
    titleLayout->addItem(title);
    titleLayout->setAlignment(title, Qt::AlignLeft);
    titleLayout->addItem(aboutButton);
    titleLayout->setAlignment(aboutButton, Qt::AlignRight | Qt::AlignVCenter);
    mainLayoutPolicy->addItem(titleLayout);

    /* spacers */
    titleSeparator = new MSeparator;
    titleSeparator->setStyleName("CommonHeaderDividerInverted");
    titleSeparator->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    mainLayoutPolicy->addItem(titleSeparator);
    /* END OF HEADER ==================================== */

    /* LED STATE ======================================== */
    ledState = new Switch(qtTrId("qtn_led_applet_led_state"));
    mainLayoutPolicy->addItem(ledState);

    /* END OF LED STATE ================================= */

    /* DRILLLISTITEM ==================================== */
    /* spacers */
    titleSeparator = new MSeparator;
    titleSeparator->setStyleName("CommonHeaderDividerInverted");
    titleSeparator->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    mainLayoutPolicy->addItem(titleSeparator);

    settingsDrillListItem = new DrillListItemTitle();
    settingsDrillListItem->setTitle(qtTrId("qtn_led_applet_settings"));
    mainLayoutPolicy->addItem(settingsDrillListItem);

    /* END OF DRILLLISTITEM ============================= */

    mainLayoutPolicy->addStretch();
    setLayout (mainLayoutPolicy);

    onLoad();

    connect(settingsDrillListItem, SIGNAL(clicked()), this, SLOT(showSettings()));
    connect(aboutButton, SIGNAL(clicked()), this, SLOT(showAboutDialog()));
    connect(ledState, SIGNAL(switchToggled(bool)), this, SLOT(onToggled(bool)));
}

void LedWidget::showSettings()
{
    refererToChangeWidget(View::Main);
    emit changeWidget(View::Settings);
}

void LedWidget::showAboutDialog()
{
    AboutDialog *aboutDialog = new AboutDialog();
    aboutDialog->appear(MSceneWindow::DestroyWhenDone);
}

void LedWidget::onToggled(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabledLED(isToggled);
    settingsDrillListItem->setEnabled(isToggled);
}

void LedWidget::onLoad()
{
    bool isEnabled = m_LedBusinessLogic.data()->isLEDEnabled();
    ledState->setChecked(isEnabled);
    settingsDrillListItem->setDisabled(!isEnabled);
}

