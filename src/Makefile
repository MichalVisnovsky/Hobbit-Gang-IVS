DIR:=$(PWD)
CalcDIR:=$(DIR)/Calculator
ProfDIR:=$(DIR)/Profiling
DocDIR:=$(DIR)/doc
InsDIR:=$(DIR)/install
RepoDIR:=$(DIR)/../
ZipNAME:=xboboc01_xburia28_xmarko20_xvisno01
PackDIR:=$(DIR)/../$(ZipNAME)
ZipDIR:=$(DIR)/../$(ZipNAME).zip
DocPackDIR:=$(PackDIR)/doc
InsPackDIR:=$(PackDIR)/install
RepoPackDIR:=$(PackDIR)/repository/
BuildDIR:=$(CalcDIR)/build
TestDIR:=$(DIR)/tests
BuildTestDIR:=$(TestDIR)/build
CXX:=g++
.PHONY: all clean run buildtest test profile pack doc help
all:
	if [ ! -d "$(BuildDIR)" ]; then mkdir "$(BuildDIR)"; fi
	cd "$(BuildDIR)" && qmake ..
	cd "$(BuildDIR)" && make
	cd "$(ProfDIR)" && $(CXX) stddev.cpp -o stddev
run:
	cd "$(BuildDIR)" && ./calculator &
buildtest:
	if [ ! -d "$(BuildTestDIR)" ]; then mkdir "$(BuildTestDIR)"; else cd "$(BuildTestDIR)" && rm -rf * || true; fi
	cd "$(BuildTestDIR)" && cmake -G Unix\ Makefiles ..
	cd "$(BuildTestDIR)" && cmake --build . --config Debug
test:
	cd "$(BuildTestDIR)" && ./CalculatorTests
profile:
	cd "$(ProfDIR)" && ./stddev
pack: doc
	if [ ! -d "$(ZipDIR)" ];then rm -rf "$(ZipDIR)" || true; fi
	if [ ! -d "$(PackDIR)" ]; then mkdir "$(PackDIR)";fi
	cp -rf "$(DocDIR)" "$(PackDIR)"
	cp -rf "$(InsDIR)" "$(PackDIR)"
	rsync -a "$(RepoDIR)" "$(RepoPackDIR)"
	rm -rf "$(RepoPackDIR)"/pack
	make clean
	cd "$(DIR)/.." && zip -r "$(ZipDIR)" $(ZipNAME)
	rm -rf "$(PackDIR)" || true
	
doc: Doxyfile clean
	doxygen $<
clean:
	rm -rf "$(BuildDIR)" || true
	rm -rf "$(CalcDIR)"/calculator || true
	rm -rf "$(ProfDIR)"/stddev || true
	rm -rf "$(BuildTestDIR)" || true
	rm -rf "$(DocDIR)" || true
help:
	@echo "Be sure to compile the calculator with make/make all before running the calculator itself"
	@echo "make / make all for compilation"
	@echo "run for packing source files"
	@echo "buildtest for building calculator library tests"
	@echo "test for running calculator library tests"
	@echo "clean for deleting generated files by compilation"
	@echo "pack for packing source files"

