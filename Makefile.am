BUILT_SOURCES = \
	com/example/virtled/Manager/server.cpp \
	com/example/virtled/Manager/server.hpp 


sbin_PROGRAMS = virtled
virtled_SOURCES = \
				server.cpp \
				com/example/virtled/Manager/server.cpp \
				main.cpp


virtled_LDFLAGS = $(SYSTEMD_LIBS) $(SDBUSPLUS_LIBS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_LIBS)
virtled_CFLAGS =  $(SYSTEMD_CFLAGS) $(SDBUSPLUS_CFLAGS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_CFLAGS)

# Needed if sdbus++ not installed on local machine, but should be on SDK.
PYTHON = /opt/openbmc-phosphor/2.2/sysroots/x86_64-pokysdk-linux/usr/bin/python 

com/example/virtled/Manager/server.cpp: com/example/virtled/Manager.interface.yaml com/example/virtled/Manager/server.hpp
	@mkdir -p `dirname $@`
	$(PYTHON) $(SDBUSPLUSPLUS) -r $(srcdir) interface server-cpp com.example.virtled.Manager > $@

com/example/virtled/Manager/server.hpp: com/example/virtled/Manager.interface.yaml
	@mkdir -p `dirname $@`
	$(PYTHON) $(SDBUSPLUSPLUS) -r $(srcdir) interface server-header com.example.virtled.Manager > $@
