CFLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

CFLAGS_RELEASE = -O3 -DNDEBUG -march=native

LINK_LIBS	:= sfml-graphics sfml-window sfml-system

BUILD = DEBUG

ifeq ($(BUILD),RELEASE)
	override CFLAGS := $(CFLAGS_RELEASE)
endif
override CFLAGS := $(CFLAGS) -I./include

#compilier
ifeq ($(origin CC),default)
	CC=g++
endif

mandelbrot.exe: build/main.o build/mandelbrot.o build/window.o
	$(CC) $(CFLAGS) $^ $(addprefix -l,$(LINK_LIBS)) -o $@

build/main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o$@

build/window.o: window.cpp
	$(CC) $(CFLAGS) -c $< -o$@

build/mandelbrot.o: mandelbrot.cpp
	$(CC) $(CFLAGS) -c $< -o$@


.PHONY:clean
clean:
	rm build/*
