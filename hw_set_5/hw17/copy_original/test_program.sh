#!/bin/bash

# This script runs your compiled binary version of test.cc, and compares its output
# against the pregenerated expected test output we have given you. 
# NOTE: the pregenerated output may not be the same as what we've given you,
# as described briefly in the README

./test > test.out
diff expected_test.out test.out > diff_output.txt
diff_ret=$?
if [[ $diff_ret -eq 0 ]]; then
    echo "Passed - Test program output matched expected output"
else
    echo "Failed - Test program output did not match expected output"
fi
