#include "XmlParser.h"

XmlParser::XmlParser(QObject *parent) :
    QObject(parent)
{
    // Constructor
}

XmlParser::~XmlParser()
{
    // Destructor
}

qint32 XmlParser::init()
{
    // TODO
    return ResultCode::ALL_RIGHT;
}

QList<Book> XmlParser::fetchBooks(const QString &_data)
{
    QList<Book> _lst;

    QDomDocument domDoc;

    if(domDoc.setContent(_data))
    {
        QDomElement domElement = domDoc.documentElement();

        if(domElement.toElement().tagName() == "catalog")
        {
            QDomNodeList _nodeList = domElement.elementsByTagName("book");

            for(int i=0; i < _nodeList.size(); i++)
            {
                Book _book;
                _book.id = _nodeList.item(i).toElement().attribute("id");
                _book.author = _nodeList.at(i).toElement().elementsByTagName("author").at(0).toElement().text();
                _book.title = _nodeList.at(i).toElement().elementsByTagName("title").at(0).toElement().text();
                _book.genre = _nodeList.at(i).toElement().elementsByTagName("genre").at(0).toElement().text();
                _book.price = _nodeList.at(i).toElement().elementsByTagName("price").at(0).toElement().text().toFloat();
                QString _str = _nodeList.at(i).toElement().elementsByTagName("publish_date").at(0).toElement().text();
                _book.publish_date = QDate::fromString(_str, "yyyy-MM-dd");
                _book.description = _nodeList.at(i).toElement().elementsByTagName("description").at(0).toElement().text();
                qDebug() << _book.toString();
                _lst.append(_book);
            }

        }

    }

    return _lst;
}
