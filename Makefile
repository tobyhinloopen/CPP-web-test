CXX=g++
CPPFLAGS=-Wall -Wextra -std=c++11 -Iinclude -Ofast
LDFLAGS=-lstdc++
LDLIBS=cpp_web.a

DEPS=$(shell find . -name "*.h" -or -name "*.cpp")
SRCS=$(shell find . -name "*.cpp")

LIB_OBJS=$(subst .cpp,.o,$(shell find . -name "*.cpp" -not -name "*test.cpp" -not -name "main.cpp"))
TEST_OBJS=$(subst .cpp,.o,$(shell find . -name "*test.cpp"))
MAIN_OBJS=$(subst .cpp,.o,$(shell find . -name "main.cpp"))

all: test main

cpp_web.a: $(LIB_OBJS)
	ar rvs cpp_web.a $(LIB_OBJS)

main: cpp_web.a $(MAIN_OBJS)
	$(CXX) $(LDFLAGS) -o main $(MAIN_OBJS) $(LDLIBS)

test: cpp_web.a $(TEST_OBJS)
	$(CXX) $(LDFLAGS) -o test $(TEST_OBJS) $(LDLIBS)

depend: .depend

.depend: $(DEPS)
	$(CXX) $(CPPFLAGS) -MM $(SRCS) > ./.depend;

clean:
	$(RM) $(LIB_OBJS) $(TEST_OBJS) $(MAIN_OBJS)

dist-clean: clean
	$(RM) .depend

include .depend
