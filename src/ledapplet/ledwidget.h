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
#ifndef LedWIDGET_H
#define LedWIDGET_H

#include <QPointer>
#include "dcpwidget.h"

#include "ledbusinesslogic.h"
#include "viewId.h"
#include "switch.h"
#include "drilllistitemtitle.h"

class LedWidget : public DcpWidget
{
    Q_OBJECT

public:
    LedWidget (
            LedBusinessLogic     *LedBusinessLogic,
            QGraphicsWidget        *parent = 0);
    ~LedWidget ();

    void createContent ();

signals:
    void refererToChangeWidget(View::Id);

private slots:
    void showSettings();
    void showAboutDialog();

    void onToggled(bool isToggled);

private:
    void onLoad();

    // Main switch:
    Switch                  *ledState;
    // DrillListItemTitle:
    DrillListItemTitle      *settingsDrillListItem;

    QPointer<LedBusinessLogic>    m_LedBusinessLogic;
};

#endif
