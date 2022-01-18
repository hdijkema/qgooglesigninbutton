#ifndef QGOOGLESIGNINBUTTON_GLOBAL_H
#define QGOOGLESIGNINBUTTON_GLOBAL_H

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

#include <QtCore/qglobal.h>

#if defined(QGOOGLESIGNINBUTTON_TEST)
#  define QGOOGLESIGNINBUTTON_EXPORT
#else
#  if defined(QGOOGLESIGNINBUTTON_LIBRARY)
#    define QGOOGLESIGNINBUTTON_EXPORT Q_DECL_EXPORT
#  else
#    define QGOOGLESIGNINBUTTON_EXPORT Q_DECL_IMPORT
#  endif
#endif

#ifndef QT6
#  if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
#    define QT6
#  endif
#endif

#endif // QGOOGLESIGNINBUTTON_GLOBAL_H
