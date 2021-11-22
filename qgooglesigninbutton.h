#ifndef QGOOGLESIGNINBUTTON_H
#define QGOOGLESIGNINBUTTON_H

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
