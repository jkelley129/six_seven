#==========================================
#    Makefile: makefile for six_seven 1.0
#   CREDIT:
#	Based on sl (Steam Locomotive) v5.02
#	Copyright 1993, 1998, 2014
#                 Toyoda Masashi
#		  (mtoyoda@acm.org)
#	Last Modified: 2025/09/29
#==========================================

CC=gcc
CFLAGS=-O -Wall

all: six_seven

six_seven: six_seven.c six_seven.h
	$(CC) $(CFLAGS) -o six_seven six_seven.c -lncurses

clean:
	rm -f sl

distclean: clean
