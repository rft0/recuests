all: test

test:
	python3 setup.py build && mv ./build/lib*/* ./ && rm -rf ./build && python3 test.py