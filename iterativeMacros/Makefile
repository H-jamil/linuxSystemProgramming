# @Author: jamil
# @Date:   2021-03-13T19:34:29-06:00
# @Last modified by:   jamil
# @Last modified time: 2021-03-13T19:43:38-06:00

TARGET: exe
libdll.a: dll.o
	ar rs libdll.a dll.o
dll.o: dll.c
	gcc -g -c -I . dll.c -o dll.o
exe: application.o libdll.a
	gcc -g application.o -o exe -L . -ldll
application.o: application.c
	gcc -g -c -I . application.c -o application.o
clean:
	rm *.o
	rm libdll.a
	rm exe
