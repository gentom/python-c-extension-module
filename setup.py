
from distutils.core import setup, Extension

setup(name='python_c_extension', version='1.0', description='practice of cpython',
      ext_modules=[Extension('gcallib', ['./extensions/main.c', './extensions/calculation.c'])])
