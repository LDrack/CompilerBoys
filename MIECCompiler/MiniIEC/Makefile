############################################################################
# Workfile: Makefile
# Author: Daniel Giritzer, S1810567004 (daniel@giritzer.eu)
# Date: 03.12.2018
# Description: Universal Makefile for Unix based Operating Systems, builds project for linux and windows
# (to install all dependencies: sudo apt install build-essential, coco-cpp, mingw-w64)
############################################################################

###################################
#GENERAL | EDIT 1/7
###################################
WORKDIR = $(shell pwd)
SOURCES := $(shell ls *.cpp)
PROJNAME = MIECCompiler
LIBDIR =
INC =
LDFLAGS = -std=c++11 -static-libstdc++ -static-libgcc -Wl,-Bstatic -pthread
CFLAGS = -Wall -fexceptions -std=c++11 -static-libstdc++ -static-libgcc
LIB=

# COCO
COCOCPP=Coco
COCOATG=$(WORKDIR)/MIEC.atg
COCOFRAMES=/usr/share/coco-cpp

###################################
#GCC | EDIT 2/7
###################################
CC_GCC = gcc
CXX_GCC = g++
AR_GCC = ar
LD_GCC = g++
WINDRES_GCC =

INC_GCC = $(INC)
LIBDIR_GCC =
CFLAGS_GCC = $(CFLAGS)
RESINC_GCC =
LDFLAGS_GCC = $(LDFLAGS)
LIB_GCC = $(LIB) -lm -lc -lrt -Wl,-Bdynamic -lpthread -ldl

###################################
#MinGW | EDIT 3/7
###################################
CC_WIN = i686-w64-mingw32-gcc
CXX_WIN = i686-w64-mingw32-g++
AR_WIN = i686-w64-mingw32-ar
LD_WIN = i686-w64-mingw32-g++
WINDRES_WIN = i686-w64-mingw32-windres

INC_WIN = $(INC)
LIBDIR_WIN =
CFLAGS_WIN = $(CFLAGS) -mconsole -DWIN32 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64
RESINC_WIN =
LDFLAGS_WIN =  $(LDFLAGS) -static
LIB_WIN = $(LIB) -static -mconsole -lole32 -luuid -lcomctl32 -lpthread

###################################
#RELEASE GCC SETTINGS | EDIT: 4/7
###################################
INC_RELEASE_GCC = $(INC_GCC)
CFLAGS_RELEASE_GCC = $(CFLAGS_GCC) -O2
RESINC_RELEASE_GCC = $(RESINC_GCC)
RCFLAGS_RELEASE_GCC = $(RCFLAGS_GCC)
LIBDIR_RELEASE_GCC = $(LIBDIR_GCC)
LIB_RELEASE_GCC = $(LIB_GCC)
LDFLAGS_RELEASE_GCC = $(LDFLAGS_GCC) -s
OBJDIR_RELEASE_GCC = obj/Release_Linux
DEP_RELEASE_GCC =
OUT_RELEASE_GCC = bin/Release_Linux

###################################
#DEBUG GCC SETTINGS | EDIT: 5/7
###################################
INC_DEBUG_GCC = $(INC_GCC)
CFLAGS_DEBUG_GCC = $(CFLAGS_GCC) -g
RESINC_DEBUG_GCC = $(RESINC_GCC)
RCFLAGS_DEBUG_GCC = $(RCFLAGS_GCC)
LIBDIR_DEBUG_GCC = $(LIBDIR_GCC)
LIB_DEBUG_GCC = $(LIB_GCC)
LDFLAGS_DEBUG_GCC = $(LDFLAGS_GCC)
OBJDIR_DEBUG_GCC = obj/Debug_Linux
DEP_DEBUG_GCC =
OUT_DEBUG_GCC = bin/Debug_Linux

###################################
#RELEASE MinGW SETTINGS | EDIT: 6/7
###################################
INC_RELEASE_WIN = $(INC_WIN)
CFLAGS_RELEASE_WIN = $(CFLAGS_WIN) -O2
RESINC_RELEASE_WIN = $(RESINC_WIN)
RCFLAGS_RELEASE_WIN = $(RCFLAGS_WIN)
LIBDIR_RELEASE_WIN = $(LIBDIR_WIN)
LIB_RELEASE_WIN = $(LIB_WIN)
LDFLAGS_RELEASE_WIN = $(LDFLAGS_WIN) -s
OBJDIR_RELEASE_WIN = obj/Release_Windows
DEP_RELEASE_WIN =
OUT_RELEASE_WIN = bin/Release_Windows

###################################
#DEBUG MinGW SETTINGS | EDIT: 7/7
###################################
INC_DEBUG_WIN = $(INC_WIN)
CFLAGS_DEBUG_WIN = $(CFLAGS_WIN) -g
RESINC_DEBUG_WIN = $(RESINC_WIN)
RCFLAGS_DEBUG_WIN = $(RCFLAGS_WIN)
LIBDIR_DEBUG_WIN = $(LIBDIR_WIN)
LIB_DEBUG_WIN = $(LIB_WIN)
LDFLAGS_DEBUG_WIN = $(LDFLAGS_WIN)
OBJDIR_DEBUG_WIN = obj/Debug_Windows
DEP_DEBUG_WIN =
OUT_DEBUG_WIN = bin/Debug_Windows

############################
#OBJECT LISTS | DO NOT EDIT!
############################
OBJ_DEBUG_GCC = $(addprefix $(OBJDIR_DEBUG_GCC)/,$(SOURCES:%.cpp=%.o))
OBJ_RELEASE_GCC = $(addprefix $(OBJDIR_RELEASE_GCC)/,$(SOURCES:%.cpp=%.o))
OBJ_DEBUG_WIN = $(addprefix $(OBJDIR_DEBUG_WIN)/,$(SOURCES:%.cpp=%.o))
OBJ_RELEASE_WIN = $(addprefix $(OBJDIR_RELEASE_WIN)/,$(SOURCES:%.cpp=%.o))

##########################
#FUNCTIONS | DO NOT EDIT!
##########################

######## General
all: make_coco debug release
clean: clean_debug_linux clean_release_linux clean_debug_windows clean_release_windows
rebuild: clean debug release

debug Debug: debug_linux debug_windows
release Release:  release_linux release_windows

######## COCO\R
make_coco:
	$(COCOCPP) $(COCOATG) -o $(WORKDIR) -namespace MIEC -frames $(COCOFRAMES)

######## DEBUG GCC
before_debug_linux:
	test -d $(OUT_DEBUG_GCC) || mkdir -p $(OUT_DEBUG_GCC)
	test -d $(OBJDIR_DEBUG_GCC) || mkdir -p $(OBJDIR_DEBUG_GCC)

after_debug_linux:

debug_linux: before_debug_linux out_debug_linux after_debug_linux

out_debug_linux: before_debug_linux $(OBJ_DEBUG_GCC) $(DEP_DEBUG_GCC)
	$(LD_GCC) $(LDFLAGS_DEBUG_GCC) $(LIBDIR_GCC) $(LIBDIR_DEBUG_GCC) $(OBJ_DEBUG_GCC) $(LIB_DEBUG_GCC)  -o $(OUT_DEBUG_GCC)/$(PROJNAME)

$(OBJDIR_DEBUG_GCC)/%.o: %.cpp
	$(CXX_GCC) $(CFLAGS_DEBUG_GCC) $(INC_DEBUG_GCC) -c $< -D_DEBUG -o $@

clean_debug_linux:
	rm -f $(OBJ_DEBUG_GCC) $(OUT_DEBUG_GCC)/$(PROJNAME)
	rm -rf $(OUT_DEBUG_GCC)
	rm -rf $(OBJDIR_DEBUG_GCC)

######## RELEASE GCC
before_release_linux:
	test -d $(OUT_RELEASE_GCC) || mkdir -p $(OUT_RELEASE_GCC)
	test -d $(OBJDIR_RELEASE_GCC) || mkdir -p $(OBJDIR_RELEASE_GCC)

after_release_linux:

release_linux: before_release_linux out_release_linux after_release_linux

out_release_linux: before_release_linux $(OBJ_RELEASE_GCC) $(DEP_RELEASE_GCC)
	$(LD_GCC) $(LDFLAGS_RELEASE_GCC) $(LIBDIR_GCC) $(LIBDIR_RELEASE_GCC) $(OBJ_RELEASE_GCC) $(LIB_RELEASE_GCC)  -o $(OUT_RELEASE_GCC)/$(PROJNAME)

$(OBJDIR_RELEASE_GCC)/%.o: %.cpp
	$(CXX_GCC) $(CFLAGS_RELEASE_GCC) $(INC_RELEASE_GCC) -c $< -D_RELEASE -o $@

clean_release_linux:
	rm -f $(OBJ_RELEASE_GCC) $(OUT_RELEASE_GCC)/$(PROJNAME)
	rm -rf $(OUT_RELEASE_GCC)
	rm -rf $(OBJDIR_RELEASE_GCC)

######## DEBUG WIN
before_debug_windows:
	test -d $(OUT_DEBUG_WIN) || mkdir -p $(OUT_DEBUG_WIN)
	test -d $(OBJDIR_DEBUG_WIN) || mkdir -p $(OBJDIR_DEBUG_WIN)
	$(WINDRES_WIN) main.rc $(OBJDIR_DEBUG_WIN)/mainres.o

after_debug_windows:

debug_windows: before_debug_windows out_debug_windows after_debug_windows

out_debug_windows: before_debug_windows $(OBJ_DEBUG_WIN) $(DEP_DEBUG_WIN)
	$(LD_WIN) $(LDFLAGS_DEBUG_WIN) $(LIBDIR_WIN) $(LIBDIR_DEBUG_WIN) $(OBJ_DEBUG_WIN) $(OBJDIR_DEBUG_WIN)/mainres.o $(LIB_DEBUG_WIN)  -o $(OUT_DEBUG_WIN)/$(PROJNAME).exe

$(OBJDIR_DEBUG_WIN)/%.o: %.cpp
	$(CXX_WIN) $(CFLAGS_DEBUG_WIN) $(INC_DEBUG_WIN) -c $< -D_DEBUG -o $@

clean_debug_windows:
	rm -f $(OBJ_DEBUG_WIN) $(OUT_DEBUG_WIN)/$(PROJNAME).exe
	rm -rf $(OUT_DEBUG_WIN)
	rm -rf $(OBJDIR_DEBUG_WIN)

######## RELEASE WIN
before_release_windows:
	test -d $(OUT_RELEASE_WIN) || mkdir -p $(OUT_RELEASE_WIN)
	test -d $(OBJDIR_RELEASE_WIN) || mkdir -p $(OBJDIR_RELEASE_WIN)
	$(WINDRES_WIN) main.rc $(OBJDIR_RELEASE_WIN)/mainres.o

after_release_windows:

release_windows: before_release_windows out_release_windows after_release_windows

out_release_windows: before_release_windows $(OBJ_RELEASE_WIN) $(DEP_RELEASE_WIN)
	$(LD_WIN) $(LDFLAGS_RELEASE_WIN) $(LIBDIR_WIN) $(LIBDIR_RELEASE_WIN) $(OBJ_RELEASE_WIN) $(OBJDIR_RELEASE_WIN)/mainres.o $(LIB_RELEASE_WIN)  -o $(OUT_RELEASE_WIN)/$(PROJNAME).exe

$(OBJDIR_RELEASE_WIN)/%.o: %.cpp
	$(CXX_WIN) $(CFLAGS_RELEASE_WIN) $(INC_RELEASE_WIN) -c $< -D_RELEASE -o $@

clean_release_windows:
	rm -f $(OBJ_RELEASE_WIN) $(OUT_RELEASE_WIN)/$(PROJNAME).exe
	rm -rf $(OUT_RELEASE_WIN)
	rm -rf $(OBJDIR_RELEASE_WIN)

.PHONY: before_debug_linux out_debug_linux after_debug_linux before_release_linux out_release_linux after_release_linux before_debug_windows out_debug_windows after_debug_windows before_release_windows out_release_windows after_release_windows
