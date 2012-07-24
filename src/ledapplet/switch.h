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

#include <MWidgetController>
#include <QGraphicsLinearLayout>
#include <MButton>

#ifndef SWITCH_H
#define SWITCH_H

class Switch: public MWidgetController
{
    Q_OBJECT

    public:
        Switch(QString const &title, QGraphicsItem *parent = 0);

        void setChecked(bool isChecked);

    signals:
        void switchToggled(bool isToggled);

    private slots:
        void stateChanged(bool isToggled);

    private:
        QGraphicsLinearLayout *switchLayout;
        QString labelTitle;
        MButton *switchButton;
};

#endif
