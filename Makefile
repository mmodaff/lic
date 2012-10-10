CC=g++
LINKER=ar cr
CFLAGS=-g -c -Wall
SOURCES=
ODIR=obj
CDIR=src/lic
OUTPUT=lic.a

SOURCES += lua_interface_number.cpp
SOURCES += lua_interface_string.cpp
SOURCES += registrant.cpp
SOURCES += string_registrant.cpp
SOURCES += util.cpp

HEADERS = $(shell find src -name *.h)
HEADERS += $(shell find src -name *.inl)

SRC := $(patsubst %, $(CDIR)/%, $(SOURCES))

OBJECTS=$(patsubst $(CDIR)/%,$(ODIR)/%,$(SRC:.cpp=.o))

ODIRS = $(sort $(dir $(OBJECTS)))

all: $(OUTPUT)

$(OUTPUT) : $(OBJECTS) Makefile
	$(LINKER) $@ $(OBJECTS)

$(ODIR)/%.o: $(CDIR)/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTS) : | $(ODIRS)

$(ODIRS):
	mkdir $@

.PHONY: clean

clean:
	rm -rf $(ODIR)
	rm -f $(OUTPUT)
