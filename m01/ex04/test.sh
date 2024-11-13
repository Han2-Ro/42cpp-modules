#! /bin/bash

function test() {
    echo "testing: " "$1 $2 $3"
    echo "$1" > src.txt
    sed "s/$2/$3/g" src.txt > dest.txt
    ./ex04 src.txt "$2" "$3"
    diff dest.txt src.txt.replace
    echo ""
}

test "akljglkjdjldkja" "a" "A"
test \
"111111
222222222
33333333" \
"22" \
"XX"

test \
"haystack: sdfsd
ha sdfj needle sdfasdf
dog sth c++ words needle ABC
this is a haystack
here is one needle
more words lorem ipsum need
eedl ABC" \
"needle" \
"XXXXXX"

#test \
#"" \
#"" \
#""
#
#test \
#"abcdefghijklmnopqrstuvwxyz" \
#"" \
#"sth"

test \
"abcdefghijklmnopqrstuvwxyz" \
"z" \
""

test "1" "1" "21"

test "00000000000000" "0" "0"
test "00000000000000" "0" "1"

test "yyy" "y" "yyy"

rm src.txt src.txt.replace dest.txt
