#ifndef QGOOGLESIGNINBUTTON_H
#define QGOOGLESIGNINBUTTON_H

/*
 * This file is part of QGoogleSignInButton.
 *
 * (c) Hans Dijkema 2021
 *
 *  QGoogleSignInButton is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 2.1 of the License, or
 *  (at your option) any later version.
 *
 *  QGoogleSignInButton is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with QGoogleSignInButton. If not, see <https://www.gnu.org/licenses/>.
 */

#include "qgooglesigninbutton_global.h"

#include <QPushButton>
#include <QObject>
#include <QWidget>

class QGoogleSignInButtonData;

class QGOOGLESIGNINBUTTON_EXPORT QGoogleSignInButton : public QPushButton
{
    Q_OBJECT
private:
    QGoogleSignInButtonData *D;

public:
    explicit QGoogleSignInButton(QWidget *parent = nullptr);
    explicit QGoogleSignInButton(const QString &text, QWidget *parent = nullptr);
   ~QGoogleSignInButton();

public:
    void setAgain();
    void setInitial();

    // QWidget interface
protected:
    virtual void focusInEvent(QFocusEvent *event) override;
    virtual void focusOutEvent(QFocusEvent *event) override;
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual QSize minimumSizeHint() const override;
    virtual void changeEvent(QEvent *) override;

public:
    void setDefault(bool yes);

    bool isDark();
    bool isLight();
    void setDark(bool yes);
    void setLight(bool yes);

private slots:
    void timedUpdate();

private:
    void reactEnabled();
    void enterEffect(bool on);
};

#endif // QGOOGLESIGNINBUTTON_H
