# ######################################
# MeeGo Touch Controlpanel Reset applet
# ######################################

system(./configure)
TEMPLATE = subdirs
SUBDIRS = \
	src \
	translations

QMAKE_CLEAN += \
	configure-stamp \
	build-stamp \
	localconfig.pri

contains(BUILD_FEATURES,coverage) {
	QMAKE_EXTRA_TARGETS += coverage
	coverage.depends = src/Makefile
	coverage.commands = \
                cd tests && make coverage && cd .. \
                && genhtml --no-branch-coverage --legend -o coverage/ \
                   -t \"MeeGo Touch Controlpanel Reset Applet Coverage Report\" 
}

