# Note that in conda libpython3xx is not found in the path returned by ldflags. IMHO it is a bug.
# The workaround is to -L appropriately. Will be fixed here.

export PLUMED_MKLIB_CFLAGS="$(python3-config --cflags --embed)  -Ipybind11-2.11.1/include"
export PLUMED_MKLIB_LDFLAGS=$(python3-config --ldflags --embed)

echo PLUMED_MKLIB_CFLAGS=$PLUMED_MKLIB_CFLAGS
echo PLUMED_MKLIB_LDFLAGS=$PLUMED_MKLIB_LDFLAGS

../lib/plumed mklib PythonCV.cpp PythonFunction.cpp PythonPlumedBase.cpp

