#include <QtTest>

// add necessary includes here

class CaseName : public QObject
{
    Q_OBJECT

public:
    CaseName();
    ~CaseName();

private slots:
    void test_case1();

};

CaseName::CaseName()
{

}

CaseName::~CaseName()
{

}

void CaseName::test_case1()
{

}

QTEST_APPLESS_MAIN(CaseName)

#include "tst_casename.moc"
