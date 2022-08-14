#include <QtTest>
#include <QString>
#include <QCoreApplication>
#include <QFuture>
#include <QFile>
#include <gsl/gsl_math.h>
#include <QDate>

#include "Models.h"
#include "XmlParser.h"

class TestXmlParser : public QObject
{
    Q_OBJECT

public:
    TestXmlParser();
    ~TestXmlParser();
    XmlParser *pXmlParser;


private slots:

    // Тестовые наборы
    void testParseCatalog();
    void testParseCatalog_data();

};

TestXmlParser::TestXmlParser()
{
    pXmlParser = new XmlParser(this);
}

TestXmlParser::~TestXmlParser()
{
    delete pXmlParser;
}


void TestXmlParser::testParseCatalog()
{
    QFETCH(QString, xmlstring);

    QList<Book> _books = pXmlParser->fetchBooks(xmlstring);

    QCOMPARE(_books.size(), 12);

    Book _b1 = _books.at(0);
    Book _b2 = _books.at(1);
    Book _b12 = _books.at(11);
    Book _b6 = _books.at(5);
    Book _b10 = _books.at(9);

    QCOMPARE(_b1.id, "bk101");
    QCOMPARE(_b2.id, "bk102");
    QCOMPARE(_b12.id, "bk112");
    QCOMPARE(_b6.publish_date.toString("yyyy-MM-dd"), "2000-09-02");
    QCOMPARE(_b10.publish_date.toString("yyyy-MM-dd"), "2000-12-09");

}

void TestXmlParser::testParseCatalog_data()
{
    QTest::addColumn<QString>("xmlstring");

    QFile _f(":/books.xml");

    _f.open(QFile::ReadOnly);

    QString _str = QString(_f.readAll());

    QTest::newRow("book_catalog")
            << (QString) _str;

    _f.close();
}

QTEST_MAIN(TestXmlParser)

#include "tst_testxmlparser.moc"
