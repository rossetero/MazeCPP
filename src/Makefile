CXX = g++
CXXFLAGS = -O2 -Wall -Werror -Wextra -std=c++17

SOURCE = model/src/*.cc && \
		 controller/src/*.cc && \
		 Common/src/*.cc

HEADERS = model/inc/*.h && \
		 controller/inc/*.h && \
		 model/view/inc/*.h && \
		 Common/inc/*.h

GCOV_FLAGS = -fprofile-arcs -ftest-coverage

TESTFLAGS = -lgtest
TESTSRC = tests/*.cc
TESTHEADERS = test/tests.h
TESTEXEC = tests.out

APP_ARCHIVE = A1_Maze_CPP
EXEC = A1_Maze_CPP.out

INSTALL_DIR = ../build

.PHONY: all install run tests dvi dist gcov_report uninstall clean clang clangi

all: install

install:
	mkdir -p $(INSTALL_DIR)
	cd view && \
	qmake && \
	make && \
	mv desktop.app/Contents/MacOS/desktop ../$(EXEC) && \
	rm -rf desktop.app && \
	rm -f Makefile && \
	cd .. && \
	mv $(EXEC) $(INSTALL_DIR)/$(EXEC)

run: install
	$(INSTALL_DIR)/$(EXEC)

tests:
	$(CXX) $(TESTSRC) model/src/*.cc $(TESTFLAGS) -o ./$(TESTEXEC)
	./$(TESTEXEC)

dvi:
	cat ../README.md

dist: clean
	mkdir $(APP_ARCHIVE)
	cp -rf * $(APP_ARCHIVE)/
	tar -cvzf $(APP_ARCHIVE).tgz $(APP_ARCHIVE)/
	rm -rf $(APP_ARCHIVE)

gcov_report:
	$(CXX) $(TESTSRC) model/src/*.cc $(GCOV_FLAGS) $(TESTFLAGS) -o ./$(TESTEXEC)
	./$(TESTEXEC)
	lcov --capture --directory . --output-file coverage.info --rc geninfo_unexecuted_blocks=1 --ignore-errors gcov,source,mismatch,inconsistent
	lcov --extract coverage.info "*/maze_wave_solver.cc" "*/eller_generator.cc" --output-file coverage_filtered.info
	genhtml coverage_filtered.info  --output-directory coverage-html
	open coverage-html/index.html

uninstall: clean
	rm -f $(INSTALL_DIR)/$(EXEC) $(TESTEXEC) *.a

clean:
	rm -rf *.out *.g* *.info *-html settings.ini
	rm -rf view/*.o view/.qmake.stash view/moc_mainwindow.cpp view/*.h view/.qtc_clangd view/Makefile view/*.app view/desktop.pro.user
	rm -rf view/qrc_qmake_resources.cpp view/*.cpp

clang:
	find . -iname *.h -o -iname *.tpp -o -iname *.c -o -iname *.cpp | xargs clang-format -n

clangi:
	find . -iname *.h -o -iname *.tpp -o -iname *.c -o -iname *.cpp | xargs clang-format -i
