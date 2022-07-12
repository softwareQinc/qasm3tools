import subprocess
import sys
import os
from setuptools import setup
from libs.pybind11.setup_helpers import Pybind11Extension

os.environ["MACOSX_DEPLOYMENT_TARGET"] = '10.15' # needed for std::filesystem
p = subprocess.Popen("cmake pyqasm3 && make -j8 antlr4_static",
                     shell=True,
                     stdout=subprocess.PIPE,
                     stderr=subprocess.STDOUT)

eigen_prefix = "Detecting Eigen3 - done (in "
eigen_path = None
qpp_prefix = "Found Quantum++ in "
qpp_path = None
print("Running cmake pyqasm3")
for line in p.stdout.read().decode('ascii', 'ignore').split('\n'):
    print(line)
    pos = line.find(eigen_prefix)
    if pos != -1:
        eigen_path = line[pos + len(eigen_prefix):-1]
    pos = line.find(qpp_prefix)
    if pos != -1:
        qpp_path = line[pos + len(qpp_prefix):]

if eigen_path is None:
    raise Exception('Eigen3 not found!')
elif qpp_path is None:
    raise Exception('Quantum++ not found!')
else:
    qpp_path = qpp_path[:-4] # remove '/qpp' suffix

ext_modules = [
    Pybind11Extension(
        "pyqasm3",
        ["pyqasm3/qasm3_wrapper.cpp"],
        extra_compile_args=["-Ilibs",
                            "-Iinclude",
                            "-iquoteantlr4cpp_runtime/runtime/src",
                            "-Iantlr4cpp_generated",
                            "-I" + eigen_path,
                            "-I" + qpp_path],
        extra_link_args=["-Lpyqasm3/dist", "-lantlr4-runtime"],
        cxx_std=17,
        include_pybind11=False,
    ),
]

setup(
    name='pyqasm3',
    version='0.1',
    description='Python 3 wrapper for qasm3tools',
    author='softwareQ',
    author_email='info@softwareq.ca',
    url='https://github.com/softwareQinc/qasm3tools',
    license='MIT',
    platforms=sys.platform,
    ext_modules=ext_modules)
