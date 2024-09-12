#!/bin/bash
source .env

WORKSPACE=$(pwd)/src

exercism configure \
    --token=$EXERCISM_TOKEN \
    --workspace=$WORKSPACE
