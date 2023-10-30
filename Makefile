#Compiler options (clang)
CC = clang 
build_flags = -Wall -c
test_flags = -L. -lclna

SRC_DIR = "src/"
TEST_DIR = "test/"
BENCH_DIR = "bench/"

#from https://stackoverflow.com/questions/3774568/makefile-issue-smart-way-to-scan-directory-tree-for-c-files
# Make does not offer a recursive wildcard function, so here's one
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# How to recursively find all files that match a pattern
ALL_SRC := $(call rwildcard,src/,*.c)
ALL_TEST := $(call rwildcard,test/,*.c)
ALL_EXECUTABLES := $(call rwildcard,./,*_test)

src/linear/algebra_normal.c: build
	echo "Hello from" $(SRC)

prod:
	$(CC) $(build_flags) $(ALL_SRC)

debug:
	$(CC) $(build_flags) $(ALL_SRC) -DLNA_DEBUG -DLNA_FUNCTION_ERRORS -DLNA_FUNCTION_OPERATIONS

*.o: debug
	ar -rc libclna.a *.o


# Function to generate the output test file name
define generate_test_output_name
$(subst /,_,$(dir $1))$(notdir $1)
endef

test: *.o
	$(foreach test_file,$(ALL_TEST), \
		$(CC) $(test_file) $(test_flags) -o $(call generate_test_output_name,$(test_file));)

test_run: test
	@for test_executable in $(call generate_test_output_name,$(ALL_TEST)); do \
		./$$test_executable; \
	done

.PHONY: debug prod help clean test install remove test_run

clean:
	rm -rf *.o
	rm -rf *.a

# Cleans objects files AND executables created from tests
remove: clean
	rm -rf *.a
	rm *_test*

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
CYAN = \033[36;1m
MAG = \033[35;1m
NC = \033[0m

#Print help message
help:
	@echo -e "$(MAG) Available targets: $(NC)"
	@echo -e "$(YELLOW)  - all:$(NC) $(CYAN)Build the project (default) $(NC)"
	@echo -e "$(YELLOW)  - clean:$(NC) $(CYAN)Remove object files and library files$(NC)"
	@echo -e "$(YELLOW)  - remove:$(NC) $(CYAN)Clean and remove executable from tests$(NC)"
	@echo -e "$(YELLOW)  - debug:$(NC) $(CYAN)Build the project with debugging symbols$(NC)"
	@echo -e "$(YELLOW)  - prod:$(NC) $(CYAN)Build the library for production $(NC)$(RED)(!!minimal,no printing, no debug symbols!!)$(NC)"
	@echo -e "$(YELLOW)  - test:$(NC) $(GREEN)Build tests$(NC)"
	@echo -e "$(YELLOW)  - help:$(NC) $(CYAN)Show this help message$(NC)"
	@echo -e "$(YELLOW)  - install:$(NC) $(CYAN)Install library on /usr/bin$(NC)"
