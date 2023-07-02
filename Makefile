.PHONY: all
all: format build compile

##########################################################################
.PHONY: clean
clean: 
	@rm -rf build

##########################################################################
.PHONY: format
format:
	@clang-format -i `find include/ -type f -name *.hh`
	@clang-format -i `find src/ -type f -name *.cc`

##########################################################################
.PHONY: update-sources-list
update-sources-list:
	@SOURCES=`find src/ -type f -name *.cc` && \
		sed -i -E -e "s%set\((SOURCES)[^)]*\)%set(\1 `echo $$SOURCES`)%" CMakeLists.txt

##########################################################################
.PHONY: build
build: pre-build-control update-sources-list
	@mkdir -p build && \
		cd build && \
		cmake -DCMAKE_BUILD_TYPE:STRING=${BUILD_TYPE} ..

##########################################################################
.PHONY: rebuild
rebuild: clean all
	@echo "Done"

##########################################################################
.PHONY: compile
compile:
	@mkdir -p build && cd build && make -j4

##########################################################################
.PHONY: run
run:
	@./build/bin/Parselo

##########################################################################
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

##########################################################################
.PHONY: update-tags
update-tags:
	@ctags -f .tags -R -I __weak_aliasses --languages=+c,c++ . \
		${VIRTUAL_ENV}/include
	@ctags -f .tags-cmake -R -I __weak_aliasses --languages=+cmake . \
		/usr/share/cmake-3.25/Help

##########################################################################

