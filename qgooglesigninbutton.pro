################################################################################
# This file is part of QGoogleSignInButton.
#
# (c) Hans Dijkema 2021
#
#  QGoogleSignInButton is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 2.1 of the License, or
#  (at your option) any later version.
#
#  QGoogleSignInButton is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with QGoogleSignInButton. If not, see <https://www.gnu.org/licenses/>.
################################################################################

QT += widgets

TEMPLATE = lib
DEFINES += QGOOGLESIGNINBUTTON_LIBRARY

# QT6 Support
equals(QT_MAJOR_VERSION, 6) {
win32: TARGET = qgooglesigninbutton_qt6
mac: TARGET = libqgooglesigninbutton_qt6
}

mac: message(Qt Deployment Target: $$QMAKE_MACOSX_DEPLOYMENT_TARGET)
mac: QMAKE_APPLE_DEVICE_ARCHS = x86_64 arm64

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qgooglesigninbutton.cpp

HEADERS += \
    qgooglesigninbutton_global.h \
    qgooglesigninbutton.h

TRANSLATIONS += \
    qgooglesigninbutton_nl_NL.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qgooglesiginbutton_res.qrc

DISTFILES += \
    QGoogleSignInButton
