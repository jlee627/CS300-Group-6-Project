#Makefile for Group6's ChocAn software
CC = g++
SRCDIR = src
BUILDDIR = build
TESTDIR = tests
TARGETDIR = bin
TARGET = $(TARGETDIR)/ChocAn
TESTTARGET = $(TARGETDIR)/Tests
INC = -I include
CFLAGS = -g -Wall
SRCEXT = cpp

#Commands to create the object file dependencies for the program and tests
HEADERS = $(shell find include -type f -name *.h)
SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp ! -name main.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TESTS = $(shell find $(TESTDIR) -type f -name *.cpp)
TESTOBJ = $(patsubst $(TESTDIR)/%,$(BUILDDIR)/%,$(TESTS:.$(SRCEXT)=.o))


#Default build target for the program
#Creates the ChocAn executable and any necessary folders
all: $(TARGETDIR) $(BUILDDIR) $(TARGET)

#Build target to run the tests for the ChocAn software
test: $(TARGETDIR) $(BUILDDIR) $(TESTTARGET)
	./$(TESTTARGET)

#Builds the ChocAn executable with dependencies for the 
#required .o files so that only the necessary .o files are
#recompiled when changes are made to the source files
$(TARGET): $(BUILDDIR)/main.o $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $<

#Builds the ChocAn test executable with 
#dependencies for the required .o files
$(TESTTARGET): $(TESTOBJ) $(OBJECTS)
	$(CC) -o ./$@ $(OBJECTS) $(TESTOBJ)

#Build targets for the src .o files
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

#Build targets for the test .o files
$(BUILDDIR)/%.o: $(TESTDIR)/%.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

#Creates the output directory if it doesn't exist
$(TARGETDIR):
	test -d $(TARGETDIR) || mkdir $(TARGETDIR)

#Creates the object file directory if it doesn't exist
$(BUILDDIR):
	test -d $(BUILDDIR) || mkdir $(BUILDDIR)

#Deletes the executable and object files
clean: 
	rm -f $(BUILDDIR)/* bin/*
