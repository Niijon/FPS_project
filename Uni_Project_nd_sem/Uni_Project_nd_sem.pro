TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CameraComponent.cpp \
        ChasingCube.cpp \
        MapBlocks.cpp \
        Maze.cpp \
        MazeExplorer.cpp \
        Structures.cpp \
        main.cpp

HEADERS += \
    CameraComponent.h \
    ChasingCube.h \
    MapBlocks.h \
    Maze.h \
    MazeExplorer.h \
    Structures.h

LIBS += -L"N:/SFML-2.5.1/lib"

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

LIBS += -lOpenGL32 -lglu32



INCLUDEPATH += "N:/SFML-2.5.1/include"
DEPENDPATH += "N:/SFML-2.5.1/include"
