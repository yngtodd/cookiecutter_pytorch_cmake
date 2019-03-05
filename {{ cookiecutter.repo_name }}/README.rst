==============================
{{ cookiecutter.project_name }}
==============================

{{ cookiecutter.project_short_description}}

Building From Source
--------------------

First make sure that you have `CMake`_ and an C++ compiler environment installed.

This project depends upon Libtorch, the C++ frontend of Pytorch. You can get the
precompiled Libtorch library on `Pytorch's main page`_. Once you have Libtorch,
let's set a convenience variable pointing to the base directory of the library:

.. code-block:: console

    export LIBTORCH=/path/to/libtorch

Then go to our source directory and build with the following:

.. code-block:: console

    mkdir build && cd build
    cmake -DCMAKE_PREFIX_PATH=$LIBTORCH ..
    make

Running Unit Tests
------------------

After building this project you may run its unit tests by using these commands:


.. code-block:: console

    make test  # To run all tests via CTest
    make catch # Run all tests directly, showing more details to you

License
-------

The MIT License

Copyright (c) 2010-2018 Google, Inc. http://angularjs.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

.. _CMake: http://www.cmake.org/
.. _Pytorch's main page: https://pytorch.org/
