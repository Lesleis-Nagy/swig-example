CC = clang++

PYTHON_INCLUDE_DIR = /opt/homebrew/Cellar/python@3.10/3.10.6_2/Frameworks/Python.framework/Versions/3.10/include/python3.10
PYTHON_LIB_DIR = /opt/homebrew/Cellar/python@3.10/3.10.6_2/Frameworks/Python.framework/Versions/3.10/lib
PYTHON_LIB = python3.10
NUMPY_INCLUDE_DIR = /opt/homebrew/Cellar/numpy/1.23.2/lib/python3.10/site-packages/numpy/core/include

#main: main.c lv.o
#	$(CC) $^ -o $@


lv.o: lv.cxx
	$(CC) -c $< -fPIC -o $@ 


lv_wrap.o: lv_wrap.cxx
	$(CC) -c $< -fPIC -o $@ -I $(PYTHON_INCLUDE_DIR) -I $(NUMPY_INCLUDE_DIR)


_lv.so: lv.o lv_wrap.o
	$(CC) -shared $^ -o $@ -I $(PYTHON_INCLUDE_DIR) -I $(NUMPY_INCLUDE_DIR) -L $(PYTHON_LIB_DIR) -l$(PYTHON_LIB)


lv_wrap.cxx: lv.i
	swig -python -c++ $<


clean:
	rm -f _lv.so
	rm -f lv.o
	rm -f lv.py
	rm -f lv_wrap.cxx
	rm -f lv_wrap.o
	rm -f main
	rm -f output1.pdf
	rm -f output2.pdf
	rm -rf __pycache__
	rm -rf main.dSYM



info:
	@echo "Use '/opt/homebrew/Cellar/python@3.10/3.10.6_2/bin/python3' to run this."
