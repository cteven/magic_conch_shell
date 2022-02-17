QT       += core multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt

INCLUDEPATH += $$PWD/include


test {
    message(Test build)

    QT += testlib
    TARGET = demo-test

    SOURCES += \
        src/test/main.cpp   \
        src/test/Battery_test.cpp   \
        src/test/BatteryLed_test.cpp    \
        src/test/Battery_mockup.cpp     \
        src/test/ConnectionHandler_test.cpp \
        src/test/Databuffer_mockup.cpp \
        src/test/FileInfoCollector_mockup.cpp \
        src/test/Update_mockup.cpp  \
        src/test/Databuffer_test.cpp \
        src/test/FileInfoCollector_test.cpp \
        src/test/Speaker_test.cpp   \
        src/test/Microphone_mockup.cpp \
        src/test/Speechassistant_test.cpp   \
        src/test/Microphone_test.cpp    \
        src/Microphone.cpp    \
        src/Speaker.cpp \
        src/BatteryLed.cpp \
        src/Battery.cpp \
        src/Databuffer.cpp \
        src/ConnectionHandler.cpp \
        src/UpdateLed.cpp  \
        src/FileInfoCollector.cpp \
        src/Update.cpp \
        src/Speechassistant.cpp \
        src/StateLed.cpp


    HEADERS += \
        include/test/Battery_mockup.h   \
        include/test/Battery_test.h \
        include/test/BatteryLed_test.h    \
        include/test/ConnectionHandler_test.h \
        include/test/Databuffer_mockup.h \
        include/test/Databuffer_test.h \
        include/test/FileInfoCollector_mockup.h \
        include/test/Update_mockup.h \
        include/test/commons.h  \
        include/test/FileInfoCollector_test.h   \
        include/test/Speaker_test.h \
        include/test/Microphone_test.h  \
        include/test/Microphone_mockup.h \
        include/test/Speechassistant_test.h \
        include/BaseBattery.h \
        include/BaseDatabuffer.h \
        include/Battery.h \
        include/Databuffer.h \
        include/BaseUpdate.h \
        include/UpdateLed.h \
        include/Update.h    \
        include/FileInfoCollector.h \
        include/Microphone.h    \
        include/Speaker.h   \
        include/BatteryLed.h    \
        include/ConnectionHandler.h \
        include/Connector.h \
        include/Speechassistant.h \
        include/BaseMicrophone.h \
        include/Microphone.h \
        include/Speechassistant.h \
        include/StateLed.h


} gui {

    QT += gui

    TARGET = gui_prog

    message(GUI build)

SOURCES += \
        src/gui/main.cpp \
        src/gui/mainwindow.cpp \
        src/Microphone.cpp    \
        src/Speaker.cpp \
        src/BatteryLed.cpp \
        src/Battery.cpp \
        src/Databuffer.cpp \
        src/ConnectionHandler.cpp \
        src/UpdateLed.cpp  \
        src/FileInfoCollector.cpp \
        src/Update.cpp \
        src/StateLed.cpp    \
        src/Button.cpp  \
        src/Cord.cpp  \
        src/Physics.cpp  \
        src/Speechassistant.cpp \
        src/SensorControl.cpp

HEADERS += \
        include/BaseBattery.h \
        include/BaseDatabuffer.h \
        include/Battery.h \
        include/Databuffer.h \
        include/BaseUpdate.h \
        include/UpdateLed.h \
        include/Update.h    \
        include/FileInfoCollector.h \
        include/Microphone.h    \
        include/Speaker.h   \
        include/BatteryLed.h    \
        include/ConnectionHandler.h \
        include/Connector.h \
        include/Speechassistant.h \
        include/BaseMicrophone.h \
        include/Microphone.h \
        include/StateLed.h  \
        include/Button.h  \
        include/commons.h  \
        include/Cord.h  \
        include/Physics.h  \
        include/Speechassistant.h \
        include/SensorControl.h  \
        include/gui/mainwindow.h

FORMS += \
    forms/mainwindow.ui

RESOURCES += \
    pic.qrc

} else {

    TARGET = default_prog

    message(Normal build)

    SOURCES += \
            src/main.cpp \
            src/Microphone.cpp    \
            src/Speaker.cpp \
            src/BatteryLed.cpp \
            src/Battery.cpp \
            src/Databuffer.cpp \
            src/ConnectionHandler.cpp \
            src/UpdateLed.cpp  \
            src/FileInfoCollector.cpp \
            src/Update.cpp \
            src/StateLed.cpp    \
            src/Button.cpp  \
            src/Cord.cpp  \
            src/Physics.cpp  \
            src/Speechassistant.cpp \
            src/SensorControl.cpp

    HEADERS += \
        include/BaseBattery.h \
        include/BaseDatabuffer.h \
        include/Battery.h \
        include/Databuffer.h \
        include/BaseUpdate.h \
        include/UpdateLed.h \
        include/Update.h    \
        include/FileInfoCollector.h \
        include/Microphone.h    \
        include/Speaker.h   \
        include/BatteryLed.h    \
        include/ConnectionHandler.h \
        include/Connector.h \
        include/Speechassistant.h \
        include/BaseMicrophone.h \
        include/Microphone.h \
        include/StateLed.h  \
        include/Button.h  \
        include/commons.h  \
        include/Cord.h  \
        include/Physics.h  \
        include/Speechassistant.h \
        include/SensorControl.h  \
}

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


