#include "test/FileInfoCollector_test.h"
//#include "test/Databuffer_mockup.h"
#include <QFile>

void TestFileInfoCollector::init()
{
    cut_ = new FileInfoCollector;
}

void TestFileInfoCollector::cleanup()
{
    delete cut_;
    cut_ = 0;
}

void TestFileInfoCollector::testSavingDatabuffer_GetFilepath()
{
    QFile file(QFILEPATH);
    file.open(QIODeviceBase::ReadWrite);
    file.close();

    cut_->save_file(FILEPATH);
    qDebug() << QString::fromStdString(FILEPATH);
    qDebug() << QString::fromStdString(cut_->get_filepath());
    QVERIFY(cut_->get_filepath() == FILEPATH);

    file.remove();
}

void TestFileInfoCollector::testSavingDatabuffer_GetFilesize()
{
    QFile file(QFILEPATH);
    file.open(QIODeviceBase::ReadWrite);
    file.write("12345",5);
    file.close();

    cut_->save_file(FILEPATH);

    QVERIFY(cut_->getfile_size() == 5);

    file.remove();
}

void TestFileInfoCollector::testPopBackFile_GetFilepath()
{
    QFile file(QFILEPATH);
    file.open(QIODeviceBase::ReadWrite);
    file.close();

    QFile file2(QFILEPATH2);
    file2.open(QIODeviceBase::ReadWrite);
    file2.close();

    cut_->save_file(FILEPATH);
    cut_->save_file(FILEPATH2);

    cut_->pop_back();

    QVERIFY(cut_->get_filepath() == FILEPATH);

    file.remove();
    file2.remove();
}

void TestFileInfoCollector::testPopBackFile_GetFilesize()
{
    QFile file(QFILEPATH);
    file.open(QIODeviceBase::ReadWrite);
    file.write("12345",5);
    file.close();

    QFile file2(QFILEPATH2);
    file2.open(QIODeviceBase::ReadWrite);
    file2.write("123",3);
    file2.close();

    cut_->save_file(FILEPATH);
    cut_->save_file(FILEPATH2);

    cut_->pop_back();

    QVERIFY(cut_->getfile_size() == 5);

    file.remove();
    file2.remove();
}


void TestFileInfoCollector::testRemoveDatabufferByPathFromCollection()
{
    QFile file(QFILEPATH);
    file.open(QIODeviceBase::ReadWrite);
    file.write("12345",5);
    file.close();

    QFile file2(QFILEPATH2);
    file2.open(QIODeviceBase::ReadWrite);
    file2.write("123",3);
    file2.close();

    cut_->save_file(FILEPATH);
    cut_->save_file(FILEPATH2);

    cut_->remove(FILEPATH2);

    QVERIFY(cut_->get_filepath() == FILEPATH);

    file.remove();
    file2.remove();
}
