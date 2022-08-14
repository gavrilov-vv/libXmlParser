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

                _lst.append(_book);
            }

        }

    }

    return _lst;
}

QList<Book> XmlParser::fetchBooks1(const QString &_data)
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

                QDomNodeList _childList = _nodeList.at(i).childNodes();

                for(int i=0; i < _childList.size(); i++)
                {
                    QDomElement _elem = _childList.item(i).toElement();

                    if(_elem.tagName() == "id")
                    {
                        _book.id = _elem.text();
                    }
                    else if(_elem.tagName() == "author")
                    {
                        _book.author = _elem.text();
                    }
                    else if(_elem.tagName() == "title")
                    {
                        _book.title = _elem.text();
                    }
                    else if(_elem.tagName() == "genre")
                    {
                        _book.genre = _elem.text();
                    }
                    else if(_elem.tagName() == "price")
                    {
                        _book.price = _elem.text().toFloat();
                    }
                    else if(_elem.tagName() == "publish_date")
                    {
                        QString _str = _elem.text();
                        _book.publish_date = QDate::fromString(_str, "yyyy-MM-dd");
                    }
                    else if(_elem.tagName() == "description")
                    {
                        _book.description = _elem.text();
                    }
                }

                _lst.append(_book);
            }

        }

    }

    return _lst;
}
