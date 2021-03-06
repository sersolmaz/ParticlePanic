TEMPLATE = app
TARGET = ParticlePanic
CONFIG += c++11
CONFIG += opengl
INCLUDEPATH += .
OBJECTS_DIR = obj

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    src/Vec3.cpp \
    src/Mat3.cpp \
    src/Particle.cpp \
    src/World.cpp \
    src/Toolbar.cpp \
    src/ParticleProperties.cpp \
    src/Main.cpp \
    src/MarchingAlgorithms.cpp

HEADERS += \
    include/Particle.h \
    include/Vec3.h \
    include/Mat3.h \
    include/World.h \
    include/Toolbar.h \
    include/ParticleProperties.h \
    include/Commands.h \
    include/MarchingAlgorithms.h

LIBS += -L/usr/local/lib

linux: {
  LIBS+=$$system(sdl2-config --libs)
  LIBS += -lSDL2  -lGLU -lGL -lSDL2_image  -L/usr/local/lib/ #-lglut #-lGLEW
}

macx: {
  DEFINES+=MAC_OS_X_VERSION_MIN_REQUIRED=1060
  QMAKE_LFLAGS += -F/Library/Frameworks
  LIBS += -framework SDL2
  LIBS += -framework SDL2_image
  INCLUDEPATH += /Library/Frameworks/SLD2_image.framework
  INCLUDEPATH += /Library/Frameworks/SDL2.framework/Headers
  INCLUDEPATH += /usr/local/include
  INCLUDEPATH += /usr/local/Cellar

  LIBS+= -framework OpenGL
  LIBS+= -framework GLUT
}
