all:
	gcc conv1d/conv1d.c -o conv1d.exe
	g++ conv2d/conv2d.cpp -o conv2d.exe
clean:
	rm *.exe