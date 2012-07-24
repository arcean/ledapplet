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
#ifndef DRILLLISTITEMTITLE_H
#define DRILLLISTITEMTITLE_H

#include <MBasicListItem>
#include <MImageWidget>

class DrillListItemTitle: public MBasicListItem
{
    Q_OBJECT
public:
    DrillListItemTitle(QGraphicsWidget* parent = 0);
    ~DrillListItemTitle ();

    void setDisabled(bool disable);
protected:
    virtual QGraphicsLayout *createLayout();
private:
    MImageWidget *m_drillImage;
};

#endif // DRILLLISTITEMTITLE_H
