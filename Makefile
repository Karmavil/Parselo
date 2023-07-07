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


.PHONY: all
all: build format compile test run

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: clean
clean: 
	@rm -rf build

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I
.PHONY: format
format:
	@clang-format -i `find include/ -type f -name *.hh`
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
build: pre-build-control update-sources-list
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
	@mkdir -p build && cd build && make -j4

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
pre-build-control:
	@if [ ! ${BUILD_TYPE} ]; then \
		echo "\`BUILD_TYPE\` not set" && exit 1; \
	fi
	@if [ ! ${CMAKE_PREFIX_PATH} ]; then	\
		echo "\`CMAKE_PREFIX_PATH\` not set" fi && exit 1; \
	fi
	@if [ ! ${PKG_CONFIG_PATH} ]; then \
		echo "\`PKG_CONFIG_PATH\` not set" && exit 1; \
	fi

#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I#I

