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

SRC := $(patsubst %, $(CDIR)/%, $(SOURCES))

OBJECTS=$(patsubst %,$(ODIR)/%,$(SRC:.cpp=.o))

ODIRS = $(sort $(dir $(OBJECTS)))

all: $(OUTPUT)

$(OUTPUT) : $(OBJECTS) Makefile
	$(LINKER) $@ $(OBJECTS)

$(ODIR)/%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTS) : | $(ODIRS)

$(ODIRS):
	mkdir -p $@

.PHONY: clean depend

clean:
	rm -rf $(ODIR)
	rm -f $(OUTPUT)

depend:
	makedepend -- $(CFLAGS) -- $(SRC) -p$(ODIR)/

# DO NOT DELETE THIS LINE -- make depend depends on it.

obj/src/lic/lua_interface_number.o: src/lic/lua_interface_number.h
obj/src/lic/lua_interface_number.o: src/lic/lua_interface_default.h
obj/src/lic/lua_interface_number.o: src/lic/lua_interface_base.h
obj/src/lic/lua_interface_number.o: src/lic/lua_wrapper.h /usr/include/lua.h
obj/src/lic/lua_interface_number.o: /usr/include/luaconf.h
obj/src/lic/lua_interface_number.o: /usr/include/limits.h
obj/src/lic/lua_interface_number.o: /usr/include/features.h
obj/src/lic/lua_interface_number.o: /usr/include/sys/cdefs.h
obj/src/lic/lua_interface_number.o: /usr/include/sys/features.h
obj/src/lic/lua_interface_number.o: /usr/include/lauxlib.h
obj/src/lic/lua_interface_number.o: /usr/include/stdio.h /usr/include/_ansi.h
obj/src/lic/lua_interface_number.o: /usr/include/newlib.h
obj/src/lic/lua_interface_number.o: /usr/include/sys/config.h
obj/src/lic/lua_interface_number.o: /usr/include/machine/ieeefp.h
obj/src/lic/lua_interface_number.o: /usr/include/sys/reent.h
obj/src/lic/lua_interface_number.o: /usr/include/sys/_types.h
obj/src/lic/lua_interface_number.o: /usr/include/machine/_types.h
obj/src/lic/lua_interface_number.o: /usr/include/machine/_default_types.h
obj/src/lic/lua_interface_number.o: /usr/include/sys/lock.h
obj/src/lic/lua_interface_number.o: /usr/include/sys/types.h
obj/src/lic/lua_interface_number.o: /usr/include/machine/types.h
obj/src/lic/lua_interface_number.o: /usr/include/sys/stdio.h
obj/src/lic/lua_interface_string.o: src/lic/lua_interface_string.h
obj/src/lic/lua_interface_string.o: src/lic/lua_interface_default.h
obj/src/lic/lua_interface_string.o: src/lic/lua_interface_base.h
obj/src/lic/lua_interface_string.o: src/lic/lua_wrapper.h /usr/include/lua.h
obj/src/lic/lua_interface_string.o: /usr/include/luaconf.h
obj/src/lic/lua_interface_string.o: /usr/include/limits.h
obj/src/lic/lua_interface_string.o: /usr/include/features.h
obj/src/lic/lua_interface_string.o: /usr/include/sys/cdefs.h
obj/src/lic/lua_interface_string.o: /usr/include/sys/features.h
obj/src/lic/lua_interface_string.o: /usr/include/lauxlib.h
obj/src/lic/lua_interface_string.o: /usr/include/stdio.h /usr/include/_ansi.h
obj/src/lic/lua_interface_string.o: /usr/include/newlib.h
obj/src/lic/lua_interface_string.o: /usr/include/sys/config.h
obj/src/lic/lua_interface_string.o: /usr/include/machine/ieeefp.h
obj/src/lic/lua_interface_string.o: /usr/include/sys/reent.h
obj/src/lic/lua_interface_string.o: /usr/include/sys/_types.h
obj/src/lic/lua_interface_string.o: /usr/include/machine/_types.h
obj/src/lic/lua_interface_string.o: /usr/include/machine/_default_types.h
obj/src/lic/lua_interface_string.o: /usr/include/sys/lock.h
obj/src/lic/lua_interface_string.o: /usr/include/sys/types.h
obj/src/lic/lua_interface_string.o: /usr/include/machine/types.h
obj/src/lic/lua_interface_string.o: /usr/include/sys/stdio.h
obj/src/lic/registrant.o: src/lic/registrant.h
obj/src/lic/string_registrant.o: src/lic/string_registrant.h
obj/src/lic/string_registrant.o: src/lic/registrant.h /usr/include/string.h
obj/src/lic/string_registrant.o: /usr/include/_ansi.h /usr/include/newlib.h
obj/src/lic/string_registrant.o: /usr/include/sys/config.h
obj/src/lic/string_registrant.o: /usr/include/machine/ieeefp.h
obj/src/lic/string_registrant.o: /usr/include/sys/features.h
obj/src/lic/string_registrant.o: /usr/include/sys/reent.h
obj/src/lic/string_registrant.o: /usr/include/sys/_types.h
obj/src/lic/string_registrant.o: /usr/include/machine/_types.h
obj/src/lic/string_registrant.o: /usr/include/machine/_default_types.h
obj/src/lic/string_registrant.o: /usr/include/sys/lock.h
obj/src/lic/string_registrant.o: /usr/include/sys/cdefs.h
obj/src/lic/string_registrant.o: /usr/include/sys/string.h
obj/src/lic/util.o: src/lic/util.h /usr/include/lua.h /usr/include/luaconf.h
obj/src/lic/util.o: /usr/include/limits.h /usr/include/features.h
obj/src/lic/util.o: /usr/include/sys/cdefs.h /usr/include/sys/features.h
obj/src/lic/util.o: /usr/include/lauxlib.h /usr/include/stdio.h
obj/src/lic/util.o: /usr/include/_ansi.h /usr/include/newlib.h
obj/src/lic/util.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
obj/src/lic/util.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
obj/src/lic/util.o: /usr/include/machine/_types.h
obj/src/lic/util.o: /usr/include/machine/_default_types.h
obj/src/lic/util.o: /usr/include/sys/lock.h /usr/include/sys/types.h
obj/src/lic/util.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
