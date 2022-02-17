#pragma once

#include <QtTest>
#include <QObject>
#include <QString>
#include "FileInfoCollector.h"

class TestFileInfoCollector : public QObject
{
    Q_OBJECT;

    FileInfoCollector * cut_;

public:
    TestFileInfoCollector() : QObject(nullptr) {};

    const string FILEPATH = "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/FICtestsound.mp3";
    const QString QFILEPATH = "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/FICtestsound.mp3";

    const string FILEPATH2 = "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/FICtestsound2.mp3";
    const QString QFILEPATH2 = "C:/Users/Steven/Documents/studium/5. Sem/se2/qt_projekte/magische-miesmuschel/sounds/FICtestsound2.mp3";

private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void init();
    void cleanup();

    void testSavingDatabuffer_GetFilepath();

    void testSavingDatabuffer_GetFilesize();

    void testPopBackFile_GetFilepath();

    void testPopBackFile_GetFilesize();

    //void testRemoveDatabufferFromCollection();

    void testRemoveDatabufferByPathFromCollection();

};
