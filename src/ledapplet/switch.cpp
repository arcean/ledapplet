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

#include <MLabel>
#include <QStyle>

#include "switch.h"

Switch::Switch(QString const &title, QGraphicsItem *parent):
    MWidgetController(parent),
    labelTitle(title)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    //setStyleName ("CommonHeaderPanelInverted");
    setContentsMargins(0, 0, 0, 0);

    // Create switchlayout
    switchLayout = new QGraphicsLinearLayout(Qt::Horizontal, this);
    switchLayout->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    // Top and bottom margins: 9, 9
    switchLayout->setContentsMargins(0, 9, 0, 9);
    switchLayout->setSpacing(0);

    switchButton = new MButton(this);
    switchButton->setViewType(MButton::switchType);
    switchButton->setObjectName("CommonRightSwitchInverted");
    switchButton->setChecked(false);
    switchButton->setCheckable(true);
    MLabel *switchLabel = new MLabel(labelTitle, this);
    switchLabel->setStyleName("CommonSingleTitleInverted");
    switchLayout->addItem(switchLabel);
    switchLayout->setAlignment(switchLabel, Qt::AlignLeft);
    switchLayout->addItem(switchButton);
    switchLayout->setAlignment(switchButton, Qt::AlignRight | Qt::AlignVCenter);

    connect(switchButton, SIGNAL(toggled(bool)), this, SLOT(stateChanged(bool)));
}

void Switch::stateChanged(bool isToggled)
{
    emit switchToggled(isToggled);
}

void Switch::setChecked(bool isChecked)
{
    switchButton->setChecked(isChecked);
}
