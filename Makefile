C=gcc -o
D=-DDEBUG -g
R=;clear;./$@

%: %.c
	$(C) $@ $< $(D)$(R)
