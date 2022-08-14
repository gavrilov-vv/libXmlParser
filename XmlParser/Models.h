#ifndef MODELS_H
#define MODELS_H

#include <QObject>
#include <QDataStream>
#include <QDate>

#include "global_defs.h"

/*!
 * \brief Класс предметной области
 * для описания книг из каталога
 */
class Book
{
public:
    Book() :
        id{"UNDEF"},
        author{"UNDEF"},
        title{"UNDEF"},
        genre{"UNDEF"},
        price{0.0},
        publish_date{QDate()},
        description("UNDEF")
    {

    }

    QString id;          /*!< id */
    QString author;      /*!< Автор */
    QString title;       /*!< Название */
    QString genre;       /*!< Жанр */
    float price;         /*!< Цена */
    QDate publish_date;  /*!< Дата публикации */
    QString description; /*!< Краткое описание */

    QString toString()
    {
        QString _str = "id=%1; "
                       "author=%2; "
                       "title=%3; "
                       "genre=%4; "
                       "price=%5; "
                       "publish_date=%6; "
                       "description=%7";

        return _str.arg(id)
                   .arg(author)
                   .arg(title)
                   .arg(genre)
                   .arg(price)
                   .arg(publish_date.toString("yyyy-MM-dd"))
                   .arg(description);
    }

};


#endif // MODELS_H
