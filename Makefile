CXX=g++
CPPFLAGS=-Wall -Wextra -std=c++14 -Iinclude
LDFLAGS=
LDLIBS=

TEST_SRCS=$(shell find . -name "*.cpp" -not -name "main.cpp")
TEST_OBJS=$(subst .cpp,.o,$(TEST_SRCS))

MAIN_SRCS=$(shell find . -name "*.cpp" -not -path "./support/*" -not -name "*test.cpp")
MAIN_OBJS=$(subst .cpp,.o,$(MAIN_SRCS))

all: test main

main: $(MAIN_OBJS)
	$(CXX) $(LDFLAGS) -o main $(MAIN_OBJS) $(LDLIBS)

test: $(TEST_OBJS)
	$(CXX) $(LDFLAGS) -o test $(TEST_OBJS) $(LDLIBS)

depend: .main_depend .test_depend

.main_depend: $(MAIN_SRCS)
	rm -f ./.main_depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.main_depend

.test_depend: $(TEST_SRCS)
	rm -f ./.test_depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.test_depend

clean:
	rm -f $(TEST_OBJS) $(MAIN_OBJS)

dist-clean: clean
	$(RM) *~ .main_depend .test_depend

include .test_depend
include .main_depend
