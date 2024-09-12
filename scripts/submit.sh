#!/bin/bash
source .env

EXERCISM_SLUG=$1
ALTER_EXERCISM_SLUG=$2
WORKING_DIR=$(pwd)/src/c/$EXERCISM_SLUG

cd $WORKING_DIR

if [[ -n "$ALTER_EXERCISM_SLUG" ]]; then
    exercism submit $ALTER_EXERCISM_SLUG.c $ALTER_EXERCISM_SLUG.h
    exit 0
fi

exercism submit $EXERCISM_SLUG.c $EXERCISM_SLUG.h
exit 0
