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

#include "ledbusinesslogic.h"
#include <QString>
#include <MGConfItem>

#include <QVariant>
#include <QDBusInterface>
#include <QDBusMessage>

#define GCONF_LED_KEY "/desktop/meego/notifications/led_enabled"

LedBusinessLogic::LedBusinessLogic()
{
    configItem = new MGConfItem(GCONF_LED_KEY);
}

LedBusinessLogic::~LedBusinessLogic()
{

}

bool LedBusinessLogic::isLEDEnabled()
{
    bool isEnabled = configItem->value().toStringList().contains("call")
            || configItem->value().toStringList().contains("chat")
            || configItem->value().toStringList().contains("sms")
            || configItem->value().toStringList().contains("voicemail")
            || configItem->value().toStringList().contains("email")
            || configItem->value().toStringList().contains("facebook")
            || configItem->value().toStringList().contains("twitter")
            || configItem->value().toStringList().contains("organiser")
            || configItem->value().toStringList().contains("wazapp");

    if (isEnabled)
        return true;
    return false;
}

void LedBusinessLogic::setEnabledLED(bool enable)
{
    QStringList list;

    if (enable) {
        list << "call" << "chat" << "sms" << "voicemail" << "email" << "facebook" << "twitter" << "organiser" << "wazapp";
        configItem->set(QVariant(list));
    }
    else {
        configItem->set(QVariant(list));
    }
}

bool LedBusinessLogic::isEnabled(const QString &text)
{
    return configItem->value().toStringList().contains(text);
}

void LedBusinessLogic::setEnabled(const QString &text, bool isEnabled)
{
    QStringList list;
    if (isEnabled) {
        list = configItem->value().toStringList();
        if (!list.contains(text))
            list << text;
        configItem->set(QVariant(list));
    }
    else {
        list = configItem->value().toStringList();
        if (list.contains(text))
            list.removeAll(text);

        configItem->set(QVariant(list));
    }
}

