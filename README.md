PYCV: a PLUMED 2 Module Enabling the Rapid Prototyping of Collective Variables in Python
==========

T. Giorgino

This repository contains the **PYCV** module of PLUMED. 

PYCV is a module for the PLUMED 2 library which enables users to define CVs and arbitrary functions in the Python language. CV implementations may thus be modified and tested independently of the main code, with essentially no "test latency". Of note, coordinates are processed as numpy arrays, making it convenient to leverage the vast set of linear algebra and numerical algorithms provided by numpy, scipy, and many other open-source modules. Furthermore, just-in-time compilation and reverse-mode automatic differentiation are easily accessible using Google's JAX library.

The module's documentation is in the [README.md](src/pycv/README.md) file contained in the module's directory.

Following PLUMED's [contribution philosophy](https://www.plumed.org/doc-v2.5/developer-doc/html/_how_to_contribute_to_plumed.html), this repository is a fork of the official PLUMED2 repository taken at release v2.5.2. The contributed code is entirely contAccained in the directories `src/pycv` and `regtest/pycv`. Minor modifications were made to the `configure` script to simplify installation.

Please report bugs & ideas via this repository's *Issues*. 
