compile-clang:
	meson compile -C build-clang

compile-gcc:
	meson compile -C build-gcc

configure-clang:
	CC=clang CXX=clang++ meson build-clang

configure-gcc:
	CC=gcc CXX=g++ meson build-gcc

reconfigure-clang:
	CC=clang CXX=clang++ meson build-clang --reconfigure

reconfigure-gcc:
	CC=gcc CXX=g++ meson build-gcc --reconfigure
