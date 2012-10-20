CC=g++
LINKER=ar cr
CFLAGS=-g -c -Wall -I../src
LDFLAGS=
SOURCES=
LIBS=
ODIR=obj
CDIR=src
OUTPUT=demo
DEPEND=depend.mk
RM = rm -f

SOURCES += derived_class.cpp
SOURCES += dummy_class.cpp
SOURCES += global_funcs.cpp
SOURCES += lic_derived_class.cpp
SOURCES += lic_dummy_class.cpp
SOURCES += lic_global_funcs.cpp
SOURCES += main.cpp

OBJECTS=$(patsubst %,$(ODIR)/%,$(SRC:.cpp=.o))

ODIRS = $(sort $(dir $(OBJECTS)))

SRC := $(patsubst %, $(CDIR)/%, $(SOURCES))

LIBS+=../lic.a
LIBS+=-llua

all: $(OUTPUT)

$(OUTPUT) : $(OBJECTS) Makefile
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

$(ODIR)/%.o: %.cpp $(DEPEND)
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTS) : | $(ODIRS)

$(ODIRS):
	mkdir -p $@

.PHONY: clean depend

depend: $(DEPEND)

clean:
	rm -rf $(ODIR)
	rm -f $(OUTPUT)

$(DEPEND): $(SRC)
	echo '#' > $(DEPEND)
	makedepend -- $(CFLAGS) -- $(SRC) -pobj/ -s# -f$(DEPEND)

include $(DEPEND)