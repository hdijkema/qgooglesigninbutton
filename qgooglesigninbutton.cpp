#include "qgooglesigninbutton.h"

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


#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QApplication>
#include <QStyle>
#include <QScreen>
#include <QTimer>
#include <QDebug>

static QFont getFont()
{
    static bool initialized = false;
    static int id = -1;

    if (!initialized) {
        id = QFontDatabase::addApplicationFont(":/qgooglesigninbutton/roboto.ttf");
        initialized = true;
    }

    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(family);

    return f;
}

static QColor zcColor(const QString &html)
{
    auto digInt = [](const QChar &D) {
        QChar dd = D.toLower();
        char d = dd.toLatin1();
        int a = (d >= '0' && d <= '9') ? static_cast<int>(d - '0')
                : static_cast<int>(d - 'a' + 10);
        return a;
    };

    auto toInt = [digInt](const QString &hex) {
        return (digInt(hex[0]) * 16) + digInt(hex[1]);
    };

    QString h = html.mid(1);
    QString r = h.mid(0, 2);
    QString g = h.mid(2, 2);
    QString b = h.mid(4, 2);
    QString a = h.mid(6, 2);
    if (a == "") { a = "FF"; }

    return QColor(toInt(r), toInt(g), toInt(b), toInt(a));
}

static qreal mmToPx(QWidget *w, qreal mm)
{
    QScreen *myscreen = w->screen();
    if (myscreen != nullptr) {
        qreal px = ((myscreen->physicalDotsPerInch() / 25.4) * mm);
        return px;
    } else {
        return 5;
    }
}

static QIcon zcSvgIcon(const QString &resource)
{
    return QIcon(resource);
}

class QGoogleSignInButtonData
{
public:
    QGraphicsDropShadowEffect *effect;
    bool                       dark;
    QTimer                    *timer;
};

QGoogleSignInButton::QGoogleSignInButton(QWidget *parent)
    : QGoogleSignInButton(tr("Sign in with Google"), parent)
{
}

QGoogleSignInButton::QGoogleSignInButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    D = new QGoogleSignInButtonData();

    setDark(true);

    int ribbe = QApplication::style()->pixelMetric(QStyle::PM_LargeIconSize);
    setIconSize(QSize(ribbe, ribbe));

    D->effect = new QGraphicsDropShadowEffect();
    setGraphicsEffect(D->effect);

    D->effect->setBlurRadius(0);
    D->effect->setOffset(0, 0);
    D->effect->setColor(zcColor("#4285F480"));

    QFont f = getFont();
    f.setBold(true);
    setFont(f);

    D->timer = new QTimer(this);
    connect(D->timer, &QTimer::timeout, this, &QGoogleSignInButton::timedUpdate);
    D->timer->setSingleShot(true);

    reactEnabled();
}

QGoogleSignInButton::~QGoogleSignInButton()
{
    delete D;
}

void QGoogleSignInButton::setAgain()
{
    setText(tr("Sign in with Google Again"));
}

void QGoogleSignInButton::setInitial()
{
    setText(tr("Sign in with Google"));
}

void QGoogleSignInButton::focusInEvent(QFocusEvent *event)
{
    enterEffect(true);
    QPushButton::focusInEvent(event);
}


void QGoogleSignInButton::focusOutEvent(QFocusEvent *event)
{
    enterEffect(false);
    QPushButton::focusOutEvent(event);
}

#ifdef QT6
void QGoogleSignInButton::enterEvent(QEnterEvent *event)
#else
void QGoogleSignInButton::enterEvent(QEvent *event)
#endif
{
    enterEffect(true);
    setCursor(Qt::PointingHandCursor);
    QPushButton::enterEvent(event);
}

void QGoogleSignInButton::leaveEvent(QEvent *event)
{
    enterEffect(false);
    unsetCursor();
    QPushButton::leaveEvent(event);
}

QSize QGoogleSignInButton::minimumSizeHint() const
{
    QSize s = QPushButton::minimumSizeHint();
    return s;
}

void QGoogleSignInButton::changeEvent(QEvent *e)
{
    QPushButton::changeEvent(e);

    bool enabled_change = (e->type() == QEvent::EnabledChange);
    if (enabled_change) {
        D->timer->start(50);
    }
}

void QGoogleSignInButton::timedUpdate()
{
    reactEnabled();
}

void QGoogleSignInButton::setDefault(bool yes)
{
    QPushButton::setDefault(yes);
}

bool QGoogleSignInButton::isDark()
{
    return D->dark;
}

bool QGoogleSignInButton::isLight()
{
    return !D->dark;
}

void QGoogleSignInButton::setDark(bool yes)
{
    D->dark = yes;
    reactEnabled();
}

void QGoogleSignInButton::setLight(bool yes)
{
    setDark(!yes);
    reactEnabled();
}

void QGoogleSignInButton::enterEffect(bool on)
{
    if (isEnabled()) {
        if (on) {
            qreal px = mmToPx(this, 2.5);
            D->effect->setBlurRadius(px);
            D->effect->setOffset(0, 0);
            if (isDark()) {
                D->effect->setColor(zcColor("#4285F480"));
            } else {
                D->effect->setColor(zcColor("#80808080"));
            }
        } else {
            D->effect->setBlurRadius(0);
            D->effect->setOffset(0, 0);
        }
    }

    reactEnabled();
}

void QGoogleSignInButton::reactEnabled()
{
    if (D->dark && isEnabled()) {
        setStyleSheet("QPushButton {"
                      "border: 2px solid #4285F4;"
                      "border-radius: 2px;"
                      "background-color: #4285F4;"
                      "padding-right: 1em;"
                      "color: white;"
                      "text-align: left;"
                      "}"
                      "QPushButton:pressed {"
                      "background-color: #3367d6;"
                      "}"
                      );
    } else {
        setStyleSheet("QPushButton {"
                      "border: 2px solid #c0c0c0;"
                      "border-radius: 2px;"
                      "background-color: white;"
                      "padding-right: 1em;"
                      "color: #808080;"
                      "text-align: left;"
                      "}"
                      "QPushButton:pressed {"
                      "background-color: #c0c0c0;"
                      "}"
                      );
    }

    QString d = (D->dark) ? "dark" : "light";

    if (isEnabled()) {
        setIcon(zcSvgIcon(QString(":/qgooglesigninbutton/%1_normal.svg").arg(d)));
    } else {
        setIcon(zcSvgIcon(QString(":/qgooglesigninbutton/%1_disabled.svg").arg(d)));
    }

    QString txt = text();
    setText(txt);
}
