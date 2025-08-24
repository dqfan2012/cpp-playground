# Phony targets
.PHONY: compile-clang compile-gcc configure-clang configure-gcc reconfigure-clang reconfigure-gcc

# Help target to display all available commands
help:
	@echo "Available commands:"
	@echo "  compile-clang      - Compiles the project using the clang++ compiler"
	@echo "  compile-gcc        - Compiles the project using the g++ compiler"
	@echo "  configure-clang    - Configures the project for clang++ with Meson"
	@echo "  configure-gcc      - Configures the project for g++ with Meson"
	@echo "  reconfigure-clang  - Reconfigures the project for clang++ with Meson"
	@echo "  reconfigure-gcc    - Reconfigures the project for g++ with Meson"
	@echo "  help               - Show all available commands"

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
