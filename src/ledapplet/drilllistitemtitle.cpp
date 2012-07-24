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
#include "drilllistitemtitle.h"

#include <QGraphicsLinearLayout>
#include <MLabel>


DrillListItemTitle::DrillListItemTitle (QGraphicsWidget *parent)
    : MBasicListItem(MBasicListItem::SingleTitle, parent)
{
    setStyleName("CommonPanelInverted");
}

DrillListItemTitle::~DrillListItemTitle()
{
}

QGraphicsLayout *DrillListItemTitle::createLayout()
{
    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Horizontal, this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    titleLabelWidget()->setStyleName("CommonSingleTitleInverted");
    titleLabelWidget()->setWordWrap(true);
    layout->addItem(titleLabelWidget());
    layout->setAlignment(titleLabelWidget(), Qt::AlignVCenter | Qt::AlignLeft);

    //subtitleLabelWidget()->setStyleName("CommonSubTitleInverted");
   // layout->addItem(subtitleLabelWidget(), 1, 0);

   /* QGraphicsWidget *spacer = new QGraphicsWidget;
    spacer->setContentsMargins(0, 0, 0, 0);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addItem(spacer, 1, 0, 1, 1);*/

    m_drillImage = new MImageWidget("icon-m-common-drilldown-arrow-inverse");
    m_drillImage->setStyleName("CommonDrillDownIcon");
    layout->addItem(m_drillImage);
    layout->setAlignment(m_drillImage, Qt::AlignVCenter | Qt::AlignRight);

    return layout;
}

void DrillListItemTitle::setDisabled(bool disable)
{
    setEnabled(!disable);
}
