/******************************************************************************
 * This file is part of the QtOpenAL project
 * Copyright (c) 2011 Laszlo Papp <lpapp@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef QALSNDAUDIODECODER_H
#define QALSNDAUDIODECODER_H

#include "q_openal_export.h"

#include "qalabstractaudiodecoder.h"

class Q_OPENAL_EXPORT QALSndAudioDecoder : QALAbstractAudioDecoder
{
    //Q_DECLARE_PRIVATE(QALAbstractAudioDecoder)
public:
    QALSndAudioDecoder();
    virtual ~QALSndAudioDecoder();

    bool open(const QFile &file);
    bool open(const QUrl &fileUrl);
    bool open(const QString &fileName);
    qint64 pos();
    bool seek(qint64 pos);
    bool close();

    void setEncodedData(const QByteArray &encodedData);

    int channels() const;
    int sampleRate() const;
    int sampleSize() const;

    QByteArray decode(qint64 maxlen);
    qint64 decode(char *decodedData, qint64 maxlen);

    private:
        class Private;
        Private *const d;
};

#endif // QALSNDAUDIODECODER_H