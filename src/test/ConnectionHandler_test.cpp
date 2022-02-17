#include "test/ConnectionHandler_test.h"
#include "UpdateLed.h"
#include "test/Update_mockup.h"
#include <QtTest>
#include <QString>
#include <QDir>

void TestConnectionHandler::init()
{
    cut_ = new ConnectionHandler;
}

void TestConnectionHandler::cleanup()
{
    delete cut_;
    cut_ = 0;
}

void TestConnectionHandler::testSearchingForAnswer_emptyString()
{
    string answer = cut_->searchAnswer("testtest");
    qDebug() << QString::fromStdString(answer);
    QDir filepath(QString::fromStdString(answer));
    filepath.makeAbsolute();
    QVERIFY(answer == filepath.path().toStdString() );
}

void TestConnectionHandler::testSearchingForAnswer()
{
    string answer = cut_->searchAnswer("");
    QVERIFY(answer == "");
}

void TestConnectionHandler::testSearchingForUpdate()
{
    bool updateready = cut_->searchUpdate();
    QVERIFY(updateready == false);
}

void TestConnectionHandler::testUseUpdateClassToUpdateProgram()
{
    UpdateLed * led = new UpdateLed;
    Update_mockup * update = new Update_mockup;

    update->setUpdateLed(led);
    cut_->setUpdateObj(update);

    cut_->Update();

    QVERIFY(led->getstate() == true);

}
