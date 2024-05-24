ALL:run


.PHONY:configure build run rebuild rerun test clean format tidy doc

configure:
	cmake --preset=linux-release
build:configure
	cmake --build --preset=linux-release
run:build
	cd build/ninja-release/dist/bin && ./graver test.graver
rebuild:clean build
rerun:rebuild run
test:build
	cd build/ninja-release/dist/test && ./graver_test
clean:
	rm -rf build
format:
	find src -type f \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -exec clang-format -style=file:.clang-format -i {} \;
	find include -type f \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -exec clang-format -style=file:.clang-format -i {} \;
	find test -type f \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -exec clang-format -style=file:.clang-format -i {} \;
tidy:format
	find src -type f -name "*.cpp" -print0 | xargs -0 clang-tidy --config-file=.clang-tidy -p=build/ninja-release --quiet
	find include -type f -name "*.h" -print0 | xargs -0 clang-tidy --config-file=.clang-tidy -p=build/ninja-release --quiet
	find test -type f -name "*.cpp" -print0 | xargs -0 clang-tidy --config-file=.clang-tidy -p=build/ninja-release --quiet
doc:
	rm -rf build/doc
	mkdir -p build/doc
	cd doc && doxygen Doxyfile
	cp doc/doxygen-awesome-css/doxygen-awesome-fragment-copy-button.js build/doc/html/
	cp doc/doxygen-awesome-css/doxygen-awesome-interactive-toc.js build/doc/html/
	cp -r doc/images build/doc/html/images



