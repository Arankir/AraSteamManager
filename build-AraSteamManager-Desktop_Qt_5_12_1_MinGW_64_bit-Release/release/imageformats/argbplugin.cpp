/****************************************************************************
**
** Copyright (C) 2006 Trolltech AS. All rights reserved.
**
** This file is part of the documentation of Qt. It was originally
** published as part of Qt Quarterly.
**
** This file may be used under the terms of the GNU General Public License
** version 2.0 as published by the Free Software Foundation or under the
** terms of the Qt Commercial License Agreement. The respective license
** texts for these are provided with the open source and commercial
** editions of Qt.
**
** If you are unsure which license is appropriate for your use, please
** review the following information:
** http://www.trolltech.com/products/qt/licensing.html or contact the
** sales department at sales@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <qimageiohandler.h>
#include "argbhandler.h"

class ArgbPlugin : public QImageIOPlugin
{
public:
    ArgbPlugin();
    ~ArgbPlugin();

    QStringList keys() const;
    Capabilities capabilities(QIODevice *device, const QByteArray &format) const;
    QImageIOHandler *create(QIODevice *device, const QByteArray &format = QByteArray()) const;
};

ArgbPlugin::ArgbPlugin()
{
}

ArgbPlugin::~ArgbPlugin()
{
}

QStringList ArgbPlugin::keys() const
{
    return QStringList() << "raw";
}

QImageIOPlugin::Capabilities ArgbPlugin::capabilities(QIODevice *device, const QByteArray &format) const
{
    if (format == "raw")
        return Capabilities(CanRead | CanWrite);
    if (!(format.isEmpty() && device->isOpen()))
        return 0;

    Capabilities cap;
    if (device->isReadable() && ArgbHandler::canRead(device))
        cap |= CanRead;
    if (device->isWritable())
        cap |= CanWrite;
    return cap;
}

QImageIOHandler *ArgbPlugin::create(QIODevice *device, const QByteArray &format) const
{
    QImageIOHandler *handler = new ArgbHandler;
    handler->setDevice(device);
    handler->setFormat(format);
    return handler;
}

Q_EXPORT_STATIC_PLUGIN(ArgbPlugin)
Q_EXPORT_PLUGIN2(argb, ArgbPlugin)
