// SPDX-FileCopyrightText: 2019 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef QUICKPANELBASE_H
#define QUICKPANELBASE_H

#include "commoniconbutton.h"

#include <QWidget>
#include <DLabel>

DWIDGET_USE_NAMESPACE

class SignalQuickPanel : public QWidget
{
    Q_OBJECT

public:
    enum WidgetState {
        WS_NORMAL,
        WS_ACTIVE,
    };

public:
    SignalQuickPanel(QWidget *parent = nullptr);
    virtual ~SignalQuickPanel();

    void setIcon(const QIcon &icon);
    void setDescription(const QString &description);
    void setWidgetState(WidgetState state);

Q_SIGNALS:
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void initUI();

private slots:
    void refreshBg();

private:
    CommonIconButton *m_icon;
    DLabel *m_description;
};

#endif