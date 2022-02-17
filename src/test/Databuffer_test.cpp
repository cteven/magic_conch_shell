#include "test/Databuffer_test.h"
#include <QtTest>
#include <QFile>
#include <QDebug>

void TestDatabuffer::init()
{
    cut_ = new Databuffer("");
}

void TestDatabuffer::cleanup()
{
    delete cut_;
    cut_ = 0;
}

void TestDatabuffer::testConstructorExistingFile_filepath()
{
    delete cut_;

    QFile file(QTESTFILE_PATH);
    // creating file
    file.open(QIODeviceBase::ReadWrite);
    file.close();

    cut_ = new Databuffer(TESTFILE_PATH);

    QVERIFY(cut_->get_filepath() == TESTFILE_PATH);
    file.remove();
}

void TestDatabuffer::testConstructorExistingFile_filesize()
{
    delete cut_;

    QFile file(QTESTFILE_PATH);
    // creating file
    file.open(QIODeviceBase::ReadWrite);
    file.write("12345",5);
    file.close();

    cut_ = new Databuffer(TESTFILE_PATH);

    QVERIFY(cut_->getfile_size() == file.size());
    file.remove();
}

void TestDatabuffer::testConstructorNotExistingFile_filepath()
{
    delete cut_;

    cut_ = new Databuffer(TESTFILE_PATH);

    QVERIFY(cut_->get_filepath().empty());
}

void TestDatabuffer::testConstructorNotExistingFile_filesize()
{

    delete cut_;

    cut_ = new Databuffer(TESTFILE_PATH);

    QVERIFY(cut_->getfile_size() == 0);
}

void TestDatabuffer::testSetExistingFile_CorrectFilepath()
{
    QFile file(QTESTFILE_PATH);
    // creating file
    file.open(QIODeviceBase::ReadWrite);
    file.close();

    cut_->set_filepath(TESTFILE_PATH);

    QVERIFY(cut_->get_filepath() == TESTFILE_PATH);
    file.remove();
}

void TestDatabuffer::testSetExistingFile_FileSizeIsActualFileSize()
{
    QFile file(QTESTFILE_PATH);
    // creating file
    file.open(QIODeviceBase::ReadWrite);
    file.write("12345",5);
    file.close();

    cut_ = new Databuffer(TESTFILE_PATH);

    QVERIFY(cut_->getfile_size() == 5);
    file.remove();
}

void TestDatabuffer::testSetNotExistingFile_FilepathEmpty()
{
    cut_->set_filepath(TESTFILE_PATH);

    QVERIFY(cut_->get_filepath().empty());
}

void TestDatabuffer::testSetNotExistingFile_FileSizeZero()
{
    cut_->set_filepath(TESTFILE_PATH);

    QVERIFY(cut_->getfile_size() == 0);
}

void TestDatabuffer::testDeletingExistingFile()
{
    delete cut_;

    QFile file(QTESTFILE_PATH);
    // creating file
    file.open(QIODeviceBase::ReadWrite);
    file.close();

    cut_ = new Databuffer(TESTFILE_PATH);

    cut_->delete_file();

    QVERIFY(file.exists() == false);
}
