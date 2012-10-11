CC=g++ -I../src
LINKER=ar cr
CFLAGS=-g -c -Wall
LDFLAGS=
SOURCES=
LIBS=
ODIR=obj
CDIR=src
OUTPUT=demo

SOURCES += derived_class.cpp
SOURCES += dummy_class.cpp
SOURCES += global_funcs.cpp
SOURCES += lic_derived_class.cpp
SOURCES += lic_dummy_class.cpp
SOURCES += lic_global_funcs.cpp
SOURCES += main.cpp

HEADERS = $(shell find $(CDIR) -name *.h)

OBJECTS=$(patsubst $(CDIR)/%,$(ODIR)/%,$(SRC:.cpp=.o))

ODIRS = $(sort $(dir $(OBJECTS)))

SRC := $(patsubst %, $(CDIR)/%, $(SOURCES))

LIBS+=../lic.a
LIBS+=-llua

all: $(OUTPUT)

$(OUTPUT) : $(OBJECTS) Makefile
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

$(ODIR)/%.o: $(CDIR)/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTS) : | $(ODIRS)

$(ODIRS):
	mkdir $@

.PHONY: clean

clean:
	rm -rf $(ODIR)
	rm -f $(OUTPUT)
