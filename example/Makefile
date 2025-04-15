.PHONY: build
build:
	gcc \
		-O2 -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self \
		-Wswitch-default -Wfloat-equal -Wpointer-arith -Wtype-limits \
		-Wempty-body -Wno-logical-op -Wstrict-prototypes -Wold-style-declaration \
		-Wold-style-definition -Wmissing-parameter-type \
		-Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign \
		-std=c99 -lm -g \
		code.c -o code


.PHONY: test
test: build
	MJ_PG="code" mj


.PHONY: clean
clean:
	rm code


