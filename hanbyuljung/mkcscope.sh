#!/bin/sh
rm -rf cscope.files csope.files
find . \( -name '*.c' -o -name '*.ccp' -o -name '*.cc' -o -name '*.h' -o -name '*.S' \) -print > cscope.files
cscope -i cscope.files
