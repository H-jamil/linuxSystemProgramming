# @Author: jamil
# @Date:   2021-03-06T13:48:44-06:00
# @Last modified by:   jamil
# @Last modified time: 2021-03-06T13:55:15-06:00
TARGET: Application.exe
libdll.a: dll.o
	ar rs libdll.a dll.o
dll.o: dll.c
	gcc -c -I . dll.c -o dll.o
Application.exe: application.o libdll.a
	gcc application.o -o Application.exe -L . -ldll
application.o: application.c
	gcc -c -I . application.c -o application.o
clean:
	rm *.o
	rm libdll.a
	rm Application.exe
