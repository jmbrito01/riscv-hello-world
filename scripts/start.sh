#!/bin/bash

# This script is being called from .github/workflows/maketest.yml to install
# necessary software to build/run tests in CI.

make clean
make runm