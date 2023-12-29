all: test



test:
	python3 setup.py build && mv ./build/lib*/* ./recuests/ && rm -rf ./build && python3 test.py