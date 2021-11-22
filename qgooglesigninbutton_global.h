#ifndef QGOOGLESIGNINBUTTON_GLOBAL_H
#define QGOOGLESIGNINBUTTON_GLOBAL_H

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

#endif // QGOOGLESIGNINBUTTON_GLOBAL_H