TEMPLATE	  = app
CONFIG	 	 += warn_on
CONFIG       -= qt
CONFIG       -= windows

# CONFIG       -= debug  # RELEASE is active
CONFIG       -= release  # DEBUG is active

INCLUDEPATH +=  ../header

debug{
  LIBS        += ../../libs/libsst_rec01_lib_d.a
}
release{
  
  win32-g++:QMAKE_LFLAGS += -static
  win32-g++:QMAKE_LFLAGS -= -mthreads
  win32-g++:QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
  win32-g++:QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads
  
  
  LIBS        += ../../libs/libsst_rec01_lib_r.a
}

# HEADERS    += ../../header/sst_rec01_lib.h

SOURCES    +=   sstRec01LibTest.cpp

TARGET	  	= sst_rec01_lib_test

