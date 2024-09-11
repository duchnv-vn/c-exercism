#!/bin/bash
source .env

EXERCISM_SLUG=$1
TRACK=c

exercism download \
    --track=$TRACK \
    --exercise=$EXERCISM_SLUG
