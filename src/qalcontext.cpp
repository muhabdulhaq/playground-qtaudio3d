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

#include "qalcontext.h"

#include "qalbufferqueue.h"

#if !defined(ALC_VERSION_0_1) || !defined(AL_VERSION_1_0)
#ifdef _WIN32
#include <al.h>
#include <alc.h>
#elif defined(__APPLE__)
#include <OpenAL/alc.h>
#include <OpenAL/al.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif
#endif

class QALContext::Private
{
    public:
        Private()
            : alcDevice(0)
            , alcContext(0)
        {
        }

        ~Private()
        {
        }

        ALCDevice *alcDevice;
        ALCContext *alcContext;
};

QALContext::QALContext()
{
}

QALContext::~QALContext()
{
}

bool
QALContext::create()
{
    // Open the default device
    if (d->alcDevice = alcOpenDevice(NULL) == false)
        return false;

    if ((d->alcContext = alcCreateContext(d->alcDevice, NULL)) == 0)
        return false;

    return true;
}

QALAttributes
requestedAttributes() const
{
}

QALAttributes
attributes() const
{
}

void
setAttributes(const QALAttributes &attributes)
{
}

bool
QALContext::isValid() const
{
}

bool
QALContext::isSharing() const
{
}

bool
QALContext::reset()
{
    if (alcDestroyContext(d->alcContext) == false)
        return false;

    return alcCloseDevice(d->alcDevice);
}

bool
QALContext::makeCurrent()
{
    return alcMakeContextCurrent(d->alcContext);
}

bool
QALContext::doneCurrent()
{
    return alcMakeContextCurrent(0);
}

ALuint
cacheBuffer(const QString& filename)
{
}

void
deleteBuffer(ALuint bufferId)
{
}

void
deleteBufferQueue(QALBufferQueue &bufferQueue)
{
}

void*
QALContext::getProcAddress(const QString &proc) const
{
    return alGetProcAddress(proc.toAscii().constData);
}
