# @Author: jamil
# @Date:   2021-02-27T22:16:20-06:00
# @Last modified by:   jamil
# @Last modified time: 2021-02-27T23:12:57-06:00
TARGET:finalexe
finalexe:main.o mylibmath.a
	gcc  main.o -o finalexe -L . mylibmath.a -lm
mylibmath.a:trig_math/trig_math.o common_math/common_math.o complex_math/complex_math.o
	ar rs mylibmath.a common_math/common_math.o complex_math/complex_math.o trig_math/trig_math.o
common_math.o:common_math/common_math.c
	gcc -c -I common_math common_math/common_math.c -o common_math/common_math.o
complex_math.o:complex_math/complex_math.c
	gcc -c -I complex_math complex_math/complex_math.c -o complex_math/complex_math.o
trig_math.o:trig_math/trig_math.c
	gcc -c -I trig_math trig_math/trig_math.c -o trig_math/trig_math.o -lm
main.o:main.c
	gcc -c -I common_math -I complex_math -I trig_math main.c -o main.o
clean:
	rm main.o
	rm mylibmath.a
	rm trig_math/trig_math.o
	rm common_math/common_math.o
	rm complex_math/complex_math.o
	rm finalexe
