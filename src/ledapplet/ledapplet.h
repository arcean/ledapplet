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
#ifndef LedApplet_H
#define LedApplet_H

#include <QObject>
#include <QPointer>
#include <DcpAppletIf>

#include "dcpappletif.h"
#include "ledbusinesslogic.h"
#include "viewId.h"

class LedWidget;

class LedApplet : public QObject, public DcpAppletIf
{
    Q_OBJECT
    Q_INTERFACES(DcpAppletIf)

public:
    LedApplet ();
    ~LedApplet ();

    virtual void init();
    virtual DcpWidget *constructWidget (int widgetId);
    virtual DcpWidget *pageMain (int widgetId);
    virtual QString title() const;
    virtual QVector<MAction *> viewMenuItems();
    virtual DcpBrief* constructBrief(int partId);

private slots:
   // void userGuide ();
    void refererToChangeWidgetSlot(View::Id ref);

private:
    QPointer<LedBusinessLogic> m_LedBusinessLogic;
    View::Id m_LastConstructedView;
    View::Id m_RefererPage;
};
#endif
