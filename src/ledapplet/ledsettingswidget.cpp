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

#include "ledsettingswidget.h"

#include <MLayout>
#include <MLinearLayoutPolicy>
#include <QGraphicsLinearLayout>
#include <MContainer>
#include <MButton>
#include <MDialog>
#include <MMessageBox>
#include <MSeparator>
#include <MLabel>

#include "TitleWidget.h"
#include "drilllistitemtitle.h"

LedSettingsWidget::LedSettingsWidget (
        LedBusinessLogic     *LedBusinessLogic,
        QGraphicsWidget        *parent) :
    DcpWidget (parent),
    m_LedBusinessLogic (LedBusinessLogic)
{
    createContent();
}

LedSettingsWidget::~LedSettingsWidget ()
{
}


void
LedSettingsWidget::createContent ()
{
    QGraphicsLinearLayout   *mainLayoutPolicy;
    //MSeparator              *titleSeparator;
    TitleWidget             *title;
    // Configbox widgets:
    MContainer              *configBox;
    QGraphicsLinearLayout   *configBoxLayout;
    QGraphicsWidget         *configBoxWidget;

    mainLayoutPolicy = new QGraphicsLinearLayout(Qt::Vertical);
    mainLayoutPolicy->setSpacing(0);
    mainLayoutPolicy->setContentsMargins(0, 0, 0, 0);

    /* HEADER ==================================== */
    /* title */
    title = new TitleWidget(qtTrId("qtn_led_applet_title_settings"), "CommonHeaderInverted");
    mainLayoutPolicy->addItem(title);

    /* spacers */
   // titleSeparator = new MSeparator;
    //titleSeparator->setStyleName("CommonHeaderDividerInverted");
   // titleSeparator->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
   // mainLayoutPolicy->addItem(titleSeparator);
    /* END OF HEADER ==================================== */

    /* CONFIGBOX ================================== */
    configBox = new MContainer();
    configBox->setStyleName("CommonContainerInverted");
    configBox->setTitle(qtTrId("qtn_led_applet_config"));
    configBoxLayout = new QGraphicsLinearLayout(Qt::Vertical);
    configBoxLayout->setContentsMargins(0, 0, 0, 0);
    configBoxLayout->setSpacing(0);
    configBoxWidget = new QGraphicsWidget();
    configBoxWidget->setLayout(configBoxLayout);
    configBox->setCentralWidget(configBoxWidget);

    call = new Switch(qtTrId("qtn_led_applet_call"));
    configBoxLayout->addItem(call);
    chat = new Switch(qtTrId("qtn_led_applet_chat"));
    configBoxLayout->addItem(chat);
    sms = new Switch(qtTrId("qtn_led_applet_sms"));
    configBoxLayout->addItem(sms);
    voicemail = new Switch(qtTrId("qtn_led_applet_voicemail"));
    configBoxLayout->addItem(voicemail);
    email = new Switch(qtTrId("qtn_led_applet_email"));
    configBoxLayout->addItem(email);
    organiser = new Switch(qtTrId("qtn_led_applet_organiser"));
    configBoxLayout->addItem(organiser);
    facebook = new Switch(qtTrId("qtn_led_applet_facebook"));
    configBoxLayout->addItem(facebook);
    twitter = new Switch(qtTrId("qtn_led_applet_twitter"));
    configBoxLayout->addItem(twitter);
    wazapp = new Switch(qtTrId("qtn_led_applet_wazapp"));
    configBoxLayout->addItem(wazapp);

    mainLayoutPolicy->addItem(configBox);

    mainLayoutPolicy->addStretch();
    setLayout (mainLayoutPolicy);

    connect(call, SIGNAL(switchToggled(bool)), this, SLOT(storeCall(bool)));
    connect(chat, SIGNAL(switchToggled(bool)), this, SLOT(storeChat(bool)));
    connect(sms, SIGNAL(switchToggled(bool)), this, SLOT(storeSMS(bool)));
    connect(voicemail, SIGNAL(switchToggled(bool)), this, SLOT(storeVoicemail(bool)));
    connect(email, SIGNAL(switchToggled(bool)), this, SLOT(storeEmail(bool)));
    connect(facebook, SIGNAL(switchToggled(bool)), this, SLOT(storeFacebook(bool)));
    connect(twitter, SIGNAL(switchToggled(bool)), this, SLOT(storeTwitter(bool)));
    connect(organiser, SIGNAL(switchToggled(bool)), this, SLOT(storeOrganiser(bool)));
    connect(wazapp, SIGNAL(switchToggled(bool)), this, SLOT(storeWazapp(bool)));

    onLoad();
}

void LedSettingsWidget::storeCall(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("call", isToggled);
}

void LedSettingsWidget::storeChat(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("chat", isToggled);
}

void LedSettingsWidget::storeSMS(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("sms", isToggled);
}

void LedSettingsWidget::storeVoicemail(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("voicemail", isToggled);
}

void LedSettingsWidget::storeEmail(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("email", isToggled);
}

void LedSettingsWidget::storeFacebook(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("facebook", isToggled);
}

void LedSettingsWidget::storeTwitter(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("twitter", isToggled);
}

void LedSettingsWidget::storeOrganiser(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("organiser", isToggled);
}

void LedSettingsWidget::storeWazapp(bool isToggled)
{
    m_LedBusinessLogic.data()->setEnabled("wazapp", isToggled);
}

void LedSettingsWidget::onLoad()
{
    call->setChecked(m_LedBusinessLogic.data()->isEnabled("call"));
    chat->setChecked(m_LedBusinessLogic.data()->isEnabled("chat"));
    sms->setChecked(m_LedBusinessLogic.data()->isEnabled("sms"));
    voicemail->setChecked(m_LedBusinessLogic.data()->isEnabled("voicemail"));
    email->setChecked(m_LedBusinessLogic.data()->isEnabled("email"));
    facebook->setChecked(m_LedBusinessLogic.data()->isEnabled("facebook"));
    twitter->setChecked(m_LedBusinessLogic.data()->isEnabled("twitter"));
    organiser->setChecked(m_LedBusinessLogic.data()->isEnabled("organiser"));
    wazapp->setChecked(m_LedBusinessLogic.data()->isEnabled("wazapp"));
}

