CC=g++
LINKER=ar cr
CFLAGS=-g -c -Wall
SOURCES=
ODIR=obj
CDIR=src/lic
OUTPUT=lic.a
DEPEND=depend.mk

SOURCES += lua_interface_bool.cpp
SOURCES += lua_interface_number.cpp
SOURCES += lua_interface_string.cpp
SOURCES += registrant.cpp
SOURCES += string_registrant.cpp
SOURCES += util.cpp

SRC := $(patsubst %, $(CDIR)/%, $(SOURCES))

OBJECTS=$(patsubst %,$(ODIR)/%,$(SRC:.cpp=.o))

ODIRS = $(sort $(dir $(OBJECTS)))

all: $(OUTPUT)

$(OUTPUT) : $(OBJECTS) Makefile
	$(LINKER) $@ $(OBJECTS)

$(ODIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTS) : | $(ODIRS)

$(ODIRS):
	mkdir -p $@

.PHONY: clean

clean:
	rm -rf $(ODIR)
	rm -f $(OUTPUT)

depend: $(DEPEND)

$(DEPEND): $(SRC)
	echo '#' > $(DEPEND)
	makedepend -- $(CFLAGS) -- $(SRC) -pobj/ -s# -f$(DEPEND)

include $(DEPEND)
