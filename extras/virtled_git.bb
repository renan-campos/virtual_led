# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# WARNING: the following LICENSE and LIC_FILES_CHKSUM values are best guesses - it is
# your responsibility to verify that the values are complete and correct.
#
# The following license files were not able to be identified and are
# represented as "Unknown" below, you will need to check them yourself:
#   LICENSE
#
LICENSE = "Unknown"
LIC_FILES_CHKSUM = "file://LICENSE;md5=cd57b681b72ca0c08dd1289c9016726a"
#LICENSE = "CLOSED"
#LIC_FILES_CHKSUM = ""

SRC_URI = "git://github.com/renan-campos/virtual_led.git;protocol=https"

# Modify these as desired
PV = "1.0+git${SRCPV}"
SRCREV = "6f67bfe5298051322fa4ad366dde308037323de7"

S = "${WORKDIR}/git"

DEPENDS = "systemd phosphor-dbus-interfaces sdbusplus sdbusplus-native"

# NOTE: if this software is not capable of being built in a separate build directory
# from the source, you should replace autotools with autotools-brokensep in the
# inherit line
inherit pkgconfig autotools

# Specify any options you want to pass to the configure script using EXTRA_OECONF:
EXTRA_OECONF = ""
FILES_${PN} += "/etc/systemd/system/*"

do_install () {
        install -m 0755 -d ${D}${bindir} ${D}${datadir}/virtled ${D}/etc/systemd/system/default.target.wants
        install -m 0755 ${WORKDIR}/${PN}-${PV}/virtled ${D}${bindir}
        install -m 0644 ${S}/extras/client.py ${D}${datadir}/virtled/
	install -m 0644 ${S}/extras/test_virtled.sh ${D}${datadir}/virtled/
	install -m 0644 ${S}/extras/virtled.service ${D}/etc/systemd/system/
	ln -fs ${D}/etc/systemd/system/virtled.service ${D}/etc/systemd/system/default.target.wants/
}
