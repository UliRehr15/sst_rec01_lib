TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # RELEASE is active
CONFIG    -= release  # DEBUG is active

CONFIG    += staticlib

INCLUDEPATH = ../Header

HEADERS		+=  ./header/sstRec01Lib.h

SOURCES		+=  sstRec01Lib.cpp

debug{
  TARGET		= sst_rec01_lib_d
}
release{
  TARGET		= sst_rec01_lib_r
}

DESTDIR     = ../libs

