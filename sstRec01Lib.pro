TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # RELEASE is active
CONFIG    -= release  # DEBUG is active

CONFIG    += staticlib

INCLUDEPATH = ./Header

HEADERS		+=  ./Header/sstRec01Lib.h
HEADERS		+= sstRec01LibInt.h

SOURCES		+=  sstRec01Lib.cpp
SOURCES		+=  sstRec01LibInt.cpp

OTHER_FILES += readme.txt

debug{
  TARGET		= sst_rec01_lib_d
}
release{
  TARGET		= sst_rec01_lib_r
}

DESTDIR     = ../libs

