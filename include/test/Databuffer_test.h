#pragma once

#include <QObject>
#include "Databuffer.h"
#include <QString>


using namespace std;

class TestDatabuffer : public QObject {

    Q_OBJECT;

    Databuffer * cut_;

public:
    TestDatabuffer() : QObject(nullptr) {};

    const string TESTFILE_PATH = "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/testsound.mp3";
    const QString QTESTFILE_PATH = "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/testsound.mp3";

private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void init();
    void cleanup();

    // Test if the filepath will be set to an path of an existing file
    // Expected: getfilepath returns path given to constructor
    void testConstructorExistingFile_filepath();

    // Test if the filesize will be set correctly giving it an existing filepath
    // Expected: getfile_size returns 5 because we write 5 characters into the file
    void testConstructorExistingFile_filesize();

    // Test if the constructor sets filepath and file_size correctly when giving a not existing files path
    // Expected: filepath = nullptr
    void testConstructorNotExistingFile_filepath();

    // Test if the filesize will be set correctly giving it a not existing filepath
    // Expected: getfile_size returns 0 since the file doesn't exist
    void testConstructorNotExistingFile_filesize();



    // Test if the filepath will be set to an path of an existing file
    // Expected: getfilepath returns path given to constructor
    void testSetExistingFile_CorrectFilepath();

    // Test file_size is actual filesize of given filepath
    // Expected: getfile_size returns 5 because we write 5 characters into the file
    void testSetExistingFile_FileSizeIsActualFileSize();

    // Test if the filepath will be set to an path of a not existing file
    // Expected: getfilepath returns nullptr
    void testSetNotExistingFile_FilepathEmpty();

    // Test file_size is actual filesize of given filepath
    // Expected: getfile_size returns 0 since the file doesn't exist
    void testSetNotExistingFile_FileSizeZero();

    // Test if we can delete a file whose path we gave to the class
    // Expected: file should be deleted
    void testDeletingExistingFile();

};

