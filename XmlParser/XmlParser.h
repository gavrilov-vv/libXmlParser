#ifndef ZXMLPARSER_H
#define ZXMLPARSER_H

#include <QObject>
#include <QtXml/QtXml>
#include <QDomNodeList>
#include <QDomNode>

#include "global_defs.h"
#include "Models.h"

class XmlParser : public QObject
{
    Q_OBJECT

public:
    explicit XmlParser(QObject *parent = nullptr);
    ~XmlParser();

    qint32 init();

    QList<Book> fetchBooks(const QString &_data);

};

#endif // ZXMLPARSER_H
