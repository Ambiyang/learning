### Generate a static library
```
.PHONY:clean

libmath.a:libmath.o
	ar rcs $@ $^
libmath.o:libmath.c libmath.h
clean:
	rm libmath.a libmath.o
```
### Use a static library 
```
.PHONY: clean

hello:main.o
	gcc -o $@ $^ -L./ -lmath 
	#-L designate the path of the lib,-l is the name
	#The lib name is libmath.a which should be viewed as a prefix lib + math + suffix .a
	#So its name is math
main.o:main.c
	gcc -o $@ -c $^
clean:
	rm hello main.o
```
### Generate a Dynamic library
```
.PHONY:clean

libdll.so:dll.o
	gcc -o $@ -shared $^
dll.o:dll.c
	gcc -o $@ -fPIC -c $^ 
clean:
	rm libdll.so dll.o
```
### Use a Dynamic library 
```
.PHONY: clean

hello:main.o
	gcc -o hello main.o -L./ -ldll
main.o:main.c
	gcc -o $@ -c -fPIC $^

clean:
	rm -f  main.o hello
```
### At last before running the dynamic library generated hello,remember to copy the dll to lib folder!
