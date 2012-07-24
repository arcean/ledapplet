/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (directui@nokia.com)
**
** This file is part of meegotouch-controlpanelapplets.
**
** If you have questions regarding the use of this file, please contact
** Nokia at directui@nokia.com.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include <MTheme>
#include <MAction>
#include <QDBusInterface>

#include "ledapplet.h"
#include "ledwidget.h"
#include "ledsettingswidget.h"
#include "ledbrief.h"

Q_EXPORT_PLUGIN2(LedApplet, LedApplet)

LedApplet::LedApplet() :
    m_LedBusinessLogic (new LedBusinessLogic)
{
}

LedApplet::~LedApplet()
{
    delete m_LedBusinessLogic;
}

void 
LedApplet::init()
{
    m_RefererPage = View::None;
    m_LastConstructedView = View::None;
}

DcpWidget *
LedApplet::pageMain(
        int widgetId)
{
    DcpWidget *ret_widget;

    switch (widgetId) {
    case View::Main:
        ret_widget = new LedWidget (m_LedBusinessLogic);
        m_LastConstructedView = View::Main;
        return ret_widget;
    case View::Settings:
        ret_widget = new LedSettingsWidget (m_LedBusinessLogic);
        m_LastConstructedView = View::Settings;
        return ret_widget;
    default:
        break;
    }

    return 0;
}

DcpWidget *
LedApplet::constructWidget (
        int widgetId)
{
    return pageMain (widgetId);
}

QString
LedApplet::title() const
{
    const char* msgid;

    switch (m_LastConstructedView) {
    case View::Settings:
        msgid = QT_TRID_NOOP("qtn_led_applet_title_settings");
        break;
    case View::Main:
    default:
        msgid = QT_TRID_NOOP("qtn_led_applet_title");
        break;
    }

    return QString(qtTrId(msgid));
}

void LedApplet::refererToChangeWidgetSlot(View::Id ref)
{
    m_RefererPage = ref;
}

QVector<MAction*>
LedApplet::viewMenuItems()
{

    //MAction            *helpAction;
    QVector<MAction*>   vector;
/*
    SYS_DEBUG ("");
    helpAction = new MAction (
            //% "User Guide"
            qtTrId ("qtn_comm_userguide"), 
            pageMain (0));
    helpAction->setLocation (MAction::ApplicationMenuLocation);

    connect (helpAction, SIGNAL (triggered (bool)),
             this, SLOT (userGuide ()));

    vector.append(helpAction);*/

    return vector;
}


/*
void
LedApplet::userGuide ()
{
    QDBusInterface userguide ("com.nokia.userguide", "/",
                              "com.nokia.UserGuideIf");
    userguide.call ("pageByPath", "tips.cfg");
    SYS_DEBUG ("");
}*/


DcpBrief *
LedApplet::constructBrief (
        int partId)
{
    Q_UNUSED (partId);
    return new LedBrief (m_LedBusinessLogic);
}
