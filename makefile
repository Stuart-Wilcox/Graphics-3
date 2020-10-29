assets = src/assets/*/*.hpp src/assets/*/*.cpp
utils = src/utils/*/*.hpp src/utils/*/*.cpp

clean:
	rm -rf bin/*

main: src/main.cpp $(assets) $(utils)
	g++ -o bin/main src/main.cpp $(assets) $(utils) -lX11 -lm
	# use the below command for mac
	# g++ src/main.cpp $(assets) $(utils) -lX11 -lm -I/usr/X11/include -L/usr/X11/lib

test_assets: src/test_assets.cpp $(assets) $(utils)
	g++ -o bin/test_assets src/test_assets.cpp $(assets) $(utils) -lX11 -lm

test_utils: src/test_utils.cpp $(assets) $(utils)
	g++ -o bin/test_utils src/test_utils.cpp $(assets) $(utils) -lX11 -lm
