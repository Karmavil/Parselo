#!/usr/bin/env bash

#  Parselo - Query the journal about your progam.
#  Copyright (C) 2023 Federico Gallo Herosa. https://www.terifel.com
#  Find the full description of the license in the following URL:
#  https://github.com/Karmavil/Parselo/blob/main/LICENSE
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License along
#  with this program; if not, write to the Free Software Foundation, Inc.,
#  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
BUILD_TYPE=Debug
JOBS=-j4
PFIX=`if [ ${VIRTUAL_ENV} ]; then echo ${VIRTUAL_ENV}; else echo /usr; fi`
SUPP_GTK=${PFIX}/share/gtk-4.0/valgrind/gtk.supp
SUPP_GLIB=${PFIX}/share/glib-2.0/valgrind/glib.supp
DEPRECATED_AFTER_4_10= AppChooser AppChooserButton AppChooserDialog AppChooserWidget CellArea CellAreaBox CellAreaContext CellLayout CellRenderer CellRendererAccel CellRendererCombo CellRendererPixbuf CellRendererProgress CellRendererSpin CellRendererSpinner CellRendererText CellRendererToggle CellView ComboBox ComboBoxText EntryCompletion IconView ListStore ListViewText StyleContext TreeDragDest TreeDragSource TreeIter TreeModel TreeModelFilter TreeModelSort TreePath TreeRowReference TreeSelection TreeSortable TreeStore TreeView TreeViewColumn ColorButton ColorChooser ColorChooserDialog FileChooser FileChooserDialog FileChooserNative FileChooserWidget FontButton FontChooser FontChooserDialog FontChooserWidget MessageDialog TreeModelColumn TreeModelColumnRecord InfoBar Assistant AssistantPage LockButton Statusbar VolumeButton
MORE_ABOUT_DEPRECATIONS="https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/changes-gtkmm4.html\#sec-deprecations-4-10"

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: all
all: build format compile test warn-deprecations run

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: clean
clean: 
	@rm -rf build

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: format
format:
	@clang-format -i `find include/ -type f -name *.hh` src/main.cc # (added main.cc because while writing this note the include folder is empty)
	@clang-format -i `find src/ -type f -name *.hh`
	@clang-format -i `find src/ -type f -name *.cc`
	@clang-format -i `find test/ -type f -name *.cc`

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: update-sources-list
update-sources-list:
	@SOURCES=`find src/ -type f -name *.cc -not -path "src/gui/*"` \
		&& sed -i -E -e \
			"s%set\((SOURCES)[^)]*\)%set(\1 `echo $$SOURCES`)%" \
			CMakeLists.txt
	@cd src/gui && \
		LIB_SOURCES=`find . -type f -name *.cc` && \
		sed -i -E -e \
			"s%set\((LIB_SOURCES)[^)]*\)%set(\1 `echo $$LIB_SOURCES`)%" \
			./CMakeLists.txt

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: build
build: update-sources-list
	@mkdir -p build && \
		cd build && \
		cmake -DCMAKE_BUILD_TYPE:STRING=${BUILD_TYPE} ..

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: rebuild
rebuild: clean all
	@echo "Done"

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: compile
compile:
	@mkdir -p build && cd build && make ${JOBS}

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: test
test:
	@./build/bin/TestParselo

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: run
run:
	@./build/bin/Parselo

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: debug
debug:
	gdb build/bin/Parselo

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: debug-test
debug-test:
	gdb build/bin/TestParselo

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: memcheck
memcheck:
	@mkdir -p build/vgdump
	@if [ ${full} ]; then \
		valgrind \
			--leak-check=full \
			--num-callers=6 \
			--show-leak-kinds=all \
			--show-error-list=yes \
			--suppressions=${SUPP_GTK} \
			--suppressions=${SUPP_GLIB} \
			--log-file=build/vgdump.txt \
			`if [ ${test} -eq 1 ]; then \
				echo "--log-file=build/vgdump/TestParselo.txt"; \
				echo "build/bin/TestParselo"; \
			else \
				echo "--log-file=build/vgdump/Parselo.txt"; \
				echo "build/bin/Parselo"; \
			fi`; \
	else \
		valgrind --show-error-list=yes \
			`if [ ${test} -eq 1 ]; then \
				echo "build/bin/TestParselo"; \
			else \
				echo "build/bin/Parselo"; \
			fi`; \
	fi

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
warn-deprecations:
	@WARNED=0 && for widget in ${DEPRECATED_AFTER_4_10}; \
		do \
			_X_=`grep -rn --binary-files=without-match "$$widget" src/`; \
			if [ "$$_X_" ]; then \
				WARNED=1; \
				echo "|\033[93mWARNING\033[00m| Frienldy reminder: "; \
				echo "Possible deprecation for: $$widget was found at"; \
				echo "$$_X_"; \
			fi \
		done && \
		if [ $$WARNED -gt 0 ]; then \
			echo "Check the following URL for more information: "; \
			echo "${MORE_ABOUT_DEPRECATIONS}"; \
		fi

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I

