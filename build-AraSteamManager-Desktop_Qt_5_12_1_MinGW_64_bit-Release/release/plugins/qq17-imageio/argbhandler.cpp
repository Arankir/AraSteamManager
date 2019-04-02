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

#include "argbhandler.h"
#include <QImage>
#include <QIODevice>
#include <QVariant>
#include <QDataStream>

ArgbHandler::ArgbHandler()
{
}

ArgbHandler::~ArgbHandler()
{
}

bool ArgbHandler::canRead() const
{
    if (canRead(device())) {
        setFormat("raw");
        return true;
    }
    return false;
}

bool ArgbHandler::canRead(QIODevice *device)
{
    return device->peek(4) == "\xCA\xFE\x12\x34";
}

bool ArgbHandler::read(QImage *image)
{
    QDataStream input(device());
    quint32 magic, width, height;
    input >> magic >> width >> height;
    if (input.status() != QDataStream::Ok
        || magic != 0xCAFE1234)
        return false;
    QImage result(width, height, QImage::Format_ARGB32);
    for (quint32 y = 0; y < height; ++y) {
        QRgb *scanLine = (QRgb *)result.scanLine(y);
        for (quint32 x = 0; x < width; ++x)
            input >> scanLine[x];
    }
    if (input.status() == QDataStream::Ok)
        *image = result;
    return input.status() == QDataStream::Ok;
}

bool ArgbHandler::write(const QImage &image)
{
    QImage result = image.convertToFormat(QImage::Format_ARGB32);
    QDataStream output(device());
    quint32 magic = 0xCAFE1234;
    quint32 width = result.width();
    quint32 height = result.height();
    output << magic << width << height;
    for (quint32 y = 0; y < height; ++y) {
        QRgb *scanLine = (QRgb *)result.scanLine(y);
        for (quint32 x = 0; x < width; ++x)
            output << scanLine[x];
    }
    return output.status() == QDataStream::Ok;
}

bool ArgbHandler::supportsOption(ImageOption option) const
{
    return option == Size;
}

QVariant ArgbHandler::option(ImageOption option) const
{
    if (option == Size) {
        QByteArray bytes = device()->peek(12);
        QDataStream input(bytes);
        quint32 magic, width, height;
        input >> magic >> width >> height;
        if (input.status() == QDataStream::Ok
            && magic == 0xCAFE1234)
            return QSize(width, height);
    }
    return QVariant();
}

void ArgbHandler::setOption(ImageOption option, const QVariant &value)
{
    Q_UNUSED(option);
    Q_UNUSED(value);
}

QByteArray ArgbHandler::name() const
{
    return "raw";
}
