#! /bin/bash

WORKING_DIR=$(pwd)
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [[ "$WORKING_DIR" != "$SCRIPT_DIR" ]]; then
  echo "Please rerun this script from: $SCRIPT_DIR"
  exit 1
fi

PARENT_DIR="$(dirname "$SCRIPT_DIR")"

if ! [[ -f "$PARENT_DIR/wzip.c" ]]; then
    echo "Error: Could not find wzip.c in directory: $PARENT_DIR"
    exit 1 
fi

if [[ -x wzip ]]; then
    echo "Removing old wzip binary."
    rm wzip 
fi

if [[ -x wzip ]]; then
    echo "Error: Could not remove old wzip binary."
    exit 1 
fi

../test-lib/run_tests.sh $*
