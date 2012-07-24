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
#ifndef LEDSETTINGSWIDGET_H
#define LEDSETTINGSWIDGET_H

#include <QPointer>
#include "dcpwidget.h"

#include "ledbusinesslogic.h"
#include "viewId.h"
#include "switch.h"

class LedSettingsWidget : public DcpWidget
{
    Q_OBJECT

public:
    LedSettingsWidget (
            LedBusinessLogic     *LedBusinessLogic,
            QGraphicsWidget        *parent = 0);
    ~LedSettingsWidget ();

    void createContent ();

signals:

private slots:
    void storeCall(bool isToggled);
    void storeChat(bool isToggled);
    void storeSMS(bool isToggled);
    void storeVoicemail(bool isToggled);
    void storeEmail(bool isToggled);
    void storeFacebook(bool isToggled);
    void storeTwitter(bool isToggled);
    void storeOrganiser(bool isToggled);

private:
    void onLoad();

    Switch                  *call;
    Switch                  *chat;
    Switch                  *sms;
    Switch                  *voicemail;
    Switch                  *email;
    Switch                  *facebook;
    Switch                  *twitter;
    Switch                  *organiser;

    QPointer<LedBusinessLogic>    m_LedBusinessLogic;
};

#endif
