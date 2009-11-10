/****************************************************************************
 *  chatstyle.h
 *
 *  Copyright (c) 2009 by Sidorov Aleksey <sauron@citadelspb.com>
 *
 ***************************************************************************
 *                                                                         *
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************
*****************************************************************************/

#ifndef CHATSTYLE_H
#define CHATSTYLE_H
#include <QString>
#include <QColor>
#include <QMap>

namespace AdiumChat
{
	typedef QMap<QString,QString> StyleVariants;
	struct ChatStyle
	{
		QString styleName;
		QString baseHref;
		QString basePath;
		QString currentVariantPath;
		QString templateHtml;
		QString headerHtml;
		QString footerHtml;
		QString incomingHtml;
		QString nextIncomingHtml;
		QString outgoingHtml;
		QString nextOutgoingHtml;
		QString incomingHistoryHtml;
		QString nextIncomingHistoryHtml;
		QString outgoingHistoryHtml;
		QString nextOutgoingHistoryHtml;
		QString incomingActionHtml;
		QString outgoingActionHtml;
		QString statusHtml;
		QString mainCSS;
		QColor backgroundColor;
		QString defaultVariant;
		StyleVariants variants;
		bool backgroundIsTransparent;
		bool isValid();
	};
	
	struct ChatStyleGeneratorPrivate;
	class ChatStyleGenerator
	{
	public:
		ChatStyleGenerator (const QString &stylePath, const QString &variant = QString());
		~ChatStyleGenerator();
		ChatStyle getChatStyle () const;
		StyleVariants getVariants() const;
		static StyleVariants listVariants (const QString &path);
	private:
		QScopedPointer<ChatStyleGeneratorPrivate> d;
	};
}
#endif // CHATSTYLE_H
