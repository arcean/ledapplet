/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Karoliina T. Salminen <karoliina.t.salminen@nokia.com>
**
** This file is part of duicontrolpanel.
**
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/
#include "drilllistitem.h"

#include <QtGui/QGraphicsGridLayout>

#include <MImageWidget>
#include <MLabel>
#include <MImageWidget>


DrillListItem::DrillListItem (QGraphicsWidget *parent)
    : MBasicListItem(MBasicListItem::TitleWithSubtitle, parent)
{
    setStyleName("CommonPanelInverted");
}

DrillListItem::~DrillListItem()
{
}

QGraphicsLayout *DrillListItem::createLayout()
{
    QGraphicsGridLayout *layout = new QGraphicsGridLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    titleLabelWidget()->setStyleName("CommonTitleInverted");
    titleLabelWidget()->setAlignment(Qt::AlignTop);
    layout->addItem(titleLabelWidget(), 0, 0);
    layout->setAlignment(titleLabelWidget(), Qt::AlignTop | Qt::AlignLeft);

    subtitleLabelWidget()->setStyleName("CommonSubTitleInverted");
    layout->addItem(subtitleLabelWidget(), 1, 0);

    QGraphicsWidget *spacer = new QGraphicsWidget;
    spacer->setContentsMargins(0, 0, 0, 0);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addItem(spacer, 2, 0, 1, 1);

    m_drillImage = new MImageWidget("icon-m-common-drilldown-arrow-inverse");
    m_drillImage->setStyleName("CommonDrillDownIcon");
    layout->addItem(m_drillImage, 0, 1, 3, 1, Qt::AlignVCenter | Qt::AlignRight);

    return layout;
}

void DrillListItem::setDisabled(bool disable)
{
    setEnabled(!disable);
    if (disable) {
        m_drillImage->setOpacity(0.3);
    } else {
        m_drillImage->setOpacity(1);
    }
}
