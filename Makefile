test:
	python3 setup.py build && mv ./build/lib.linux-x86_64-cpython-311/recuests* ./recuests.cpython-311-x86_64-linux-gnu.so && python3 test.py