#! /bin/bash

ROOT=$(pwd)
echo $ROOT
declare -i fails; fails=0
# Find all directories containing Makefiles
find . -name "Makefile" -type f -print0 | while IFS= read -r -d '' makefile; do
    echo "Testing Makefile in $(dirname "$makefile")"

    # Navigate to the Makefile's directory
    cd "$(dirname "$makefile")" || exit 1

    # Run make
    if ! make; then
        echo "Error: Make failed in $(dirname "$makefile")"
        fails+=1
        echo $fails
    fi
    BINARY=$(make -s print-name)
    echo Bin: $BINARY


    # Clean after successful build
    make fclean || true

    # Return to the root directory
    cd "$ROOT" || exit 1
    echo
done

echo "Found $fails erros."
exit $fails
