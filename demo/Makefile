CC=g++
LINKER=ar cr
CFLAGS=-g -c -Wall -I../src
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

OBJECTS=$(patsubst %,$(ODIR)/%,$(SRC:.cpp=.o))

ODIRS = $(sort $(dir $(OBJECTS)))

SRC := $(patsubst %, $(CDIR)/%, $(SOURCES))

LIBS+=../lic.a
LIBS+=-llua

all: $(OUTPUT)

$(OUTPUT) : $(OBJECTS) Makefile
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

$(ODIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTS) : | $(ODIRS)

$(ODIRS):
	mkdir $@

.PHONY: clean depend

depend:
	makedepend -- $(CFLAGS) -- $(SRC) -p$(ODIR)/

clean:
	rm -rf $(ODIR)
	rm -f $(OUTPUT)

# DO NOT DELETE THIS LINE -- make depend depends on it.

obj/src/derived_class.o: src/derived_class.h src/dummy_class.h
obj/src/derived_class.o: /usr/include/stdio.h /usr/include/_ansi.h
obj/src/derived_class.o: /usr/include/newlib.h /usr/include/sys/config.h
obj/src/derived_class.o: /usr/include/machine/ieeefp.h
obj/src/derived_class.o: /usr/include/sys/features.h /usr/include/sys/reent.h
obj/src/derived_class.o: /usr/include/sys/_types.h
obj/src/derived_class.o: /usr/include/machine/_types.h
obj/src/derived_class.o: /usr/include/machine/_default_types.h
obj/src/derived_class.o: /usr/include/sys/lock.h /usr/include/sys/types.h
obj/src/derived_class.o: /usr/include/machine/types.h
obj/src/derived_class.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
obj/src/dummy_class.o: src/dummy_class.h /usr/include/stdio.h
obj/src/dummy_class.o: /usr/include/_ansi.h /usr/include/newlib.h
obj/src/dummy_class.o: /usr/include/sys/config.h
obj/src/dummy_class.o: /usr/include/machine/ieeefp.h
obj/src/dummy_class.o: /usr/include/sys/features.h /usr/include/sys/reent.h
obj/src/dummy_class.o: /usr/include/sys/_types.h
obj/src/dummy_class.o: /usr/include/machine/_types.h
obj/src/dummy_class.o: /usr/include/machine/_default_types.h
obj/src/dummy_class.o: /usr/include/sys/lock.h /usr/include/sys/types.h
obj/src/dummy_class.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
obj/src/dummy_class.o: /usr/include/sys/cdefs.h
obj/src/global_funcs.o: src/global_funcs.h /usr/include/stdio.h
obj/src/global_funcs.o: /usr/include/_ansi.h /usr/include/newlib.h
obj/src/global_funcs.o: /usr/include/sys/config.h
obj/src/global_funcs.o: /usr/include/machine/ieeefp.h
obj/src/global_funcs.o: /usr/include/sys/features.h /usr/include/sys/reent.h
obj/src/global_funcs.o: /usr/include/sys/_types.h
obj/src/global_funcs.o: /usr/include/machine/_types.h
obj/src/global_funcs.o: /usr/include/machine/_default_types.h
obj/src/global_funcs.o: /usr/include/sys/lock.h /usr/include/sys/types.h
obj/src/global_funcs.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
obj/src/global_funcs.o: /usr/include/sys/cdefs.h
obj/src/lic_derived_class.o: src/derived_class.h src/dummy_class.h
obj/src/lic_derived_class.o: ../src/lic/register_class_macros.h
obj/src/lic_derived_class.o: ../src/lic/string_registrant.h
obj/src/lic_derived_class.o: ../src/lic/registrant.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface.inl
obj/src/lic_derived_class.o: ../src/lic/lua_interface.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface_default.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface_base.h
obj/src/lic_derived_class.o: ../src/lic/lua_wrapper.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface_pointer.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface_reference.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface_number.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface_string.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface_base.inl
obj/src/lic_derived_class.o: /usr/include/lua.h /usr/include/luaconf.h
obj/src/lic_derived_class.o: /usr/include/limits.h /usr/include/features.h
obj/src/lic_derived_class.o: /usr/include/sys/cdefs.h
obj/src/lic_derived_class.o: /usr/include/sys/features.h
obj/src/lic_derived_class.o: /usr/include/lauxlib.h /usr/include/stdio.h
obj/src/lic_derived_class.o: /usr/include/_ansi.h /usr/include/newlib.h
obj/src/lic_derived_class.o: /usr/include/sys/config.h
obj/src/lic_derived_class.o: /usr/include/machine/ieeefp.h
obj/src/lic_derived_class.o: /usr/include/sys/reent.h
obj/src/lic_derived_class.o: /usr/include/sys/_types.h
obj/src/lic_derived_class.o: /usr/include/machine/_types.h
obj/src/lic_derived_class.o: /usr/include/machine/_default_types.h
obj/src/lic_derived_class.o: /usr/include/sys/lock.h /usr/include/sys/types.h
obj/src/lic_derived_class.o: /usr/include/machine/types.h
obj/src/lic_derived_class.o: /usr/include/sys/stdio.h
obj/src/lic_derived_class.o: ../src/lic/lua_interface_default.inl
obj/src/lic_derived_class.o: ../src/lic/lua_interface_pointer.inl
obj/src/lic_derived_class.o: ../src/lic/lua_interface_reference.inl
obj/src/lic_derived_class.o: ../src/lic/proxy_class_ctor.inl
obj/src/lic_derived_class.o: ../src/lic/proxy_class_ctor.h
obj/src/lic_derived_class.o: ../src/lic/proxy_function.h
obj/src/lic_derived_class.o: ../src/lic/proxy_function.inl ../src/lic/util.h
obj/src/lic_derived_class.o: ../src/lic/proxy_class_function.inl
obj/src/lic_derived_class.o: ../src/lic/proxy_class_function.h
obj/src/lic_dummy_class.o: src/dummy_class.h
obj/src/lic_dummy_class.o: ../src/lic/register_class_macros.h
obj/src/lic_dummy_class.o: ../src/lic/string_registrant.h
obj/src/lic_dummy_class.o: ../src/lic/registrant.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface.inl
obj/src/lic_dummy_class.o: ../src/lic/lua_interface.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_default.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_base.h
obj/src/lic_dummy_class.o: ../src/lic/lua_wrapper.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_pointer.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_reference.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_number.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_string.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_base.inl
obj/src/lic_dummy_class.o: /usr/include/lua.h /usr/include/luaconf.h
obj/src/lic_dummy_class.o: /usr/include/limits.h /usr/include/features.h
obj/src/lic_dummy_class.o: /usr/include/sys/cdefs.h
obj/src/lic_dummy_class.o: /usr/include/sys/features.h /usr/include/lauxlib.h
obj/src/lic_dummy_class.o: /usr/include/stdio.h /usr/include/_ansi.h
obj/src/lic_dummy_class.o: /usr/include/newlib.h /usr/include/sys/config.h
obj/src/lic_dummy_class.o: /usr/include/machine/ieeefp.h
obj/src/lic_dummy_class.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
obj/src/lic_dummy_class.o: /usr/include/machine/_types.h
obj/src/lic_dummy_class.o: /usr/include/machine/_default_types.h
obj/src/lic_dummy_class.o: /usr/include/sys/lock.h /usr/include/sys/types.h
obj/src/lic_dummy_class.o: /usr/include/machine/types.h
obj/src/lic_dummy_class.o: /usr/include/sys/stdio.h
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_default.inl
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_pointer.inl
obj/src/lic_dummy_class.o: ../src/lic/lua_interface_reference.inl
obj/src/lic_dummy_class.o: ../src/lic/proxy_class_ctor.inl
obj/src/lic_dummy_class.o: ../src/lic/proxy_class_ctor.h
obj/src/lic_dummy_class.o: ../src/lic/proxy_function.h
obj/src/lic_dummy_class.o: ../src/lic/proxy_function.inl ../src/lic/util.h
obj/src/lic_dummy_class.o: ../src/lic/proxy_class_function.inl
obj/src/lic_dummy_class.o: ../src/lic/proxy_class_function.h
obj/src/lic_global_funcs.o: src/global_funcs.h
obj/src/lic_global_funcs.o: ../src/lic/register_global_macros.h
obj/src/lic_global_funcs.o: ../src/lic/string_registrant.h
obj/src/lic_global_funcs.o: ../src/lic/registrant.h
obj/src/lic_global_funcs.o: ../src/lic/proxy_function.inl
obj/src/lic_global_funcs.o: ../src/lic/proxy_function.h
obj/src/lic_global_funcs.o: ../src/lic/lua_interface.h
obj/src/lic_global_funcs.o: ../src/lic/lua_interface_default.h
obj/src/lic_global_funcs.o: ../src/lic/lua_interface_base.h
obj/src/lic_global_funcs.o: ../src/lic/lua_wrapper.h
obj/src/lic_global_funcs.o: ../src/lic/lua_interface_pointer.h
obj/src/lic_global_funcs.o: ../src/lic/lua_interface_reference.h
obj/src/lic_global_funcs.o: ../src/lic/lua_interface_number.h
obj/src/lic_global_funcs.o: ../src/lic/lua_interface_string.h
obj/src/lic_global_funcs.o: ../src/lic/util.h /usr/include/lua.h
obj/src/lic_global_funcs.o: /usr/include/luaconf.h /usr/include/limits.h
obj/src/lic_global_funcs.o: /usr/include/features.h /usr/include/sys/cdefs.h
obj/src/lic_global_funcs.o: /usr/include/sys/features.h
obj/src/lic_global_funcs.o: ../src/lic/proxy_singleton_function.inl
obj/src/lic_global_funcs.o: ../src/lic/proxy_singleton_function.h
obj/src/main.o: ../src/lic/lic.h ../src/lic/registrant.h /usr/include/lua.h
obj/src/main.o: /usr/include/luaconf.h /usr/include/limits.h
obj/src/main.o: /usr/include/features.h /usr/include/sys/cdefs.h
obj/src/main.o: /usr/include/sys/features.h /usr/include/lauxlib.h
obj/src/main.o: /usr/include/stdio.h /usr/include/_ansi.h
obj/src/main.o: /usr/include/newlib.h /usr/include/sys/config.h
obj/src/main.o: /usr/include/machine/ieeefp.h /usr/include/sys/reent.h
obj/src/main.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
obj/src/main.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
obj/src/main.o: /usr/include/sys/types.h /usr/include/machine/types.h
obj/src/main.o: /usr/include/sys/stdio.h /usr/include/lualib.h
