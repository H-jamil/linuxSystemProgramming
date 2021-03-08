# @Author: jamil
# @Date:   2021-03-06T13:48:44-06:00
# @Last modified by:   jamil
# @Last modified time: 2021-03-08T00:21:50-06:00
TARGET: Application.exe
libdll.a: dll.o
	ar rs libdll.a dll.o
dll.o: dll.c
	gcc -c -I . dll.c -o dll.o
diff.o:diff.c
	gcc -c -I . diff.c -o diff.o
Application.exe: evaluation.o libdll.a diff.o
	gcc evaluation.o diff.o -o Application.exe -L . -ldll
evaluation.o: evaluation.c
	gcc -c -I . evaluation.c -o evaluation.o
clean:
	rm *.o
	rm libdll.a
	rm Application.exe
