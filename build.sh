#!/bin/bash

build_main() {
    local CLEAN_FLAG=0

    while [[ $# -gt 0 ]]; do
        case $1 in
        --clean)
            CLEAN_FLAG=1
            shift
            break
            ;;
        esac
    done

    if [[ $CLEAN_FLAG -eq 1 ]]; then
        rm -rf build
    fi

    [ -d build ] | mkdir build

    cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B./build .
    if [ $? != 0 ]; then
        return $?
    fi

    cmake --build ./build -j4

    return $?
}

build_main "$@"
exit $?