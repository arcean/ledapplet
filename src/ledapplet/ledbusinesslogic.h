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
#ifndef LedBUSINESSLOGIC_H
#define LedBUSINESSLOGIC_H

#include <QList>
#include <QObject>
#include <MGConfItem>

class LedBusinessLogic : public QObject
{
    Q_OBJECT

public:
    LedBusinessLogic ();
    ~LedBusinessLogic ();

    bool isLEDEnabled();
    void setEnabledLED(bool enable);
    bool isEnabled(const QString &text);
    void setEnabled(const QString &text, bool isEnabled);

signals:

public slots:

private slots:

private:
    MGConfItem *configItem;

};

#endif
